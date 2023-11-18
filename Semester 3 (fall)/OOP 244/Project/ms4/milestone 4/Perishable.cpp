#include <iostream>
#include <fstream> 
#include "Perishable.h"

using namespace std;

namespace sdds {
	Perishable::Perishable() : Item()
	{
	}
	Perishable::Perishable(const Perishable& perishable)
	{
		*this = perishable;
	}

	Perishable& Perishable::operator=(const Perishable& other)
	{
		if (this != &other) {
			Item::operator=(other);
			expDate = other.expDate;
			this->instruction = other.instruction;
		}

		return *this;
	}

	const Date& Perishable::expiry() const
	{
		return expDate;
	}

	int Perishable::readsku(std::istream& istr)
	{
		cout << "SKU: ";
		Item::unitNum = ut.getint(40000, 99999, "", "");

		return unitNum;
	}

	ofstream& Perishable::save(ofstream& of) const
	{
		if (*this) {
			Item::save(of);
			of << '\t';
			if (instruction[0] != 0 && instruction != nullptr) {
				of << instruction;
			}

			// Write another tab
			of << '\t';

			// Write an unformatted copy of the expiry date
			Date temp = expDate;
			temp.formatted(false); // Assuming this function formats the date as needed
			of << temp;
		}
		return of;
	}


}

