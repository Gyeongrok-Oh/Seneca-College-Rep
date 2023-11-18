/* Citation and Sources...
Final Project Milestone 1
Module: Whatever
Filename: Date.h
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      2023/10/31
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include "Status.h"

namespace sdds {
	const int max_year = 2030;
	class Date {
		int year{};
		int month{};
		int day{};
		Status* State{ nullptr };
		bool Formatted{ true };
		bool validate();
		int intVal() const;
	public:
		Date();
		Date(const int get_year, const int get_month, const int get_day);
		bool operator!=(const Date D)const;
		bool operator==(const Date D)const;
		bool operator<=(const Date D)const;
		bool operator<(const Date D)const;
		bool operator>=(const Date D)const;
		bool operator>(const Date D)const;
		const Status& state()const;
		Date& formatted(bool is_format);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		void init(); // added
		~Date();
		//helper function
		friend std::ostream& operator<<(std::ostream& os, const Date& date);
		friend std::istream& operator>>(std::istream& is, Date& date);
	};
};
#endif