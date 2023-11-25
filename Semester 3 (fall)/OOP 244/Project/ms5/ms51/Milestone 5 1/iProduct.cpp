/* Citation and Sources...
Final Project Milestone 1
Module: iProduct
Filename: iProduct.cpp
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
#include "iProduct.h"

using namespace std;

namespace sdds {
	int iProduct::readSku(std::istream& istr)
	{
		int userInput{};
		istr >> userInput;
		return userInput;
	}
	int iProduct::operator-=(int qty) {
		return qty;
	}
	iProduct::operator double() const {
		return 0.0;
	}
	iProduct::operator bool() const {
		return false;
	}
	int iProduct::qtyNeeded() const {
		return 0;
	}
	int iProduct::qty() const {
		return 0;
	}
	void iProduct::linear(bool isLinear) {
		cout << isLinear;
	}
	std::ofstream& iProduct::save(std::ofstream& ofstr) const {
		return ofstr;
	}
	std::ifstream& iProduct::load(std::ifstream& ifstr) {
		return ifstr;
	}
	std::ostream& iProduct::display(std::ostream& ostr) const {
		return ostr;
	}
	std::istream& iProduct::read(std::istream& istr) {
		return istr;
	}
	bool iProduct::operator==(int sku) const {
		return false;
	}
	bool iProduct::operator==(const char* description) const {
		return false;
	}
	int iProduct::operator+=(int qty) {
		return qty;
	}
	ostream& operator<<(ostream& ostr, const iProduct& iproduct) {
		return iproduct.display(ostr);
	}
	istream& operator>>(istream& istr, iProduct& iproduct) {
		return iproduct.read(istr);
	}
}