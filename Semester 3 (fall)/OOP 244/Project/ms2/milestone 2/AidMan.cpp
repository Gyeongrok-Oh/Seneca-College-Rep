/***********************************************************************
// Final project Milestone 2
// Module: AidMan
// File: AidMan.cpp
// Version 1.0
// Author  Gyeongrok oh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Gyeongrok oh          Date Nov-8-2023            Reason
***********************************************************************/
#include <iostream>
#include "AidMan.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	unsigned int AidMan::menu() const
	{
		cout << "Aid Management System" << endl;
		int year{0}, month{0}, day{0};
		ut.getSystemDate(&year,&month,&day);
		cout << "Date: " << year << "/";
		cout.fill('0');
		cout.width(2);
		cout << month << "/";
		cout.fill('0');
		cout.width(2);
	    cout << day << endl;
		cout << "Data file: ";
		if (m_fileName != nullptr) {
			cout << m_fileName;
		}
		else {
			cerr << "No file";
		}
		cout << endl << endl;
		unsigned int userChoice{ m_mainMenu.run() };
		
		return userChoice;
	}
	AidMan::AidMan(const char* fileName)
		:m_mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database")
		//"List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSortShip Items New/Open Aid Database"
	{
		if (fileName != nullptr) {
			delete[] m_fileName;
			m_fileName = nullptr;
			m_fileName = new char[strLen(fileName) + 1];
			strCpy(m_fileName, fileName);
		}
		else {
			m_fileName = nullptr;
		}
	}
	void AidMan::run() {
		int choice{ -1 };

		while (choice != 0) {
			choice = AidMan::menu(); // Display the menu and get user entry


			// Execute the task based on the user's selection
			switch (choice) {
			case 0:
				std::cout << "Exiting Program!\n";
				break;
			case 1:
				std::cout << "\n****List Items****\n\n"; // Task for option 1
				break;
			case 2:
				std::cout << "\n****Add Item****\n\n"; // Task for option 2
				break;
			case 3:
				std::cout << "\n****Remove Item****\n\n"; // Task for option 3
				break;
			case 4:
				cout << "\n****Update Quantity****\n\n";
				break;
			case 5:
				cout << "\n****Sort****\n\n";
				break;
			case 6:
				cout << "\n****Ship Items****\n\n";
				break;
			case 7:
				cout << "\n****New/Open Aid Database****\n\n";
				break;
			default:
				std::cout << "Invalid option selected.\n";
				break;
			}
		}
		delete[] m_fileName;
	}

}

