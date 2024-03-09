#include "Station.h"
#include <iomanip>

using namespace std;

namespace seneca {
    size_t Station::m_widthField{ 0 };
    size_t Station::id_generator{ 0 };

    Station::Station(const std::string& str) {
        Utilities utility;
        m_id = ++Station::id_generator;
        size_t next_pos = 0; bool more = true;
        m_itemName = more ? utility.extractToken(str, next_pos, more) : "";
        m_serialNumber = more ? std::stoi(utility.extractToken(str, next_pos, more)) : 0;
        m_quantity = more ? std::stoi(utility.extractToken(str, next_pos, more)) : 0;
        m_widthField = (utility.getFieldWidth() > m_widthField) ? utility.getFieldWidth() : m_widthField;
        m_description = more ? utility.extractToken(str, next_pos, more) : "";

        m_description.erase(0, m_description.find_first_not_of(" \t\r\n"));
        m_description.erase(m_description.find_last_not_of(" \t\r\n") + 1);

    }


    const std::string& Station::getItemName() const
    {
        return m_itemName;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const
    {
        return m_quantity;
    }

    void Station::updateQuantity()
    {
        if (m_quantity > 0) {
            --m_quantity;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        os << setw(3) << right << std::setfill('0') << m_id << " | ";
        os << left << setw(m_widthField) << std::setfill(' ') << m_itemName << " | ";
        os << setw(6) << right << std::setfill('0') << m_serialNumber << " | ";

        if (full == false) {
            os << std::endl;
        }
        else {
            os << setw(4) << right << std::setfill(' ') << m_quantity << " | " << m_description << std::endl;
        }

    }
}
