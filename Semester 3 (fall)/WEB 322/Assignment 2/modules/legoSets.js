const setData = require("../data/setData");
const themeData = require("../data/themeData");

let sets = [];

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
    if (sets.length > 0) {
      resolve(sets);
    } else {
      reject("sets no available");
    }
  });
}

// Get a set by set number
function getSetByNum(setNum) {
  return new Promise((resolve, reject) => {
    const foundSet = sets.find(set => set.set_num === setNum);
    if (foundSet) {
      resolve(foundSet);
    } else {
      reject("getSetByNum is not found");
    }
  });
}

// Get sets by theme (case-insensitive and partial match)
function getSetsByTheme(theme) {
  return new Promise((resolve, reject) => {
    const filteredSets = sets.filter(set =>
      set.theme.toLowerCase().includes(theme.toLowerCase())
    );
    if (filteredSets.length > 0) {
      resolve(filteredSets);
    } else {
      reject("No sets found with the specified theme");
    }
  });
}

module.exports = { initialize, getAllSets, getSetByNum, getSetsByTheme };


const legoSets = require("./legoSets");

legoSets.initialize();

const setAll = legoSets.getAllSets();
const specificSet = legoSets.getSetByNum("001-1");
const setsByTheme = legoSets.getSetsByTheme("tech");

console.log(setAll);
console.log(specificSet);
console.log(setsByTheme);