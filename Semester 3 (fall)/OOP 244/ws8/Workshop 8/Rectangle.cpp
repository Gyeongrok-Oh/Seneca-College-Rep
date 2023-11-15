#include "Rectangle.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0)
	{
	}
    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label), m_width(width), m_height(height) {

        if (m_height < 3 || m_width < (strLen(LblShape::label()) + 2)) {

            m_width = 0;
            m_height = 0;
        }
    }
    void Rectangle::getSpecs(std::istream& is)
    {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore(1000, ',');
        is >> m_height;
        is.ignore(1000, '\n');
    }
    void Rectangle::draw(std::ostream& os) const
    {
        int i{ 0 };

        const char* getLabel = label();
        // Check if the label is not null before using it
        if ((getLabel[0] != 0 && getLabel != nullptr) && (m_width > 0 && m_height > 0)) {
            LblShape::draw(os);
            os << "+";
            for (; i < m_width - 2; i++) {
                os << "-";
            }
            os << "+" << std::endl;

            os << "|";
            os.setf(std::ios::left);
            os.width(m_width - 2);
            os << getLabel << "|" << std::endl;

            for (i = 0; i < m_height - 3; i++) {
                os << "|";
                os.width(m_width - 2);
                os << ' ';
                os << "|" << std::endl;
            }

            os << "+";
            for (i = 0; i < m_width - 2; i++) {
                os << "-";
            }
            os << "+";
        }
    }

}