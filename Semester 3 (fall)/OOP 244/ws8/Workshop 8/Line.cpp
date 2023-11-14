#include "Line.h"

using namespace std;

namespace sdds {
	Line::Line() : m_length(0), LblShape()
	{
	}
	Line::Line(const char* label, int length) : LblShape(label), m_length(0)
	{
	}
	void Line::getSpecs(istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n'); // Ignore the rest of the characters up to 1000 and including the newline character '\n'
	}
	void Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;

			for (unsigned int i{ 0 }; i < m_length; i++) {
				os << "=";
			}
			os << endl;
		}
	}
}

