/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.cpp
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      Nov 23, 2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#include <iostream>
#include <fstream> 
#include <string>
#include "Perishable.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	Date temp;
	int count_linear = 0;

	Perishable::Perishable() : Item()
	{
	}

	Perishable::Perishable(const Perishable& perishable) : Item(perishable)
	{
		expDate = perishable.expDate;
		delete[] instruction;
		instruction = nullptr;
		*this = perishable;
	}

	Perishable& Perishable::operator=(const Perishable& other)
	{
		if (this != &other) {
			Item::operator=(other);
			expDate = other.expDate;
			delete[] instruction;
			instruction = nullptr;

			if (other.instruction) {
				ut.alocpy(instruction, other.instruction);
			}
		}

		return *this;
	}

	const Date& Perishable::expiry() const
	{
		return expDate;
	}

	int Perishable::readSku(std::istream& istr)
	{
		cout << "SKU: ";
		unitNum = ut.getint(10000, 39999, "", "");
		return unitNum;
	}

	ofstream& Perishable::save(ofstream& of) const
	{
		if (s) {
			Item::save(of);
			of << '\t';
			if (instruction && instruction[0]) {
				of << instruction;
			}


			of << '\t';
			Date temp;
			temp = expDate;
			temp.formatted(false);
			of << temp;
			temp.init();
		}


		return of;
	}

	ifstream& Perishable::load(ifstream& ifstr)
	{
		delete[] instruction; 
		instruction = nullptr;
		Item::load(ifstr);
		string temp{ "" };

		getline(ifstr, temp, '\t');

		if (temp != "") {
			ut.alocpy(instruction, temp.c_str());
		}
		else {
			instruction = nullptr;
		}

		ifstr >> expDate;

		ifstr.ignore();

		return ifstr;
	}

	ostream& Perishable::display(ostream& ostr) const
	{
		if (s) {
			if (linear()) {

				Item::display(ostr);

				if (instruction != nullptr && instruction[0] != 0) {
					ostr << '*';
				}
				else {
					ostr << ' ';
				}
				ostr << expDate;
			}
			else {
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";
				temp = expDate;
				temp.formatted(true);
				ostr << temp << endl;
				temp.init();
				if (instruction && instruction[0]) {
					ostr << "Handling Instructions: " << instruction << endl;
				}
			}
		}
		else {
			ostr << s;
		}


		return ostr;
	}

	std::istream& Perishable::read(std::istream& is)
	{

		Item::read(is);
		if (instruction != nullptr) {
			delete[] instruction;
			instruction = nullptr;
		}
		instruction = nullptr;
		cout << "Expiry date (YYMMDD): ";
		is >> expDate;
		is.ignore();
		cout << "Handling Instructions, ENTER to skip: ";
		string temp{ "" };
		if (is.peek() != '\n' && getline(is, temp, '\n')) {

			if (temp != "") {
				ut.alocpy(instruction, temp.c_str());
			}
		}


		if (!is.good()) {
			s = "Perishable console date entry failed!";
		}


		return is;

	}

	Perishable::operator bool() const {
		count_linear++;
		return count_linear > 1;
	}

	Perishable::~Perishable() {
		if (instruction != nullptr) {
			delete[] instruction;
			instruction = nullptr;
		}
		expDate.init();
	}

}
