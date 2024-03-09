#include "Employee.h"

using namespace std;

namespace seneca {

	void Employee::trim(string& str)
	{
		str.erase(0, str.find_first_not_of(" \t\r\n"));
		str.erase(str.find_last_not_of(" \t\r\n") + 1);
	}



	Employee::Employee(std::istream& is)
	{
		std::string str;
		is.ignore(1);


		std::getline(is, str);
		size_t startIndex{ 0 };
		size_t endIndex = str.find(',');

		m_name = str.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		trim(m_name);

		startIndex = endIndex + 1;  // Move to the next character after the comma
		endIndex = str.find(',', startIndex);  // Find the next comma
		m_age = str.substr(startIndex, (endIndex - startIndex));
		trim(m_age);


		for (auto& ch : m_age) {
			if (isdigit(ch) == 0) {
				throw m_name + "++Invalid record!";
			}
		}

		startIndex = endIndex + 1;
		endIndex = str.find(',', startIndex);
		m_id = str.substr(startIndex, (endIndex - startIndex));
		trim(m_id);

		// Validate ID
		if (tolower(m_id[0]) != 'e') {
			throw m_name + "++Invalid record!";
		}

		startIndex = endIndex + 1;
		endIndex = str.find(',', startIndex);
		m_deptartment = str.substr(startIndex, (endIndex - startIndex));
		trim(m_deptartment);
	}

	std::string Employee::status() const
	{
		return "Employee";
	}

	std::string Employee::name() const
	{
		return m_name;
	}

	std::string Employee::id() const
	{
		return m_id;
	}

	std::string Employee::age() const
	{
		return m_age;
	}

	void Employee::display(std::ostream& out) const
	{ 
 		out << "| ";
		out.setf(ios::left);
		out.width(10);
		out << "Employee";
		out << "| ";
		out.width(10);
		out << m_id;
		out << "| ";
		out.width(20);
		out << m_name;
		out << " | ";
		out.width(3);
		out << m_age;
		out << " |";
		out.unsetf(ios::left);
	}


}