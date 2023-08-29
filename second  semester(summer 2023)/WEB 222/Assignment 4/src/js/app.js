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

// Function to display the artist's songs
function displaySongs(artist) {
  const selectedArtistTitle = document.getElementById("selected-artist");
  const songsTableBody = document.getElementById("songs");

  // Clear previous data
  selectedArtistTitle.innerHTML = "";
  songsTableBody.innerHTML = "";

  // Display the artist's name and links
  const artistNameLinks = document.createElement("h2");
  artistNameLinks.textContent = `${artist.name} (${displayArtistLinks(artist).textContent})`;
  selectedArtistTitle.appendChild(artistNameLinks);

  // Filter and display the artist's songs
  const filteredSongs = window.songs.filter((song) => !song.flagged && song.artistId === artist.id);
  filteredSongs.forEach((song) => {
    // Create a new table row for each song
    const row = document.createElement("tr");

    // Add click event handler to log the song when the user clicks on the row
    row.addEventListener("click", () => {
      console.log(song);
    });

    // Create table data elements for song details
    const nameData = document.createElement("td");
    const yearData = document.createElement("td");
    const durationData = document.createElement("td");

    // Set the content for each table data element
    nameData.textContent = song.title;
    yearData.textContent = song.year;
    const durationInSeconds = song.duration;
    const minutes = Math.floor(durationInSeconds / 60);
    const seconds = durationInSeconds % 60;
    durationData.textContent = `${minutes}:${seconds.toString().padStart(2, "0")}`;

    // Append table data elements to the table row
    row.appendChild(nameData);
    row.appendChild(yearData);
    row.appendChild(durationData);

    // Append the table row to the table body
    songsTableBody.appendChild(row);
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

// 각 아티스트의 링크 정보를 ul li 형태로 반환
function getLinksHTML(links) {
  return links
    .map((link) => `<li><a href="${link.url}" target="_blank">${link.name}</a></li>`)
    .join("");
}
