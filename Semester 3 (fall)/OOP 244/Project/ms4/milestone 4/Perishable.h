/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.h
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      Nov 23, 2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H_
#define SDDS_PERISHABLE_H_

#include "Item.h"
#include "Date.h"

namespace sdds {
	class Perishable : public Item {
		Date expDate{};
		char* instruction{};
	public:
		Perishable();
		Perishable(const Perishable& perishable);
		Perishable& operator=(const Perishable& other);
		const Date& expiry() const;
		virtual int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& of) const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr) const;
		std::istream& read(std::istream& is);
		operator bool() const;
		~Perishable();
	};
	extern int count_linear;
}
#endif

