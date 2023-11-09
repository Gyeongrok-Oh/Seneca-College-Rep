/***********************************************************************
// Final project Milestone 2
// Module: Menu
// File: Menu.cpp
// Version 1.0
// Author  Gyeongrok oh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Gyeongrok oh          Date Nov-8-2023            Reason
***********************************************************************/
#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	Menu::Menu(const char* oprions)
	{
		if (oprions != nullptr && countOption(oprions) < 15) {
			delete[] menuCont;
			menuCont = nullptr;
			menuCont = new char[strLen(oprions) + 1];
			strCpy(menuCont, oprions);
		}
		else {
			menuCont = nullptr;
		}
	}

	unsigned int Menu::countOption(const char* options) const {
		unsigned int count{ 0 };

		const char* temp = options; // Create a local non-const pointer to traverse the string

		while (*temp != '\0') {
			if (*temp == '\t') {
				count++;
			}
			temp++;
		}
		return count + 1;
	}


	Menu::~Menu()
	{
		delete[] menuCont;
	}

	unsigned int Menu::run() const
	{
		int value{ 0 };
		if (menuCont == nullptr) {
			cerr << "Invalid Menu!";
			while (cin.get() != '\n'){}
			cin.clear();
		}
		else {
			int i = 0, j = 1;
			cout << j << "- ";
			while (menuCont[i] != '\0') {
				if (menuCont[i] != '\t') {
					cout << menuCont[i];
				}
				else {
					cout << endl;
					j++;
					cout << j << "- ";
				}
				i++;
			}
			cout << endl << "---------------------------------" << endl << "0- Exit" << endl << "> ";

			unsigned int maxOption{ countOption(menuCont) };

			value = ut.getint(0, maxOption, "\0", NULL);
		}


		return value;
	}

}
