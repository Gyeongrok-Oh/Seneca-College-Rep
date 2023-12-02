/***********************************************************************
// Final project Milestone 5
// Module: AidMan
// File: AidMan.cpp
// Version 1.0
// Author  Gyeongrok oh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Gyeongrok oh          Date Nov-26-2023            Reason
***********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "AidMan.h"

using namespace std;

namespace sdds {
	unsigned int AidMan::menu() const
	{
		cout << "Aid Management System" << endl;
		int year{ 0 }, month{ 0 }, day{ 0 };
		ut.testMode(true);
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
		cout << endl << "---------------------------------" << endl;
		unsigned int userChoice{ m_mainMenu.run() };

		return userChoice;
	}
	AidMan::AidMan(const char* fileName)
		:m_mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database")
		//"List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSortShip Items New/Open Aid Database"
	{
		for (int i = 0; i < sdds_max_num_items; i++) {
			items[i] = nullptr;
		}
		if (fileName != nullptr) {
			delete[] m_fileName;
			m_fileName = nullptr;
			ut.alocpy(m_fileName, fileName);
		}
		else {
			m_fileName = nullptr;
		}
		numItem = 0;

	}
	void AidMan::run() {
		int choice{ -1 };

		while (choice != 0) {
			choice = AidMan::menu();

			switch (choice) {
			case 0:
				std::cout << "Exiting Program!\n";
				break;
			case 1:
				if (m_fileName == nullptr) {
					cout << "\n****New/Open Aid Database****\n";
					load();
				}
				else {
					std::cout << "\n****List Items****\n";
					list();
				}
				break;
			case 2:
				std::cout << "\n****Add Item****\n\n";
				break;
			case 3:
				std::cout << "\n****Remove Item****\n\n";
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

	void AidMan::save()
	{
		if (m_fileName != nullptr) {
			ofstream fout(m_fileName);
			for (int i = 0; i < numItem; i++) {
				items[i]->save(fout);
			}
			fout.close();
		}
	}

	void AidMan::deallocate()
	{
		for (int i = 0; i < numItem; i++) {
			delete items[i];
		}
		numItem = 0;
	}

	bool AidMan::load()
	{
		save();
		deallocate();
		cout << "Enter file name: ";
		char tempName[sdds_max_num_items] = "\0";
		cin.getline(tempName, sdds_max_num_items, '\n');
		int i = 0;
		while (cin.peek() != '\n') {
			tempName[i] = cin.get();
			i += 1;
		};
		cin.ignore();
		ut.alocpy(m_fileName, tempName);
		int noOfRecords = 0;
		ifstream f(m_fileName);
		if (!f.is_open()) {
			cout << "Failed to open " << m_fileName << " for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;

			int userChoice;
			std::cout << "> ";
			std::cin >> userChoice;

			if (userChoice == 1) {
				std::ofstream newFile(m_fileName);
				newFile.close();
			}

		}
		else {
			while (!f.eof()) {
				char c = f.peek();
				int x = c - '0';
				if (x >= 1 && x <= 3) {
					items[numItem] = new Perishable;
				}
				else if (x >= 4 && x <= 9) {
					items[numItem] = new Item;
				}
				else {
					f.setstate(ios::failbit);
				}

				if (items[numItem]) {
					items[numItem]->load(f);
					noOfRecords += 1;
					numItem += 1;
				}
				else {
					delete items[numItem];
				}
			}
		}
		cout << noOfRecords << " records loaded!" << endl << endl;

		bool value{ false };
		return noOfRecords > 0 ? true : value;
	}

	int AidMan::list(const char* str) {
		int tempIndex[sdds_max_num_items];
		for (int i = 0; i < sdds_max_num_items; i++) {
			tempIndex[i] = -1;
		}

		if (str == nullptr) {
			if (numItem > 0) {
				cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

				for (int i = 0; i < numItem; i++) {
					cout << " ";
					cout.fill(' ');
					cout.width(3);
					cout << i + 1 << " | ";
					items[i]->linear(true);
					items[i]->display(cout);
					cout << endl;
					tempIndex[i] = i;
				}

				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			}
			else {
				cout << "The list is empty!" << endl;
			}
		}


		cout << "Enter row number to display details or <ENTER> to continue:" << endl;
		cout << "> ";
		cin.get();
		if (cin.peek() == '\n') {
			cin.ignore();
			cout << endl;
		}
		else {
			int option = ut.getint(1, numItem, "", "");
			items[tempIndex[option - 1]]->linear(false);
			items[tempIndex[option - 1]]->display(cout);
			cout << endl << endl;
		}

		return numItem;
	}

	AidMan::~AidMan()
	{
		deallocate();
	}


}