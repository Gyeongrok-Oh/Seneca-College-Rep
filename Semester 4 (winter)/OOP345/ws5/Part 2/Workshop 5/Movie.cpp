//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
#include "Movie.h"

using namespace std;

namespace seneca {

	Movie::Movie() : m_title(""), m_year(0), m_desc("")
	{
	}

	const string& Movie::title() const
	{
		return m_title;
	}

    std::string Movie::trimWhitespace(const std::string& str = "") {
        size_t firstNonSpace = str.find_first_not_of(' ');
        size_t lastNonSpace = str.find_last_not_of(' ');

        if (firstNonSpace == std::string::npos) {
            return "";
        }

        return str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
    }

    Movie::Movie(const std::string& strMovie) : m_year(0) {
        std::string title, year, desc;
        std::string str = strMovie;


        size_t firstComma = str.find(',');
        if (firstComma == std::string::npos) {
            return;
        }

        title = str.substr(0, firstComma);
        str.erase(0, firstComma + 1);

        size_t secondComma = str.find(',');
        if (secondComma == std::string::npos) {
            return;
        }

        year = str.substr(0, secondComma);
        str.erase(0, secondComma + 1);

        desc = str;

        title = trimWhitespace(title);
        desc = trimWhitespace(desc);

        try {
            m_year = std::stoi(year);
        }
        catch (const std::invalid_argument&) {
            return ;
        }

        m_title = title;
        m_desc = desc;
    }


    ostream& operator<<(ostream& os, const Movie& movie)
    {
        os.width(40);
        os << movie.m_title;
        os << " | ";
        os.width(4);
        os << movie.m_year;
        os << " | ";
        os << movie.m_desc << endl;

        return os;
    }


}