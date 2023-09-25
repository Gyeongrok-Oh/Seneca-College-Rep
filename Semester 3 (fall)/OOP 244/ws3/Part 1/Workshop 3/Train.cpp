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

		return (value > 0 && value < MAX_NO_OF_PASSENGERS);
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

	bool Train::validName(const char * name) const {
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
}