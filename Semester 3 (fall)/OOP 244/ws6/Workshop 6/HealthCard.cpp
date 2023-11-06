/* Citation and Sources...
Workshop 6
Module: Whatever
Filename: HealthCard.cpp
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      11/3/2023
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
#include <cstring>
#include "HealthCard.h"
#include "Utils.h" // custom file
using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		return (name != nullptr && name[0] != 0) && (number > 999999999 && number < 9999999999) && (strLen(vCode) == 2) && (strLen(sNumber) == 9);
	}
	void HealthCard::setEmpty()
	{
		m_name = nullptr;
		m_number = -1;
		*m_vCode = '\0';
		*m_sNumber = '\0';
	}
	void HealthCard::allocateAndCopy(const char* name) {
		// Free the memory pointed to by m_name
		delete[] m_name;

		if (name) {
			if (m_name != nullptr) {
				delete[] m_name;
			}
			// Allocate enough memory to store the new name C-string
			m_name = new char[strLen(name) + 1]; // +1 for the null terminator

			// Check if the allocation was successful
			if (m_name) {
				// Copy the C-string pointed to by name into the newly allocated memory pointed to by m_name
				strCpy(m_name, name);
			}
		}
		else {
			m_name = nullptr;
		}
	}


	void HealthCard::extractChar(istream& istr, char ch) const {
		if (istr.peek() == ch) {
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}



	ostream& HealthCard::printIDInfo(ostream& ostr) const
	{
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
	
		return ostr;
	}

	HealthCard::HealthCard(const HealthCard& hc)
	{
		setEmpty();
		if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}

	}

	HealthCard& HealthCard::operator=(const HealthCard& hc)
	{
		if (this != &hc) {
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}

	HealthCard::operator bool() const
	{
		return m_name != nullptr;
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const
	{
		if (*this) {
			if (toFile) {
				ostr << m_name << ",";
				printIDInfo(ostr) << endl;
			}
			else {
				ostr.width(50);
				ostr.setf(ios::left);
				ostr.fill('.');
				ostr << m_name;
				ostr.unsetf(ios::left);
				printIDInfo(ostr);
			}
		}

		return ostr;
	}

	istream& HealthCard::read(istream& istr) {
		if (m_name != nullptr) {
			delete[] m_name;
		}
		m_name = new char[MaxNameLength + 1];
		long long number = 0; 
		char vCode[3]{'\0'};
		char sNumber[10]{'\0'};
		istr.get(m_name, MaxNameLength, ',');
		char* copy = new char[strLen(m_name) + 1];
		strCpy(copy, m_name);
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(sNumber, 10, '\n');

		if (!istr.fail()) {
			set(copy, number, vCode, sNumber);
		}

		istr.clear();
		istr.ignore(1000,'\n');
		if (copy != nullptr) {
			delete[] copy;
			copy = nullptr;
		}

		return istr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
		if (validID(name, number, vCode, sNumber)) {
			allocateAndCopy(name);
			m_number = number;
			strCpy(m_vCode, vCode); // Assuming m_vCode is a char array and vCode is a C-style string
			strCpy(m_sNumber, sNumber); // Assuming m_vCode is a char array and vCode is a C-style string
		}
		else {
			if (m_name != nullptr) {
				delete[] m_name;
			}
			setEmpty();
		}

	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[] )
	{
		set(name, number, vCode, sNumber);
	}


	istream& operator>>(istream& istr, HealthCard& hc)
	{
		hc.read(istr);
		return istr;
	}

	ostream& operator<<(ostream& ostr, const HealthCard& hc)
	{
		if (hc.validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			hc.print(ostr, false);
		}
		else {
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}

	HealthCard::~HealthCard()
	{
		delete[] m_name;
		m_name = nullptr;
	}
}