//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Child.h"

using namespace std;

namespace seneca {

	void Child::deallocate()
	{
		if (m_toyArr != nullptr) {
			for (size_t i = 0; i < m_count; i++) {
				delete m_toyArr[i];
			}

			delete[] m_toyArr;
		}
	}

	Child::Child(std::string name, int age, const Toy* toys[], size_t count) : m_name(name), m_age(age), m_count(count)
	{

		m_toyArr = new const Toy * [m_count];

		for (size_t i = 0; i < m_count; i++) {
			m_toyArr[i] = new Toy(*toys[i]);  
		}
	}

	size_t Child::size() const
	{
		return m_count;
	}

	Child::Child() : m_name(""), m_age(0), m_toyArr(nullptr), m_count(0)
	{
	}

	Child::~Child()
	{
		deallocate();
	}


	Child::Child(const Child& child)
	{
		this->m_toyArr = nullptr;
		*this = child;
	}

	Child& Child::operator=(const Child& child)
	{
		if (this != &child) {
			m_name = child.m_name;
			m_age = child.m_age;

			deallocate();


			m_count = child.m_count;

			m_toyArr = new const Toy * [m_count]; 

			for (size_t i = 0; i < m_count; i++) {
				m_toyArr[i] = new Toy(*(child.m_toyArr[i]));
			}
		}

		return *this;
	}



	Child::Child(Child&& child) noexcept
	{
		*this = move(child);

	}

	Child& Child::operator=(Child&& child) noexcept
	{
		if (this != &child) {

			m_name = child.m_name;
			m_age = child.m_age;
			m_count = child.m_count;
			m_toyArr = child.m_toyArr;

			
			child.m_name = "";
			child.m_age = 0;
			child.m_count = 0;
			child.m_toyArr = nullptr;
		}
		return *this;
	}



	
	ostream& operator<<(ostream& os, const Child& child)
	{
		static unsigned int CALL_CNT{ 1 };

		os << "--------------------------" << endl;
		os << "Child " << CALL_CNT << ": " << child.m_name << " " << child.m_age << " years old:" << endl;
		os << "--------------------------" << endl;

		size_t t_size = child.size();

		if (!t_size) {
			os << "This child has no toys!" << endl;
		}
		else {
			for (size_t i = 0; i < t_size; i++) {
				os << *(child.m_toyArr[i]);
			}
		}
		os << "--------------------------" << endl;
		CALL_CNT++;

		return os;
	}


}