/**
 * WEB222 – Assignment 04
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       Gyeongrok Oh
 *      Student ID: 119140226
 *      Date:       SUBMISSION_DATE (e.g., 2023-07-18)
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
// WEB222 – Assignment 04

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { artists, songs } = window;

// For debugging, display all of our data in the console. You can remove this later.
console.log({ artists, songs }, "App Data");

// Function to display the artist's links
function displayArtistLinks(artist) {
  const linksContainer = document.createElement("div");
  artist.links.forEach((link, index) => {
    const anchor = document.createElement("a");
    anchor.href = link.url;
    anchor.textContent = link.name;
    linksContainer.appendChild(anchor);

    // Add a comma after each link except for the last one
    if (index < artist.links.length - 1) {
      linksContainer.appendChild(document.createTextNode(", "));
    }
  });
  return linksContainer;
}

function createSongCard(song) {
  // Create a <div> to hold the card
  const card = document.createElement("div");

  // Add the .product-card class to the <div>
  card.classList.add("product-card");

  // Create a song image, use the .card-image class
  const songImg = document.createElement("img");
  songImg.src = song.imageUrl;
  songImg.classList.add("card-image");

  // Create elements for song title, year, and duration
  const titleElement = document.createElement("h2");
  titleElement.textContent = song.title;

  const yearElement = document.createElement("time");
  yearElement.textContent = `Year Recorded: ${song.year}`;

  const durationElement = document.createElement("span");
  const minutes = Math.floor(song.duration / 60);
  const seconds = song.duration % 60;
  durationElement.textContent = `Duration: ${minutes}:${seconds.toString().padStart(2, "0")}`;

  // Append the song elements to the card <div>
  card.appendChild(songImg);
  card.appendChild(titleElement);
  card.appendChild(yearElement);
  card.appendChild(durationElement);

  // Return the card's <div> element to the caller
  return card;
}

// Function to display the artist's songs
function displaySongs(artist) {
  const selectedArtistTitle = document.getElementById("selected-artist");

  // Clear previous data
  selectedArtistTitle.innerHTML = "";

  // Display the artist's name and links
  const artistNameLinks = document.createElement("h2");
  artistNameLinks.textContent = `${artist.name} (${displayArtistLinks(artist).textContent})`;
  selectedArtistTitle.appendChild(artistNameLinks);

  // Filter and display the artist's songs
  const filteredSongs = window.songs.filter((song) => !song.flagged && song.artistId === artist.id);

  // Get the container where song cards will be added
  const songsContainer = document.getElementById("songs-container");

  // Clear previous data
  songsContainer.innerHTML = "";

  // Create and append song cards for each song
  filteredSongs.forEach((song) => {
    const songCard = createSongCard(song);
    songsContainer.appendChild(songCard);
  });
}

// Function to create buttons for each artist
function createArtistButtons() {
  const menu = document.getElementById("menu");

  artists.forEach((artist) => {
    const button = document.createElement("button");
    button.textContent = artist.name;
    button.addEventListener("click", () => {
      displaySongs(artist);
    });
    menu.appendChild(button);
  });
}

// Event handler to run when the page is loaded
document.addEventListener("DOMContentLoaded", () => {
  // Create buttons for each artist in the menu
  createArtistButtons();

  // Display the first artist's songs by default
  displaySongs(artists[0]);
});

const artistLinksElement = document.getElementById("artistLinks");

artists.forEach((artist) => {
  const artistListItem = document.createElement("li");
  artistListItem.innerHTML = `<h2>${artist.name}</h2><ul>${getLinksHTML(artist.links)}</ul>`;
  artistLinksElement.appendChild(artistListItem);
});

function getLinksHTML(links) {
  return links
    .map((link) => `<li><a href="${link.url}" target="_blank">${link.name}</a></li>`)
    .join("");
}
