//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student id : 119140226

#include "Pair.h"

using namespace std;

namespace seneca {
	ostream& operator<<(ostream& os, const Pair& pair) {

		os.width(20);
		os.setf(ios::right);
		os << pair.m_key;
		os.setf(ios::left);
		os << ": " << pair.m_value;
		return os;
	}

	Pair::Pair() : m_key(""), m_value("") {}

	bool Pair::operator==(const Pair& other) const
	{
		return (m_key == other.m_key);
	}


}