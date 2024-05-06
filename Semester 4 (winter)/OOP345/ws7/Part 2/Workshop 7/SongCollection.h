//Name : Gyeongrok Oh
//Seneca Email : goh3@myseneca.ca
//Student Id : 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm> 
#include <list>

namespace seneca {

	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		int m_year;
		size_t m_length;
		friend std::ostream& operator<<(std::ostream& out, const Song& theSong);
	};

	class SongCollection {
		std::vector<seneca::Song> m_songs;
		void trim(std::string& str);
	public:
		SongCollection(std::string file);
		void display(std::ostream& out) const;
		void sort(std::string field);
		void cleanAlbum();
		bool inCollection(const std::string& artistName) const;
		std::list<Song> getSongsForArtist(const std::string& artistName) const;
	};
}
#endif
