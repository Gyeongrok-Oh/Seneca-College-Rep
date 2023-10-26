/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
//==============================================
// Name:           Gyeongrok oh
// Student Number: 119140226
// Email:          goh3@myseneca.ca
// Section:        NAA
//==============================================
// Mark.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "cstring" // to use the string library "strcpy(m_stock, stock);"
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator const char* () const { 
        return m_stock; 
    }

    double operator +(Portfolio& first, Portfolio& second) {
        int sum = first.m_value + second.m_value;
        return (sum) ? sum : 0;
    }

    Portfolio::operator double () const {
        return m_value;
    }

    double& operator += (double& left, Portfolio& protFolio) {
        left += protFolio.m_value;

        return left;
    }

    Portfolio& Portfolio::operator >> (Portfolio& right) {
        // Check if it's a self-assignment
        if (this != &right) {
            // Transfer the value to the right portfolio
            right.m_value += m_value;
            // Empty the current portfolio
            emptyPortfolio(); // this
        }
        return *this;
    }

    Portfolio& Portfolio::operator << (Portfolio& right) {
        // Check if it's a self-assignment
        if (this != &right) {
            // Transfer the value to the left portfolio
            m_value += right.m_value;
            // Empty the right portfolio
            right.emptyPortfolio();
        }
        return *this;
    }

    Portfolio& Portfolio::operator += (double value) {
        // Check if the Portfolio evaluates to TRUE and the value is non-negative
        if (m_value > 0 && value >= 0) {
            // Add the value to the Portfolio
            m_value += value;
        }
        return *this;
    }

    Portfolio& Portfolio::operator -= (double value) {
        // Check if the Portfolio evaluates to TRUE and the value is non-negative
        if (m_value > 0 && value >= 0) {
            // Subtract the value from the Portfolio
            m_value -= value;
            if (m_value < 0) {
                m_value = 0;
            }
        }
        return *this;
    }

    bool Portfolio::operator ~() const {
        return m_value < 0;
    }

    Portfolio::operator const char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
    }


}