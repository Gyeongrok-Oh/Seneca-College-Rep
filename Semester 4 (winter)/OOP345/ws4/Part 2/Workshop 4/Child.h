//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include "Toy.h"

namespace seneca {
	class Child {
		std::string m_name;
		int m_age;
		const seneca::Toy** m_toyArr;
		size_t m_count;
		void deallocate();
	public:
		Child(std::string name, int age, const seneca::Toy* toys[], size_t count);
		size_t size() const;
		Child();
		~Child();
		Child(const Child& child);
		Child& operator=(const Child& child);
		Child(Child&& child) noexcept;
		Child& operator=(Child&& child) noexcept;
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif