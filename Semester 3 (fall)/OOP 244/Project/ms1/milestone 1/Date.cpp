#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
using namespace std;

namespace sdds {

	bool Date::validate()
	{
		bool is_valid{ false };
		
		int currentYear{};

		ut.getSystemDate(&currentYear,NULL,NULL);

		if (year < currentYear || year > max_year) {
			State->clear();
			*State = "Invalid year in date";
			*State = 1;
		}
		else if (month < 1 || month > 12) {
			State->clear();
			*State = "Invalid month in date";
			*State = 2;
		}
		else if (day < 1 || day > 12) {
			State->clear();
			*State = "Invalid day in date";
			*State = 3;
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
			year = 0;
			month = 0;
			day = 0;
			//Processing invalid dates
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
		return *State;
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
		os.unsetf(ios::left);
		return os;
	}
	std::istream& Date::read(std::istream& is)
	{
		int getInt{};

		if (State == nullptr) {
			State = new Status(); // Allocate memory for State if it's nullptr
		}

		if (!(is >> getInt) || (is.peek() != '\n') || getInt < 0) {
			State->clear();
			*State = "Invalid date value";
		}
		else {
			ut.testMode(false);
			if (getInt == 0 || (getInt > 31 && getInt < 100)) { // two digit integer and invlaid day
				ut.getSystemDate(&year, &month, NULL);
				day = getInt;
				if (!validate()) {
					is.istream::setstate(ios::badbit);
				}
			}
			else if (getInt >= 1 && getInt <= 12) {
				ut.getSystemDate(&year, NULL, NULL);
			}
		}


		return is;
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