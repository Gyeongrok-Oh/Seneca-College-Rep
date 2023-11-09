/* Citation and Sources...
Workshop 6
Module: Whatever
Filename: HealthCard.cpp
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      11/3/2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_CONTAINER_H_
#define SDDS_CONTAINER_H_

#include <iostream> 

namespace sdds {
	class Container {
	private:
		char m_content[51]{ '\0' };
		int m_capacity{};
		int m_volume{};
	protected:
		void setEmpty();
		int capacity() const; 
		int volume() const; 
	public:
		Container(const char* cont, int cap, int volume = 0);
		int operator+=(int vol);
		int operator-=(int vol);
		operator bool() const;
		void clear(int cap, const char* cont);
		std::ostream& print(std::ostream& os) const; 
		std::istream& read(std::istream& is); 
	};
	std::ostream& operator<<(std::ostream& os, const Container& C);
	std::istream& operator>>(std::istream& is, Container& C);
}
#endif