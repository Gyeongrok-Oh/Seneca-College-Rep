#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include "Toy.h"

namespace seneca {
	class Child {
		std::string m_name;
		int m_age;
		const seneca::Toy** m_toyArr;
		size_t m_count;
	public:
		Child(std::string name, int age, const seneca::Toy* toys[], size_t count);
		size_t size() const;
		Child();
		~Child();
		Child(const Child& child);
		Child& operator=(const Child& child);
		Child(Child&& child);
		Child& operator=(Child&& child);
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif