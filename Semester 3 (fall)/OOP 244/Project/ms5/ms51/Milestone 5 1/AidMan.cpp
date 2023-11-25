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
		int year{ 0 }, month{ 0 }, day{ 0 };
		ut.getSystemDate(&year, &month, &day);
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
			ut.alocpy(m_fileName, fileName);
		}
		else {
			m_fileName = nullptr;
		}
		numOfArr = 0;
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

	int AidMan::list(const char* str) {
		int noProductsPrinted = 0;
		int indexesPrinted[sdds_max_num_items];

		if (str == nullptr) {
			if (numOfArr > 0) {
				cout << " ROW |SKU| Description| Have| Need |Price| Expiry" << endl;
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

				for (int i = 0; i < numOfArr; i++) {
					cout << " ";
					cout.fill(' ');
					cout.width(3);
					cout << i + 1 << " | ";
					items[i]->linear(true);
					items[i]->display(cout);
					cout << endl;
					indexesPrinted[i] = i;
				}

				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
				noProductsPrinted = numOfArr;
			}
			else {
				cout << "The list is empty!" << endl;
			}
		}
		else {
			int i2 = 0;
			for (int i = 0; i < numOfArr; i++) {
				if (strStr(*(items[i]), str) != NULL) {
					indexesPrinted[i2] = i;
					i2 += 1;
					noProductsPrinted += 1;
				}
			}

			if (noProductsPrinted > 0) {
				cout << " ROW |SKU| Description| Have| Need |Price| Expiry" << endl;
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

				for (int i = 0; i < noProductsPrinted; i++) {
					cout << " ";
					cout.fill(' ');
					cout.width(3);
					cout << i + 1 << " | ";
					items[indexesPrinted[i]]->linear(true);
					items[indexesPrinted[i]]->display(cout);
					cout << endl;
				}

				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			}
			else {
				cout << "The list is empty!" << endl;
			}
		}

		if (noProductsPrinted > 0) {
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";

			if (cin.peek() == '\n') {
				cin.get();
				cout << endl;
			}
			else {
				int option = ut.getint(noProductsPrinted, 1, "","");
				items[indexesPrinted[option - 1]]->linear(false);
				items[indexesPrinted[option - 1]]->display(cout);
				cout << endl << endl;
			}
		}

		return noProductsPrinted;
	}

}
