#include <iostream>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		return (name != nullptr && name[0] != 0) && (number > 999999999 && number < 9999999999) && (strlen(vCode) == 2) && (strlen(sNumber) == 9);
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

		// Allocate enough memory to store the new name C-string
		m_name = new char[strlen(name) + 1]; // +1 for the null terminator

		// Check if the allocation was successful
		if (m_name) {
			// Copy the C-string pointed to by name into the newly allocated memory pointed to by m_name
			strcpy_s(m_name, strlen(name) + 1, name);
		}
		else {
			// Handle the case of failed memory allocation
			// For instance, you might set m_name to nullptr or take other appropriate actions.
			m_name = nullptr;
		}
	}

	void HealthCard::extractChar(std::istream& istr, char ch) const
	{
		int nextCharInt = istr.peek(); // Get the next character as an integer

		if (nextCharInt == EOF) {
			istr.setstate(std::ios::failbit); // If no characters are left in the stream, set the failbit
			return;
		}

		char nextChar = nextCharInt; // Convert the integer to a character

		int n = 1000; // Ignore all the remaining characters up to 1000

		if (ch == nextChar) {
			istr.ignore();
		}
		else {
			istr.ignore(n, ch);
			istr.setstate(std::ios::failbit); // Set the failbit when the specified character isn't found
		}
	}


	ostream& HealthCard::printIDInfo(ostream& ostr) const
	{
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber << endl;
		return ostr;
	}

	HealthCard::HealthCard(const HealthCard& hc)
	{
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
		if (validID(m_name, m_number, m_vCode, m_sNumber)) {
			if (toFile) {
				ostr << m_name << ",";
				printIDInfo(ostr);
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

		m_name = new char[MaxNameLength];
		istr.get(m_name, MaxNameLength, ',');
		char* copy = new char[strlen(m_name) + 1];
		strcpy_s(copy, strlen(m_name) + 1, m_name);
		extractChar(istr, ',');
		istr >> m_number;
		extractChar(istr, '-');
		istr.get(m_vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(m_sNumber, 10, '\n');

		if (!istr.fail()) {
			set(copy, m_number, m_vCode, m_sNumber);
		}

		istr.clear();
		istr.ignore(1000,'\n');
		delete[] copy;
		return istr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		if (validID(name, number, vCode, sNumber)) {
			allocateAndCopy(name);
			m_number = number;
			strcpy_s(m_vCode, strlen(vCode) + 1, vCode); // Assuming m_vCode is a char array and vCode is a C-style string
			strcpy_s(m_sNumber, strlen(sNumber) + 1, sNumber); // Assuming m_vCode is a char array and vCode is a C-style string
		}
		else {
			delete[] m_name;
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
			ostr << "Invalid Card Number" << endl;
		}
		return ostr;
	}

	HealthCard::~HealthCard()
	{
		if (m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
		}
	}
}