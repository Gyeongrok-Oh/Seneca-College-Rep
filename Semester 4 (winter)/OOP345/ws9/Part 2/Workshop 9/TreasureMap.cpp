//Name : Gyeongrok Oh
//Seneca Email : goh3@myseneca.ca
//Student Id : 119140226
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <fstream>
#include <string>
#include <functional> // added
#include <future> // added
#include <thread> // added
#include <vector> // added
#include "TreasureMap.h"

namespace seneca {


    size_t digForTreasure(const std::string& str, char mark) {
        size_t cnt = 0;
        for (auto& x : str) {
            if (x == mark) {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename) {
        std::fstream fin(filename);
        if (fin) {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin) {
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap() {
        delete[] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const {
        if (map) {
            for (size_t i = 0; i < rows; ++i) {
                os << map[i] << std::endl;
            }
        }
        else
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename) {
        // Binary write
        if (map) {
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
            std::ofstream file(filename, std::ios::out | std::ios::binary); 
            if (file) { 
                file.write(reinterpret_cast<char*>(&rows), sizeof(rows)); 
                file.write(reinterpret_cast<char*>(&colSize), sizeof(colSize)); 
                for (std::size_t i = 0; i < rows; i++) { 
                    file.write(&(map[i][0]), map[i].size()); 
                } 
            }
            // END TODO
        }
        else {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename) {
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.
        std::ifstream file(filename, std::ios::in | std::ios::binary); 
        if (file) {
            file.read(reinterpret_cast<char*>(&rows), sizeof(rows)); 
            file.read(reinterpret_cast<char*>(&colSize), sizeof(colSize)); 
            map = new std::string[rows]; 
            for (std::size_t i = 0; i < rows; i++) {
                map[i].resize(colSize);
                file.read(reinterpret_cast<char*>(&(map[i][0])), colSize);
            }
        }
        // END TODO
    }

    void TreasureMap::clear() {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark) {
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        static const size_t numThreads{ 4 };

        size_t partitionSize = rows / numThreads;


        std::vector<std::thread> threads;


        std::vector<std::future<size_t>> futures;

        for (size_t i = 0; i < numThreads; ++i) {
            size_t start = i * partitionSize;
            size_t end = (i == numThreads - 1) ? rows : (i + 1) * partitionSize;

            std::string concatenatedString;
            for (size_t j = start; j < end; ++j) {
                concatenatedString += map[j];
            }

            std::packaged_task<size_t(const std::string&)> task(std::bind(&digForTreasure, std::placeholders::_1, mark));

            futures.push_back(task.get_future());


            threads.emplace_back(std::move(task), concatenatedString);
        }


        for (auto& thread : threads) {
            thread.join();
        }

        for (auto& future : futures) {
            count += future.get();
        }

        // -----------------------------------------------------------------------------
        //for (size_t i = 0; i < rows; ++i) {
        //    count += digForTreasure(map[i], mark);
        //}

        return count;
    }
}