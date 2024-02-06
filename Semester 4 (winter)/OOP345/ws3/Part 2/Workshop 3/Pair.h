//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student id : 119140226

#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <iostream>

namespace seneca {
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		Pair();
		friend std::ostream& operator<<(std::ostream& os, const Pair& other);
		bool operator==(const Pair& other) const;
	};
}

#endif
