#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <iomanip> 
#include<cstdio> 
#include<cstring> 
#include"Train.h" 

using namespace std;

namespace sdds {
	void Train::initialize() {
		tName = nullptr;
		noOfpeople = -1;
		depTime = -1;
	}

	bool Train::validTime(int value) const {
		unsigned int digit = value % 100;
		return (value >= MIN_TIME && value <= MAX_TIME) && (digit >= 0 && digit <= 59);
	}

	bool Train::validNoOfPassengers(int value) const {

		return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
	}

	void Train::set(const char* name) {
		delete[] tName;
		tName = nullptr;
		if (validName(name)) {
			tName = new char[strlen(name) + 1];

			strcpy(tName, name);
		}

	}

	void Train::set(int noOfPassengers, int departure) {
		if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
			noOfpeople = noOfPassengers;
			depTime = departure;
		}
		else {
			noOfpeople = -1;
			depTime = -1;
		}
	}

	void Train::set(const char* name, int noOfPassengers, int departure) {
		// Set the name first
		set(name);

		// Then set the number of passengers and departure time
		set(noOfPassengers, departure);
	}

	bool Train::validName(const char* name) const {
		return (name != nullptr && name[0] != '\0');
	}

	void Train::finalize() {
		delete[] tName;
		tName = nullptr;
	}

	bool Train::isInvalid()const {
		return validTime(depTime) && validNoOfPassengers(noOfpeople) && validName(tName) ? false : true;
	}

	int Train::noOfPassengers() const {
		return noOfpeople;
	}

	const char* Train::getName() const {
		return tName;
	}

	int Train::getDepartureTime() const {
		return depTime;
	}

	void Train::display() const {
		if (isInvalid()) {
			cout << "Train in an invalid State!" << endl;
		}
		else {
			cout << "NAME OF THE TRAIN:    " << tName << endl;
			cout << "NUMBER OF PASSENGERS: " << noOfpeople << endl;
			cout << "DEPARTURE TIME:       " << depTime << endl;
		}
	}

	// Part 2

	bool Train::load(int& notBoarded) {
		cout << "Enter number of passengers boarding:" << endl;
		cout << "> ";
		unsigned int passengers{};
		bool boarded = false;
		cin >> passengers;
		this->noOfpeople += passengers;
		if (validNoOfPassengers(noOfpeople)) {
			boarded = true;
			notBoarded = 0;
		}
		else {
			notBoarded = noOfpeople - MAX_NO_OF_PASSENGERS;
			noOfpeople = MAX_NO_OF_PASSENGERS;
		}

		return boarded;
	}

	bool Train::updateDepartureTime() {
		cout << "Enter new departure time:" << endl;
		cout << "> ";
		unsigned int newDepartureTime{};
		bool is_time = false;
		cin >> newDepartureTime;

		if (validTime(newDepartureTime)) {
			depTime = newDepartureTime;
			is_time = true;
		}
		else {
			depTime = -1;
			
		}

		return is_time;
	}

	bool Train::transfer(const Train& from) {
		bool transfer = false;

		if (!this->isInvalid() && !from.isInvalid()) {
			// Calculate the combined length of the names
			size_t combinedLength = strlen(this->tName) + strlen(", ") + strlen(from.tName) + 1;

			// Dynamically allocate memory for the new name
			char* newTName = new char[combinedLength];

			// Check if memory allocation was successful
			if (newTName != nullptr) {
				// Copy the current train's name to the new buffer
				strcpy(newTName, this->tName);

				// Concatenate the names using strcat
				strcat(newTName, ", ");
				strcat(newTName, from.tName);

				// Free the old name and update the pointer
				delete[] this->tName;
				this->tName = newTName;

				this->noOfpeople += from.noOfpeople;
				if (validNoOfPassengers(this->noOfpeople)) {
					transfer = true;
				}
				else {
					cout << "Train is full; " << this->noOfpeople - MAX_NO_OF_PASSENGERS << " passengers of " << from.tName << " could not be boarded!" << endl;
					this->noOfpeople = MAX_NO_OF_PASSENGERS;
					transfer = true;
				}
			}
			else {
				cout << "Memory allocation failed for the new name." << endl;
			}
		}

		return transfer;
	}



}