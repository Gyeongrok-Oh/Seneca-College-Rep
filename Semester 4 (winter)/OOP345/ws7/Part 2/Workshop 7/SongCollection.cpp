//Name : Gyeongrok Oh
//Seneca Email : goh3@myseneca.ca
//Student Id : 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
#include "SongCollection.h"

using namespace std;

namespace seneca {

    static size_t totalLength;

    void SongCollection::trim(string& token) {

        size_t start = token.find_first_not_of(' ');
        if (start != string::npos) {
            token = token.substr(start);
        }

        size_t end = token.find_last_not_of(' ');
        if (end != string::npos) {
            token = token.substr(0, end + 1);
        }
    }

    SongCollection::SongCollection(string fileName) {
        ifstream file(fileName);
        if (!file) {
            throw "Invalid file name: " + fileName;
        }

        while (file) {
            Song song;
            string line;
            getline(file, line);

            if (file) {
                song.m_title = line.substr(0, 25);
                trim(song.m_title);

                song.m_artist = line.substr(25, 25);
                trim(song.m_artist);

                song.m_album = line.substr(50, 25);
                trim(song.m_album);

                try {
                    song.m_year = stoi(line.substr(75, 5));
                }
                catch (const exception&) {
                    song.m_year = 0;
                }

                try {
                    song.m_length = stoi(line.substr(80, 5));
                }
                catch (const exception&) {
                    song.m_length = 0;
                }

                try {
                    song.m_price = stod(line.substr(85, 5));
                }
                catch (const exception&) {
                    song.m_price = 0.0;
                }

                m_songs.push_back(song);
            }
        }

        file.close();
    }

    void SongCollection::display(ostream& out) const {
        size_t totalLength{ 0 };

        for_each(m_songs.begin(), m_songs.end(),
            [&out, &totalLength](const Song& theSong) {
                out << theSong << endl;
                totalLength += theSong.m_length;
            });

        for (int i = 0; i < 88; ++i) {
            out << "-";
        }
        out << endl;
        out.fill(' ');
        out << "| ";
        out.width(77);
        out << "Total Listening Time: ";
        out << totalLength / 3600;
        out << ":";
        out.width(2);
        out << (totalLength % 3600) / 60;
        out << ":";
        out.width(2);
        out << totalLength % 60;
        out << " |";
        out << endl;

    }


    ostream& operator<<(ostream& out, const Song& theSong)
    {
        totalLength += theSong.m_length;
        out << "| "; out.width(20);
        out << left << theSong.m_title;
        out << " | ";
        out.width(15);
        out << theSong.m_artist;
        out << " | ";
        out.width(20);
        out << theSong.m_album;
        out << " | ";
        out.width(6);
        (theSong.m_year != 0) ? out << right << theSong.m_year << left : out << "";
        out << " | ";
        out.width(0);
        out << theSong.m_length / 60;
        out << ":";
        out.width(2);
        out.fill('0');
        out << right << theSong.m_length - (theSong.m_length / 60) * 60;
        out.fill(' ');
        out << left;
        out << " | ";
        out.setf(ios::fixed);
        out.precision(2);
        out << theSong.m_price;
        out << " |" << right;
        
        return out;
    }

    void SongCollection::sort(string field) {
        if (field == "title") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_title < b.m_title;
                });
        }
        else if (field == "album") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_album < b.m_album;
                });
        }
        else if (field == "length") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_length < b.m_length;
                });
        }
        else {

            throw "Invalid field for sorting: " + field;
        }
    }
    
    void SongCollection::cleanAlbum() {
        for_each(m_songs.begin(), m_songs.end(), [](Song& song) {
            song.m_album = song.m_album == "[None]" ? "" : song.m_album;
            });
    }
    
    bool SongCollection::inCollection(const string& artistName) const {
        return any_of(m_songs.begin(), m_songs.end(), [&](const Song& song) {
            return song.m_artist == artistName;
            });
    }

    list<Song> SongCollection::getSongsForArtist(const string& artistName) const {
        list<Song> songsForArtist;
        copy_if(m_songs.begin(), m_songs.end(), back_inserter(songsForArtist), [&](const Song& song) {
            return song.m_artist == artistName;
            });
        return songsForArtist;
    }

}