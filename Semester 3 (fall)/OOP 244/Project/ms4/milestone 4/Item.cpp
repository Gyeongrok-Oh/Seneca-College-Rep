/* Citation and Sources...
Final Project Milestone 1
Module: Item
Filename: Item.cpp
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      Nov 18, 2023
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
#include "Item.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	bool Item::linear() const
	{
		return m_flag;
	}
	Item::Item() : m_price(0.0), m_quantity(0), m_neededQuantity(0), m_description(nullptr), m_flag(false) {}

	Item::Item(const Item& item)
	{
		*this = item;
	}

	Item& Item::operator=(const Item& item)
	{
		if (this != &item) {
			m_price = item.m_price;
			m_quantity = item.m_quantity;
			m_neededQuantity = item.m_neededQuantity;
			unitNum = item.unitNum;
			ut.alocpy(m_description, item.m_description);
		}

		return *this;
	}

	int Item::qtyNeeded() const
	{
		return m_neededQuantity;
	}

	int Item::qty() const
	{
		return m_quantity;
	}

	Item::operator double() const
	{
		return m_price;
	}

	Item::operator bool() const
	{
		return s.operator bool();
	}

	int Item::operator-=(int value)
	{
		m_quantity -= value;
		return m_quantity;
	}

	int Item::operator+=(int value)
	{
		m_quantity += value;
		return m_quantity;
	}

	void Item::linear(bool isLinear)
	{
		m_flag = isLinear;
	}

	Item::~Item()
	{
		clear();
	}

	void Item::clear()
	{
		m_price = 0.0;
		m_quantity = 0;
		m_neededQuantity = 0;
		delete[] m_description;
		m_description = nullptr;
		m_flag = false;
		s.clear();
		unitNum = 0;
	}

	bool Item::operator==(int value) const
	{
		return unitNum == value;
	}

	bool Item::operator==(const char* desc) const
	{
		return (strStr(m_description, desc) != nullptr) && m_description && desc;
	}

	ofstream& Item::save(ofstream& of) const
	{
		if (s) {
			of << '\n' << unitNum << '\t' << m_description << '\t' << m_quantity << '\t' << m_neededQuantity << '\t';
			of.setf(ios::fixed);
			of.precision(2);
			of << m_price;
		}

		return of;
	}

	ifstream& Item::load(ifstream& ifstr) {

		clear();
		string temp;
		ifstr >> unitNum;
		ifstr.ignore();
		getline(ifstr, temp, '\t');

		if (!temp.empty()) {
			ut.alocpy(m_description, temp.c_str());
		}

		ifstr >> m_quantity;
		ifstr.ignore();
		ifstr >> m_neededQuantity;
		ifstr.ignore();
		ifstr >> m_price;
		ifstr.ignore();

		if (!ifstr) {
			s = "Input file stream read failed!";
		}

		return ifstr;
	}


	ostream& Item::display(ostream& ostr) const {
		if (s) {
			if (m_flag) {
				ostr << unitNum << " | ";
				ostr.width(35);
				ostr.setf(ios::left);

				if (m_description && strLen(m_description) > 35) {
					string result = subStr(m_description, 0, 35);
					strCpy(m_description, result.c_str());
					ostr << m_description << " | ";
				}
				else {
					ostr.unsetf(ios::right);
					ostr << m_description << " | ";
				}

				ostr.unsetf(ios::left);
				ostr.width(4);
				ostr.setf(ios::right);
				ostr << m_quantity << " | "; ostr.width(4);
				ostr << m_neededQuantity << " | ";
				ostr.width(7);
				ostr.setf(ios::fixed); ostr.precision(2); ostr << m_price << " |"; ostr.unsetf(ios::right); ostr.unsetf(ios::fixed);
			}
			else {
				ostr << "AMA Item:" << endl;
				ostr << unitNum << ": " << m_description << endl;
				ostr << "Quantity Needed: " << m_neededQuantity << endl;
				ostr << "Quantity Available: " << m_quantity << endl;
				ostr << "Unit Price: $";
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << m_price << endl;
				ostr << "Needed Purchase Fund: $";
				ostr.precision(2);
				double value = (m_neededQuantity - m_quantity) * m_price;
				ostr << value << endl;
			}
		}
		else {
			ostr << s;
		}

		return ostr;
	}
	istream& Item::read(istream& istr)
	{
		string temp;
		cout << "AMA Item:" << endl;
		cout << "SKU: " << unitNum << endl;
		istr.ignore();
		cout << "Description: ";
		getline(istr, temp, '\n');
		if (temp != "") {
			ut.alocpy(m_description, temp.c_str());
		}

		cout << "Quantity Needed: ";
		m_neededQuantity = ut.getint(1, 9999, "", "");
		cout << "Quantity On Hand: ";
		m_quantity = ut.getint(0, m_neededQuantity, "", "");
		cout << "Unit Price: $";
		m_price = ut.getDouble(0.00, 9999.00, nullptr, nullptr);
		if (!istr && !cin) {
			s = "Console Entry failed";
		}

		return istr;
	}

	int Item::readSku(istream& istr) {
		cout << "SKU: ";
		unitNum = ut.getint(40000, 99999, "", "");

		return unitNum;
	}
}
