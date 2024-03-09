//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
#include "Book.h"

using namespace std;

namespace seneca{

	Book::Book() : m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.00), m_desc("")
	{
	}

	const std::string& Book::title() const
	{
		return m_title;
	}

	const std::string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

    std::string& Book::ltrim(std::string& s, const char* t)
    {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

    std::string& Book::rtrim(std::string& s, const char* t)
    {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    std::string& Book::trim(std::string& s, const char* t)
    {
        return ltrim(rtrim(s, t), t);
    }

	Book::Book(const std::string& strBook) {
		std::string str = strBook;
		trim(str);

		size_t field = str.find(",");
		m_author = str.substr(0, field);
		trim(m_author);
		str.erase(0, field + 1);

		field = str.find(",");
		m_title = str.substr(0, field);
		trim(m_title);
		str.erase(0, field + 1);

		field = str.find(",");
		m_country = str.substr(0, field);
		trim(m_country);
		str.erase(0, field + 1);

		field = str.find(",");
		m_price = std::stod(str.substr(0, field));
		str.erase(0, field + 1);

		field = str.find(",");
		m_year = std::stoi(str.substr(0, field));
		str.erase(0, field + 1);

		m_desc = str;
		trim(m_desc);
	}


	Book::Book(const Book& other)
	{
		*this = other;
	}

	Book& Book::operator=(const Book& book)
	{
		if (this != &book) {
			m_author = book.m_author;
			m_title = book.m_title;
			m_country = book.m_country;
			m_year = book.m_year;
			m_price = book.m_price;
			m_desc = book.m_desc;
		}
		return *this;
	}



	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os.width(20);
		os << book.m_author;
		os << " | ";
		os.width(22);
		os << book.m_title;
		os << " | ";
		os.width(5);
		os << book.m_country;
		os << " | ";
		os.width(4);
		os << book.m_year;
		os << " | ";
		os.width(6);
		os.setf(ios::fixed);
		os.precision(2);
		os << book.m_price;
		os << " | ";
		os << book.m_desc << endl;


		return os;
	}

}