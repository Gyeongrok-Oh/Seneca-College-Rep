#include "Utilities.h"

using namespace std;

namespace seneca {

	char Utilities::m_delimiter{ ' ' };

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string temp;
		int end_pos = str.find_first_of(m_delimiter, next_pos);

		if (str[next_pos] == m_delimiter) {
			more = false;
			throw("Delimiter Not Found.");
		}
		else if (
			str.find(m_delimiter, next_pos) == std::string::npos) {
			temp = str.substr(next_pos); more = false; next_pos = 0;
		}
		else {
			temp = str.substr(next_pos, end_pos - next_pos);

			more = true;

			next_pos = str.find(m_delimiter, next_pos) + 1;
		}

		if (m_widthField < temp.length())
			m_widthField = temp.length();

		return temp;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}


}
