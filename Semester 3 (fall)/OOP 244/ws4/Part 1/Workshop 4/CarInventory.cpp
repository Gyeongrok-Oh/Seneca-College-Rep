#define _CRT_SECURE_NO_WARNINGS 
#include "CarInventory.h" 
#include<cstdio> 
#include<cstring> 
#include <iostream> 
using namespace std; 

namespace sdds {
	CarInventory::CarInventory() 
	{ 
		resetInfo(); 
	} 
	
	void CarInventory::resetInfo() 
	{ 
		m_type = nullptr; 
		m_brand = nullptr; 
		m_model = nullptr; 
		m_year = 0; 
		m_code = 0; 
		m_price = 0.00; 
	}

    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        resetInfo();

        // Allocate memory and copy the provided strings
        m_type = new char[strlen(type) + 1];
        strcpy(m_type, type);
 
        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);

        m_model = new char[strlen(model) + 1];
        strcpy(m_model, model);

        // Set other attributes based on the provided arguments
        if (year > 0) {
            m_year = year;
        }
        else {
            m_year = 2022;
        }

        // Validate and set the code (assuming it should be a three-digit integer)
        if (code > 0) {
            m_code = code;
        }
        else {
            m_code = 100;
        }

        if (price > 0.0) {
            m_price = price;
        }
        else {
            m_price = 1.0;
        }
    }


    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
    {// Deallocate existing memory for attributes
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

        // Reset attributes
        resetInfo();

        m_type = new char[strlen(type) + 1];
        strcpy(m_type, type);

        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);

        m_model = new char[strlen(model) + 1];
        strcpy(m_model, model);

        m_year = year;
        m_code = code;
        m_price = price;

        return *this;
    }

    void CarInventory::printInfo() const
    {
        cout << "| ";
        cout.setf(ios::left);
        cout.width(11);
        cout << m_type;
        cout << "| ";
        cout.width(17);
        cout << m_brand;
        cout << "| ";
        cout.width(17);
        cout << m_model;
        cout << "| ";
        cout << m_year;
        cout << " |";
        cout.unsetf(ios::left);
        cout.setf(ios::fixed);
        cout.width(5);
        cout << m_code;
        cout << " |";
        cout.width(10);
        cout.precision(2);
        cout << fixed << m_price << " |" << endl;
        cout.unsetf(ios::fixed);
    }

    bool CarInventory::isValid() const
    {
        bool is_valid = true;

        if (m_type == nullptr || m_brand == nullptr || m_model == nullptr || m_year < 1990 || (m_code < 100 && m_code > 999) || m_price <= 0) {
            is_valid = false;
        }

        return is_valid;
    }

    int find_similar(CarInventory car[], const int num_cars) {

        int found_index = -1;
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    // Match is found, return the index of the first match
                    found_index = i;
                    i = num_cars;
                }
            }
        }

        // No match found, return -1
        return found_index;
    }

    bool CarInventory::isSimilarTo(const CarInventory& car) const {
        // Check if any of the values are nullptr, return false
        if (!isValid()) {
            return false;
        }

        // Compare the type, brand, and year, and return true only if they all match
        return (strcmp(m_type, car.m_type) == 0 &&
            strcmp(m_brand, car.m_brand) == 0 &&
            m_year == car.m_year);
    }
   

	CarInventory::~CarInventory() 
	{
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

	}
}