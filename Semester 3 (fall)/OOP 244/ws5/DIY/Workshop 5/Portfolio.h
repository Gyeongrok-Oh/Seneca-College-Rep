/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
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
#include <iostream>
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_


namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;
        void emptyPortfolio();

    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        std::ostream& display() const;
        void dispPortfolio() const;
        operator const char* () const;
        operator double() const;
        Portfolio& operator >> (Portfolio & right);
        Portfolio& operator << (Portfolio& right);
        Portfolio& operator += (double value);
        Portfolio& operator -= (double value);
        bool operator ~() const;
        operator const char() const;
        operator bool() const;
        //helper function
        friend double operator +(Portfolio& left, Portfolio& right);
        friend double& operator += (double& left, Portfolio& protFolio);
    };
}
#endif // SDDS_Portfolio_H_