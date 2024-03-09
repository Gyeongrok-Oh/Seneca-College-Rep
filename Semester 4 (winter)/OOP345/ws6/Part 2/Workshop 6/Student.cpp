#include "Student.h"
#include "Utilities.h"

using namespace std;

namespace seneca {

    Student::Student(std::istream& is) {
		std::string str;
		is.ignore(1);


		std::getline(is, str);
		size_t startIndex{ 0 };
		size_t endIndex = str.find(',');

		m_name = str.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		m_name.erase(0, m_name.find_first_not_of(" \t\r\n"));
		m_name.erase(m_name.find_last_not_of(" \t\r\n") + 1);

		startIndex = endIndex + 1;  // Move to the next character after the comma
		endIndex = str.find(',', startIndex);  // Find the next comma
		m_age = str.substr(startIndex, (endIndex - startIndex));

		m_age.erase(0, m_age.find_first_not_of(" \t\r\n"));
		m_age.erase(m_age.find_last_not_of(" \t\r\n") + 1);

		for (auto& ch : m_age) {
			if (isdigit(ch) == 0) {
				throw m_name + "++Invalid record!";
			}
		}

		startIndex = endIndex + 1;
		endIndex = str.find(',', startIndex);
		m_id = str.substr(startIndex, (endIndex - startIndex));
		m_id.erase(0, m_id.find_first_not_of(" \t\r\n"));
		m_id.erase(m_id.find_last_not_of(" \t\r\n") + 1);

		// Validate ID
		if (tolower(m_id[0]) != 's') {
			throw m_name + "++Invalid record!";
		}

		std::string countStr{""};

		startIndex = endIndex + 1; 
		endIndex = str.find(',', startIndex); 
		countStr = str.substr(startIndex, (endIndex - startIndex));
		countStr.erase(0, countStr.find_first_not_of(" \t\r\n"));
		countStr.erase(countStr.find_last_not_of(" \t\r\n") + 1);


		try {
			m_count = std::stoi(countStr);
		}
		catch (const std::invalid_argument& e) {
			// Handle the case where conversion fails
			throw std::runtime_error("Invalid count value: " + countStr);
		}
		catch (const std::out_of_range& e) {
			// Handle the case where the converted value is out of range
			throw std::runtime_error("Count value out of range: " + countStr);
		}



		m_courses = new std::string[m_count];
		for (size_t i = 0; i < m_count; i++) {
			startIndex = endIndex + 1; 
			endIndex = str.find(',', startIndex); 
			m_courses[i] = str.substr(startIndex, (endIndex - startIndex));
			m_courses[i].erase(0, m_courses[i].find_first_not_of(" \t\r\n")); 
			m_courses[i].erase(m_courses[i].find_last_not_of(" \t\r\n") + 1); 
		}
 
    }

    // Destructor
    Student::~Student() {
        // Deallocate memory for courses
        delete[] m_courses;
    }

    // Public Member Functions

    std::string Student::status() const {
        return "Student";
    }

    std::string Student::name() const {
        return m_name;
    }

    void Student::display(std::ostream& out) const {
        // Display format: | Student | id | name | age | courses
		out.setf(ios::left);
		out << "| ";
		out.width(10);
		out << "Student";
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
		for (size_t i = 0; i < m_count - 1; i++) {
			out << m_courses[i] << ", ";
		}
		out << m_courses[m_count - 1];
    }

	std::string Student::age() const
	{
		return m_age;
	}

	std::string Student::id() const
	{
		return m_id;
	}

}