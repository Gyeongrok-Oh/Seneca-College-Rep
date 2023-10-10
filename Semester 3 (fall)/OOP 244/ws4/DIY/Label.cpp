#include <iostream>
#include <iomanip> // For setw() and setfill()
#include "Label.h"
#include "cstring"

using namespace std;

namespace sdds {

	bool is_newline{};

	Label::Label() {
		cont = nullptr;
		strcpy(frame, "+-+|+-+|");
	}

	Label::Label(const char* frameArg) {

		cont = nullptr;
		strcpy(frame, frameArg);
	}

	Label::Label(const char* frameArg, const char* content) {

		cont = nullptr;
		strcpy(frame, frameArg);

		unsigned int lenCont = strlen(content) + 1;

		if (lenCont <= 71) {
			cont = new char[lenCont]; // Use [] for array allocation
			strcpy(cont, content);
		}
	}


	Label::~Label() {

		delete[] cont;
		cont = nullptr;
	}

	istream& Label::readLabel() {

		char content[71]; // Buffer to hold label content

		is_newline = true;

		cout << "> ";
		cin.getline(content, 71); // Read label content (up to 70 characters)

		// Release previous content if it exists
		delete[] cont;
		cont = nullptr;

		// Copy new content if it's within the limit
		unsigned int lenCont = strlen(content);

		if (lenCont <= 70) {
			cont = new char[lenCont + 1];
			strcpy(cont, content);
		}

		return cin;
	}

	std::ostream& Label::printLabel() const {
		
		
		

		// Print the label content and sides
		if (cont) {
			int contWidth = strlen(cont) + 3;
			
			cout << frame[0] << setw(contWidth) << setfill(frame[1]) << frame[2] << endl;
			cout << frame[7] << setw(contWidth) << setfill(' ') << frame[3] << endl;
			cout << frame[7] << ' ' << cont << ' ' << frame[3] << endl;
			cout << frame[7] << setw(contWidth) << setfill(' ') << frame[3] << endl;
			cout << frame[6] << setw(contWidth) << setfill(frame[5]) << frame[4];
		}
		if (is_newline) {
			cout << endl;
		}
		return cout;
	}

	Label& Label::text(const char* content) {
		// Release previous content if it exists
		delete[] cont;
		cont = nullptr;

		// Copy new content if it's within the limit
		unsigned int lenCont = strlen(content);

		if (lenCont <= 70) {
			cont = new char[lenCont + 1];
			strcpy(cont, content);
		}
		
		is_newline = false;

		return *this; // Return a reference to the current object
	}

}