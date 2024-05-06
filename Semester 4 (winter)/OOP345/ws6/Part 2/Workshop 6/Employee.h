//Student Name: Gyeongrok oh
//Student Email: goh3@myseneca.ca
//Student Id: 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H

#include <string>
#include <algorithm>
#include "Person.h"

namespace seneca {
	class Employee : public Person {
		std::string m_name{};
		std::string m_age{};
		std::string m_id{};
		void trim(std::string& str);
	protected:
		std::string m_deptartment{};
	public:
		Employee(std::istream& is);
		std::string status() const;
		std::string name() const;
		std::string id() const;
		std::string age() const;
		void display(std::ostream& out) const;
	};
}
#endif
