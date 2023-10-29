/* Citation and Sources...
Final Project Milestone 1
Module: Whatever
Filename: Status.cpp
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"

using namespace std;

namespace sdds {
	Status::Status()
	{
		setEmpty();
	}
	Status::Status(char* desc)
	{
		if (desc[0] != 0 && desc != nullptr) {
			ut.alocpy(description, desc);
			Status s = 0;
		}
		else {
			setEmpty();
		}
	}
	void Status::setEmpty()
	{
		description = nullptr;
		code = 0;
	}
	Status::operator bool() const
	{
		return (description == nullptr);
	}
	Status& Status::operator=(const char* desc)
	{
		ut.alocpy(description, desc);
		return *this;
	}
	Status& Status::operator=(const int right)
	{
		this->code = right;
		return *this;
	}
	Status& Status::clear()
	{
		delete[] description;
		description = nullptr;
		code = 0;

		return *this;
	}
	Status::operator const char* () const
	{
		return description;
	}
	Status::operator int() const
	{
		return code;
	}
	std::ostream& operator<<(std::ostream& os, const Status s) {
		if (s.code) {
			os << "ERR#" << s.code << ": " << s.description;
		}
		else {
			os << s.description;
		}
	
		return os;
	}
	
}
