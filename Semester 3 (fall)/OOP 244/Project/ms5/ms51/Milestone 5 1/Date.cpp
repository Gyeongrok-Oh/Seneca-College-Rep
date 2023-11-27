/* Citation and Sources...
Final Project Milestone 1
Module: Whatever
Filename: Date.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
using namespace std;

namespace sdds {

	bool Date::validate()
	{
		bool is_valid{ false };

		int currentYear{};

		ut.getSystemDate(&currentYear, nullptr, nullptr);

		State.clear();

		if (year < currentYear || year > max_year) {
			State = "Invalid year in date";
			State = 1;
		}
		else if (month < 1 || month > 12) {
			State = "Invalid month in date";
			State = 2;
		}
		else if (day < 1 || day > ut.daysOfMon(month, year)) {
			State = "Invalid day in date";
			State = 3;
		}
		else {
			is_valid = true;
		}
		return is_valid;
	}
	int Date::intVal() const
	{
		return year * 372 + month * 31 + day;
	}
	Date::Date() {
		ut.getSystemDate(&year, &month, &day);
	}

	Date::Date(const int get_year, const int get_month, const int get_day)
	{
		year = get_year;
		month = get_month;
		day = get_day;

		if (!validate()) {
			init();
		}
	}
	bool Date::operator!=(const Date D) const
	{
		return !((year == D.year) && (month == D.month) && (day == D.day));
	}
	bool Date::operator==(const Date D) const
	{
		return (year == D.year) && (month == D.month) && (day == D.day);
	}
	bool Date::operator<=(const Date D) const
	{
		bool is_true{};

		if (year < D.year) {
			is_true = true;
		}
		else if (year > D.year) {
			is_true = false;
		}
		else { // If years are equal, check months
			if (month < D.month) {
				is_true = true;
			}
			else if (month > D.month) {
				is_true = false;
			}
			else { // If years and months are equal, check days
				is_true = (day <= D.day);
			}
		}
		return is_true;
	}
	bool Date::operator<(const Date D) const
	{
		bool is_true{};

		if (year < D.year) {
			is_true = true;
		}
		else if (year > D.year) {
			is_true = false;
		}
		else { // If years are equal, check months
			if (month < D.month) {
				is_true = true;
			}
			else if (month > D.month) {
				is_true = false;
			}
			else { // If years and months are equal, check days
				is_true = (day < D.day);
			}
		}
		return is_true;
	}
	bool Date::operator>=(const Date D) const
	{
		return !(*this < D);
	}

	bool Date::operator>(const Date D) const
	{
		bool is_valid{};
		if (year > D.year) {
			is_valid = true;
		}
		else if (year < D.year) {
			is_valid = false;
		}
		else {
			if (month > D.month) {
				is_valid = true;
			}
			else if (month < D.month) {
				is_valid = false;
			}
			else {
				is_valid = day > D.day;
			}
		}
		return is_valid;
	}

	const Status& Date::state() const
	{
		return State;
	}

	Date& Date::formatted(bool is_format)
	{
		Formatted = is_format;
		return *this;
	}

	ostream& Date::write(std::ostream& os) const
	{
		if (Formatted) {
			os << year << "/";
			os.fill('0');
			os.setf(ios::right);
			os.width(2);
			os << month << "/";
			os.width(2);
			os << day;
		}
		else {
			os << year % 100;
			os.fill('0');
			os.setf(ios::left);
			os.width(2);
			os << month;
			os.width(2);
			os << day;
		}
		os.fill(' ');
		os.unsetf(ios::left);
		return os;
	}
	std::istream& Date::read(std::istream& is)
	{
		int getInt{};

		if ((!(is >> getInt) && (is.peek() != '\n')) || getInt < 0) {
			State.clear();
			State = "Invalid date value";
		}
		else {
			//Exception handling
			ut.testMode(false);
			if (getInt == 0 || (getInt > 31 && getInt < 100)) { // Invalid state: not provided year and month, invalid day 
				ut.getSystemDate(&year, &month, nullptr);
				day = getInt;
			}
			else if (getInt >= 1 && getInt < 10000) {
				ut.getSystemDate(&year, nullptr, nullptr);
				if (getInt >= 1 && getInt <= 31) { // invalid DD->Day
					day = getInt;
				}
				else if (getInt > 99 && getInt < 1000) { // 3 integer value Examples(MM/DD) : 121 -> 2023(current year)/01/12, invalid : 141 -> 2023(current year)/01/41 "Invalid day"
					month = getInt / 100;

					if ((getInt % 100) >= 1 && (getInt % 100) <= ut.daysOfMon(month, year)) {
						day = getInt % 100;
					}

				}
				else {
					if ((getInt / 100) >= 1 && (getInt / 100) <= 12) { // getInt > 999 && getInt < 10000-> 4 digit
						month = getInt / 100;
						if ((getInt % 100) >= 1 && (getInt % 100) <= ut.daysOfMon(month, year)) {
							day = getInt % 100;
						}
					}
				}
			}
			else if (getInt > 9999 && getInt < 100000) { // invalid year: Example: 11212 -> 2001/12/12 -> already less than current year(2023)
				// do nothing
			}
			else if (getInt > 99999 && getInt < 1000000) {  // 6 digit
				year = 2000 + (getInt / 10000);

				getInt -= (getInt / 10000) * 10000;
				if ((getInt / 100) >= 1 && (getInt / 100) <= 12) {
					month = getInt / 100;
					if ((getInt % 100) >= 1 && (getInt % 100) <= ut.daysOfMon(month, year)) {
						day = getInt % 100;
					}
				}
			}
			else {
				cout << "You Entered: " << getInt << " is too low or much" << endl; // less than 0 or more than 6 digit
			}

			if (!validate()) {
				is.istream::setstate(ios::badbit);
			}
		}


		return is;
	}

	void Date::init()
	{
		year = 0;
		month = 0;
		day = 0;
		if (State != nullptr) {
			State.setEmpty();
			delete State;
			State = nullptr;
		}
	}

	Date& Date::operator=(const Date& other)
	{
		if (this != &other) {
			year = other.year;
			month = other.month;
			day = other.day;
			State = other.State;
			Formatted = other.Formatted;
		}

		return *this;
	}


	ostream& operator<<(std::ostream& os, const Date& date)
	{
		return date.write(os);
	}

	std::istream& operator>>(std::istream& is, Date& date)
	{
		return date.read(is);
	}
}