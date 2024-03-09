//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca {
	class Book {
	private:
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_desc;
		std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v");
		std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v");
		std::string& trim(std::string& s, const char* t = " \t\n\r\f\v");
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
		template <class T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
		}
		Book(const Book& other);
		Book& operator=(const Book& book);

	};
}

#endif
