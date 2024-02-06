#include "Child.h"

using namespace std;

namespace seneca {
	Child::Child(std::string name, int age, const Toy* toys[], size_t count) : m_name(name), m_age(age), m_count(count)
	{
		m_toyArr = new const Toy*[m_count];

		for (size_t i = 0; i < m_count; i++) {
			m_toyArr[i] = toys[i];
		}
	}
	size_t Child::size() const
	{
		return m_count;
	}

	Child::Child() : m_name(""), m_age(-1), m_toyArr(nullptr), m_count(0)
	{
	}

	Child::~Child()
	{
		//delete[] m_toyArr;
		//m_toyArr = nullptr;
	}

	Child::Child(const Child& child)
	{
		*this = child;
	}

	Child& Child::operator=(const Child& child)
	{
		if (this != &child) {
			m_name = child.m_name;
			m_age = child.m_age;

			delete[] m_toyArr;
			m_toyArr = nullptr;

			m_toyArr = 
			m_count = child.m_count;

			for (size_t i = 0; i < m_count; i++) {
				m_toyArr[i] = child.m_toyArr[i];
			}
		
		}
		return *this;
	}

	Child::Child(Child&& child)
	{
		*this = move(child);
	}

	Child& Child::operator=(Child&& child)
	{
		if (this != &child) {
			m_name = child.m_name;
			m_age = child.m_age;

			delete[] m_toyArr;
			m_toyArr = nullptr;

			m_count = child.m_count;

			for (size_t i = 0; i < m_count; i++) {
				m_toyArr[i] = child.m_toyArr[i];
			}

			for (size_t i = 0; i < m_count; i++) {
				child.m_toyArr[i] = nullptr;
			}

			child.m_count = 0;
	
		}
		return *this;
	}

	
	ostream& operator<<(ostream& os, const Child& child)
	{
		static unsigned int CALL_CNT{ 1 };

		os << "--------------------------" << endl;
		os << "Child " << CALL_CNT << ": " << child.m_name << " AGE " << "years old:" << endl;
		os << "--------------------------" << endl;

		size_t t_size = child.size();

		if (t_size) {
			os << "This child has no toys!" << endl;
		}
		else {
			for (size_t i = 0; i < t_size; i++) {
				os << child.m_toyArr[i];
			}
		}

		return os;
	}


}