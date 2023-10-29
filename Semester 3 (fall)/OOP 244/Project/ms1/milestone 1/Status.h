/* Citation and Sources...
Final Project Milestone 1
Module: Whatever
Filename: Status.h
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
#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_
#include "Utils.h"

namespace sdds {
	class Status{
		char* description{};
		int code{};
		Utils ut;
	public:
		Status();
		Status(char * desc);
		void setEmpty();
		operator bool() const;
		Status& operator=(const char* desc);
		Status& operator=(const int right);
		Status& clear();
		operator const char* () const;
		operator int() const;
		//helper function
		friend std::ostream& operator<<(std::ostream& os, const Status s);
	};
}
#endif