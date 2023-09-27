/********************************************************************************

* WEB322 – Assignment 02

*

* I declare that this assignment is my own work in accordance with Seneca's

* Academic Integrity Policy:

*

* https://www.senecacollege.ca/about/policies/academic-integrity-policy.html

*

* Name: Gyeongrok Oh   Student ID: 119140226   Date: ______________

*

********************************************************************************/

const express = require('express');
const legoData = require('./modules/legoSets');

const app = express();
const port = process.env.PORT || 3000; // Set the port for your server

// Middleware to wait for legoData initialization before starting the server
app.use(async (req, res, next) => {
  try {
    await legoData.initialize();
    next(); // Proceed to the next middleware/route
  } catch (error) {
    res.status(500).send('Error initializing Lego data');
  }
});

// Route: GET "/"
app.get('/', (req, res) => {
  res.send('Assignment 2: Gyeongrok oh - 119140226');
});

// Route: GET "/lego/sets"
app.get('/lego/sets', async (req, res) => {
  try {
    const allSets = await legoData.getAllSets();
    res.json(allSets);
  } catch (error) {
    res.status(500).send('Error retrieving Lego sets');
  }
});

// Route: GET "/lego/sets/num-demo"
app.get('/lego/sets/num-demo', async (req, res) => {
  const setNum = '001-1'; // Replace with a known set number from your data
  try {
    const specificSet = await legoData.getSetByNum(setNum);
    res.json(specificSet);
  } catch (error) {
    res.status(500).send('Error retrieving Lego set by number');
  }
});

// Route: GET "/lego/sets/theme-demo"
app.get('/lego/sets/theme-demo', async (req, res) => {
  const theme = 'technic'; // Replace with a known theme from your data (part of theme name in lowercase)
  try {
    const setsByTheme = await legoData.getSetsByTheme(theme);
    res.json(setsByTheme);
  } catch (error) {
    res.status(500).send('Error retrieving Lego sets by theme');
  }
});

// Start the server
app.use(async (req, res, next) => {
    try {
      console.log('Initializing Lego data middleware...'); // Add this line
      await legoData.initialize();
      console.log('Lego data initialized successfully.'); // Add this line
      next(); // Proceed to the next middleware/route
    } catch (error) {
      console.error('Error initializing Lego data:', error); // Add this line to log the error
      res.status(500).send('Error initializing Lego data');
    }
  });
  
