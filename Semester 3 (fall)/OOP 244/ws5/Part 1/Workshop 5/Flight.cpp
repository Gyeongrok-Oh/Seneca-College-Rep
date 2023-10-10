/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }

    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }

    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const { 

        double minRequiredFuel = m_passengers * 600.0;

        return (m_passengers > 0 && m_fuel >= minRequiredFuel);
    }

    Flight::operator int() const { 
        return m_passengers; 
    }

    Flight::operator double() const { 
        return m_fuel; 
    }

    Flight::operator const char* () const { 
        return m_title; 
    }

    bool Flight::operator ~() const {
        return m_passengers == 0;
    }

    Flight& Flight::operator =(sdds::Flight& right) {
        
        m_passengers = right.m_passengers;
        m_fuel = right.m_fuel;
        strcpy(this->m_title, right.m_title);

        right.emptyPlane();

        return *this;
    }

    Flight& Flight::operator >>(sdds::Flight& right) {
        if ( (*this) && (right)) { // Check if both flights are valid
            int availableSpace = Boen747Capacity - right.m_passengers;
            if (this->m_passengers > availableSpace) {
                right.m_passengers += availableSpace;
                this->m_passengers -= availableSpace;
            }
            else {
                right.m_passengers += m_passengers; 
                this->m_passengers = 0;
            }
        }

        return *this;
    }

    Flight& Flight::operator +=(double fuel) {
        if ((fuel > -1) && m_fuel <= FuelTankCapacity) {
            m_fuel += fuel;
            if (m_fuel > FuelTankCapacity) {
                m_fuel = FuelTankCapacity;
            }
        }

        return *this;
    }

    Flight& Flight::operator -=(double fuel) {
        if (fuel > -1) {
            m_fuel -= fuel;
            if (m_fuel < 0) {
                m_fuel = 0;
            }
        }

        return *this;
    }

    Flight& Flight::operator +=(int pas) { 
        if (pas > -1 && pas <= Boen747Capacity) {
            m_passengers += pas;
            if (m_passengers > Boen747Capacity) {
                m_passengers = Boen747Capacity;
            }
        }
        
        return *this; 
    }
    
    Flight& Flight::operator -=(int pas) {
        if (pas > -1 && pas <= Boen747Capacity) {
            m_passengers -= pas;
        }
        
        return *this; 
    }



    Flight& Flight::operator =(int pas) { 
        if (pas > -1 && pas <= Boen747Capacity) { 
            m_passengers = pas; 
        }
        
        return *this; 
    }

    Flight& Flight::operator =(double fuel) { 
        if (fuel > -1 && fuel <= FuelTankCapacity) { 
            m_fuel = fuel; 
        }
        
        return *this; 
    }

    int operator + (const Flight& first, const Flight& second) {
        int numOfP = first.m_passengers + second.m_passengers;
        return (numOfP) ? numOfP : 0;
    }

    int& operator += (int& left, const Flight& flight) {
        if (left > -1 && flight.m_passengers <= Boen747Capacity) {
            left += flight.m_passengers;
        }
        else {
            left = 0;
        }

        return left;
    }
}