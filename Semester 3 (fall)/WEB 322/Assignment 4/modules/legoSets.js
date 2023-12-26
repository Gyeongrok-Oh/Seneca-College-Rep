require('dotenv').config();
const Sequelize = require('sequelize');

const setData = require("../data/setData");
const themeData = require("../data/themeData");
let sets = [];

//////////////// Set up sequelize to point to our postgres database//////
const sequelize = new Sequelize(process.env.DB_DATABASE, process.env.DB_USER, process.env.DB_PASSWORD, {
  host: process.env.DB_HOST,
  dialect: 'postgres',
  port: 5432,
  dialectOptions: {
    ssl: { rejectUnauthorized: false },
  },
  query: { raw: true },
});


const Theme = sequelize.define(
  'Theme', 
  {
    id: {
      type: Sequelize.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    name: {
      type: Sequelize.STRING, 
    },
  }, {
    createdAt: false, 
    updatedAt: false, 
  });


const Set = sequelize.define(
  'Set', 
  {
    set_num: {
      type: Sequelize.STRING,
      primaryKey: true,
    },
    name: {
      type: Sequelize.STRING,
    },
    year: {
      type: Sequelize.INTEGER,
    },
    theme_id: {
      type: Sequelize.INTEGER,
    },
    num_parts: {
      type: Sequelize.INTEGER,
    },  
    img_url: {
      type: Sequelize.STRING,
    },
  }, {
    createdAt: false, 
    updatedAt: false, 
  });


Set.belongsTo(Theme, { foreignKey:'theme_id'});


// Initialize the sets array with theme information
function initialize() {
  return new Promise((resolve, reject) => {
    sets = setData.map(set => {
      const themeInfo = themeData.find(theme => theme.id === set.theme_id);
      return {
        ...set,
        theme: themeInfo ? themeInfo.name : "Unknown"
      };
    });
    resolve(); // Resolving with no data once the operation is complete
  });
}

// Return all sets
function getAllSets() {
  return new Promise((resolve, reject) => {
    Set.findAll({ include: [Theme],raw : true ,
      nest : true })
      .then((sets) => {
        resolve(sets);
      })
      .catch((error) => {
        reject(error);
      });
  });
}



async function getSetByNum(setNum) {
  try {
    const foundSet = await Set.findOne({
      where: { set_num: setNum },
      include: [Theme],
    });

    if (foundSet) {
      return foundSet;
    } else {
      throw new Error("Unable to find requested set");
    }
  } catch (error) {
    throw new Error("Error while fetching set: " + error.message);
  }
}




async function getSetsByTheme(theme) {
  try {
    const sets = await Set.findAll({
      include: [Theme],
      where: {
        '$Theme.name$': {
          [Sequelize.Op.iLike]: `%${theme}%`,
        },
      },
    });

    if (sets.length > 0) {
      return sets;
    } else {
      throw new Error("Unable to find requested sets");
    }
  } catch (error) {
    throw new Error("Error while fetching sets: " + error.message);
  }
}


function addSet(setData) {
  return new Promise(async (resolve, reject) => {
    try {
      const newSet = await Set.create(setData);
      resolve(); // Resolve without data upon successful creation
    } catch (error) {
      reject(`Error adding set: ${error.errors[0].message}`);
    }
  });
}

function getAllThemes() {
  return new Promise(async (resolve, reject) => {
    try {
      const themes = await Theme.findAll();
      resolve(themes);
    } catch (error) {
      reject(`Error fetching themes: ${error.message}`);
    }
  });
}

// Function to edit an existing set
function editSet(set_num, setData) {
  return new Promise(async (resolve, reject) => {
    try {
      // Find the set with the specified set_num
      const existingSet = await Set.findOne({ where: { set_num } });

      // If the set is found, update its properties with the new data
      if (existingSet) {
        await existingSet.update(setData);
        resolve(); // Resolve without data upon successful update
      } else {
        // Reject with an error message if the set is not found
        reject(`Set with set_num ${set_num} not found`);
      }
    } catch (error) {
      // Reject with an error message if there's any issue during the update
      reject(`Error editing set: ${error.errors[0].message}`);
    }
  });
}

function deleteSet(setNum) {
  return new Promise(async (resolve, reject) => {
    try {
      const deletedSet = await Set.destroy({
        where: { set_num: setNum },
      });

      if (deletedSet > 0) {
        resolve(); // Resolve without data upon successful deletion
      } else {
        throw new Error("Unable to find and delete the requested set");
      }
    } catch (error) {
      reject(`Error deleting set: ${error.message}`);
    }
  });
}

sequelize
  .sync()
  .then( async () => {
    try{
      await Theme.bulkCreate(themeData);
      await Set.bulkCreate(setData); 
      console.log("-----");
      console.log("data inserted successfully");
    }catch(err){
      console.log("-----");
      console.log(err.message);

      // NOTE: If you receive the error:

      // insert or update on table "Sets" violates foreign key constraint "Sets_theme_id_fkey"

      // it is because you have a "set" in your collection that has a "theme_id" that does not exist in the "themeData".   

      // To fix this, use PgAdmin to delete the newly created "Themes" and "Sets" tables, fix the error in your .json files and re-run this code
    }

    process.exit();
  })
  .catch((err) => {
    console.log('Unable to connect to the database:', err);
  });
  
module.exports = { initialize, getAllSets, getSetByNum, getSetsByTheme, addSet, getAllThemes, editSet, deleteSet };


// Code Snippet to insert existing data from Set / Themes

// sequelize
//   .sync()
//   .then( async () => {
//     try{
//       await Theme.bulkCreate(themeData);
//       await Set.bulkCreate(setData); 
//       console.log("-----");
//       console.log("data inserted successfully");
//     }catch(err){
//       console.log("-----");
//       console.log(err.message);

//       // NOTE: If you receive the error:

//       // insert or update on table "Sets" violates foreign key constraint "Sets_theme_id_fkey"

//       // it is because you have a "set" in your collection that has a "theme_id" that does not exist in the "themeData".   

//       // To fix this, use PgAdmin to delete the newly created "Themes" and "Sets" tables, fix the error in your .json files and re-run this code
//     }

//     process.exit();
//   })
//   .catch((err) => {
//     console.log('Unable to connect to the database:', err);
//   });