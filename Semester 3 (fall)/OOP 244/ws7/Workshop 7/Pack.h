/* Citation and Sources...
Workshop 6
Module: Whatever
Filename: HealthCard.cpp
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      11/10/2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_PACK_H_
#define SDDS_PACK_H_

#include "Container.h"

namespace sdds {
	class Pack : public Container {
		int m_size{};
		int m_unitSize{}; 
		int m_noOfUnits{};

	public:
		Pack(const char* Content, int Size, int unitSize = 330, int NumberOfUnits = 0);
		void validateAndSetUnitSize(int unitSize);
		int operator+=(int numUnitsToAdd);
		int operator -= (int numUnitsToAdd);
		int unit() const;
		int noOfUnits() const;
		int size() const;
		void clear(int pack_size, int unitSize, const char* cont);
		std::ostream& print(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Pack& pack);
	std::istream& operator>>(std::istream& is, Pack& pack);
}
#endif