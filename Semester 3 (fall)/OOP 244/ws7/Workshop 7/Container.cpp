/* Citation and Sources...
Workshop 6
Module: Whatever
Filename: HealthCard.cpp
Version 1.0
Author	Gyeongrok oh
Revision History
-----------------------------------------------------------
Date      11/10/2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#include "Container.h"
#include "Utils.h"
using namespace std;

namespace sdds {
    Container::Container(const char* cont, int cap, int volume) {
        if ((cont[0] != 0 && cont != nullptr) && (strLen(cont) > 0 && strLen(cont) < 51)) {
            strCpy(m_content,cont);
        }
        else {
            cerr << "Invalid content" << endl;
        }

        m_capacity = cap;

        m_volume = volume;

    }
    int Container::operator+=(int vol)
    {
        int spaceAvailable = m_capacity - m_volume;

        if (spaceAvailable >= vol) {
            spaceAvailable = vol;
            m_volume += vol;
        }
        else {
            spaceAvailable = m_capacity - m_volume;
            m_volume = m_capacity;
        }

        return spaceAvailable;
    }
    int Container::operator-=(int vol)
    {
        int value{ 0 };

        if (m_volume >= vol) {
            m_volume -= vol;
            value = vol;
        }
        else {
            value = m_volume;
            m_volume = 0;
        }

        return value;

    }
    Container::operator bool() const
    {
        return ((m_capacity >= 0) && (m_volume >= 0) && (m_volume <= m_capacity) && (m_content[0] != 0));
    }
    void Container::clear(int cap, const char* cont)
    {
        if (cap > 0 && (cont[0] != 0 && cont != nullptr)) {
            m_capacity = cap;
            strCpy(m_content, cont);
            m_volume = 0; 
        }
    }

    void Container::setEmpty() {
        *m_content = '\0';
        m_capacity = 0;
        m_volume = 0;
    }

    int Container::capacity() const
    {
        return m_capacity;
    }

    int Container::volume() const
    {
        return m_volume;
    }


    std::ostream& Container::print(std::ostream& os) const {
        if (*this) {
            os << m_content << ": (" << m_volume << "cc/" << m_capacity << ")";
        }
        else {
            os << "****: (**cc/***)";
        }
        return os;
    }

    std::istream& Container::read(std::istream& is) {
        if (!(*this)) {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            while (is.get() != '\n') {} 
            is.clear();
            is.ignore();
        }
        else {
            int value{ 0 };
            bool flag{ false };
            while (!flag) {
                cout << "Add to ";
                print(cout);
                value = ut.getint(1, 220000, "\n> ", "Trying to read into broken container...");
                if (value >= 1 && value <= 220000) {
                    value = (*this += value);
                    cout << "Added " << value << " CCs" << endl;
                    flag = true;
                }
            }
         
     
        }
        return is;
    }

    std::ostream& operator<<(std::ostream& os, const Container& C) {
        return C.print(os);
    }

    std::istream& operator>>(std::istream& is, Container& C) {
        return C.read(is);
    }


}

