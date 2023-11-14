/***********************************************************************
// Milestone 3
// Module: iProduct
// File: iProduct.cpp
// Version 1.0
// Author  Gyeongrok oh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
/***********************************************************************
// Final project Milestone 3
// Module: iProduct
// File: iProduct.cpp
// Version 1.0
// Author  Gyeongrok oh
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Gyeongrok oh                Date 2023/Nov/13           Reason
***********************************************************************/
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