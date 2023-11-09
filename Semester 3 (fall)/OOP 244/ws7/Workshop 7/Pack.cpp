/* Citation and Sources...
Workshop 6
Module: Whatever
Filename: HealthCard.cpp
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      11/3/2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include "Pack.h"
#include "Utils.h"
using namespace std;

namespace sdds {
    Pack::Pack(const char* cont, int size, int unitSize, int noOfUnits)
        : Container(cont, size* unitSize, noOfUnits* unitSize) {
        validateAndSetUnitSize(unitSize);
        m_size = size;
        m_noOfUnits = noOfUnits;
    }
    void Pack::validateAndSetUnitSize(int unitSize) {
        if (unitSize > 0) {
            m_unitSize = unitSize;
        }
        else {
            Container::setEmpty();
        }
    }
    int Pack::operator += (int numUnitsToAdd) {
        int value = Container::operator+=(numUnitsToAdd * m_unitSize) / m_unitSize;
        this->m_noOfUnits += value;
        return value;
    }
    int Pack::operator -= (int numUnitsToAdd) {
        int value = Container::operator-=(numUnitsToAdd * m_unitSize) / m_unitSize;
        this->m_noOfUnits -= value;
        return value;
    }
    int Pack::unit() const {
        return m_unitSize;
    }
    int Pack::noOfUnits() const {
        return Container::volume() / m_unitSize;
    }
    int Pack::size() const {
        return Container::capacity() / m_unitSize;
    }

    void Pack::clear(int pack_size, int unitSize, const char* cont)
    {
        if (unitSize > 0) {
            Container::clear(pack_size * unitSize, cont);
            m_size = pack_size;
            m_unitSize = unitSize;
            m_noOfUnits = 0;
        }
    }

    std::ostream& Pack::print(std::ostream& os) const {
        Container::print(os);
        if (this->Container::operator bool()) {
            os << ", " << m_noOfUnits << " in a pack of " << m_size;
        }
        return os;
    }

    std::istream& Pack::read(istream& is)
    {
        if (!(*this)) {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            while (is.get() != '\n') {} // Wait for Enter key press
            is.clear();
        }
        else {
            if (m_noOfUnits < m_size) {
                int value{ 0 };
                bool flag{ false };
                int maxVal = m_size - m_noOfUnits;
                while (!flag) {
                    cout << "Add to ";
                    print(cout);
                    cout << endl << "> ";
                    value = ut.getint(1, maxVal, "", NULL);

                    if (value >= 1 && value <= (m_size - m_noOfUnits)) {
                        *this += value;
                        cout << "Added " << value << endl;
                        flag = true;
                    }


                }
            }
            else {
                cout << "Pack is full!, press <ENTER> to continue...";
                while (is.get() != '\n') {}
                is.clear();
                is.ignore();
            }

        }

        return is;
    }

    std::ostream& operator<<(std::ostream& os, const Pack& pack) {
        return pack.print(os);
    }

    std::istream& operator>>(std::istream& is, Pack& pack) {
        return pack.read(is);
    }

}
