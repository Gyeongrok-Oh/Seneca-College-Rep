/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"

using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    //optional functions
    void Utils::alocpy(char*& destination, const char* source) {
        // Delete existing memory if any
        delete[] destination;

        if (source && source[0] != 0) {
            // Allocates memory in the destination to the size of the source
            size_t len = strLen(source);
            destination = new char[len + 1];

            // Copies the source into the allocated memory
            strCpy(destination, source);
        }
        else {
            // If source is null or empty, set destination to nullptr
            destination = nullptr;
        }
    }




    int Utils::getint(const char* prompt)
    {
        if (prompt[0] != 0 && prompt != nullptr) {
            cout << prompt;
        }


        int input{};

        while (!(cin >> input) || (cin.peek() != '\n')) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n'); // chose buffer size(100) immediately
            }
            cout << "Invalid Integer, retry: ";
        }

        return input;
    }
    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int get_int{};
        bool is_int = false;

        while (!is_int) {
            get_int = getint(prompt);
            is_int = (get_int >= min && get_int <= max);

            if (!is_int) {
                if (errMes != nullptr && errMes[0] != 0) {
                    std::cout << errMes << ", retry: " << std::endl;
                }
                else {
                    std::cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
            }
        }

        return get_int;
    }

    double Utils::getDouble(const char* prompt)
    {
        if (prompt != nullptr && prompt[0] != '\0') {
            std::cout << prompt;
        }

        double input = 0.0;

        while (!(std::cin >> input) || (std::cin.peek() != '\n')) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(100, '\n'); // chose buffer size(100) immediately
            }
            std::cout << "Invalid number, retry: ";
        }

        return input;
    }

    double Utils::getDouble(double min, double max, const char* prompt, const char* errMes)
    {
        double get_double = 0.0;
        bool is_double = false;

        while (!is_double) {
            get_double = getDouble(prompt);
            is_double = (get_double >= min && get_double <= max);

            if (!is_double) {
                if (errMes != nullptr && errMes[0] != '\0') {
                    std::cout << errMes << ", retry: " << std::endl;
                }
                else {
                    std::cout << "Value out of range [";
                    cout.setf(ios::fixed);
                    cout.precision(2); 
                    cout << min << "<=val<=" << max << "]: ";


                }
            }
        }

        return get_double;
    }


    // strLen: Calculate the length of the C-String in characters
    int strLen(const char* s)
    {
        // Declare Variable to store the length
        int length;

        // Set the "while" loop to repeat until the corresponding index has a value
        for (length = 0; s[length] != '\0'; length++);

        return length;
    }

    // strCpy: Cpies the srouce character string into the destination
    void strCpy(char* des, const char* src)
    {
        int i;

        // Set the "while" loop to repeat until 'src' has a value the corresponding index
        for (i = 0; src[i] != '\0'; i++)
        {
            // Copy the String from 'src' to 'des'
            des[i] = src[i];
        }
        // Set the last index to be NULL value
        des[i] = '\0';
    }

    // strnCpy: Copies the source character string into the destination upto "len" characters.
    void strnCpy(char* des, const char* src, int len)
    {
        int i;

        if (strLen(src) >= len)
        {
            // Set the "while" loop to copy the 'src' as long as 'len'
            for (i = 0; i < len; i++)
            {
                des[i] = src[i];
            }
        }
        else
        {
            // Set the "while" loop to copy the 'src' as long as the length of 'src'
            for (i = 0; i < strLen(src); i++)
            {
                des[i] = src[i];
            }
        }
        des[i] = '\0';
    }

    // strCmp: Compares two C-strings
    int strCmp(const char* s1, const char* s2)
    {
        int i = 0;
        int value = 0;
        bool equal = true;

        while (equal)
        {
            if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            {
                equal = false;
            }
            else {
                i++;
            }
        }

        value = s1[i] - s2[i];
        return value;
    }




    // strnCmp: Compares two C-strings upto "len" characters.
    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0;
        int value = 0;
        bool equal = true;

        while (equal && i < len)
        {
            if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            {
                equal = false;
                value = s1[i] - s2[i];
            }
            else {
                i++;
            }
        }

        return value;
    }


    // strStr: returns the address of first occurance of "str2" in "str1"
    const char* strStr(const char* str1, const char* str2)
    {
        const char* p1 = str1;
        const char* p2 = str2;
        const char* match = nullptr;
        bool flag = true;
        while (*p1 && flag) {
            if (*p1 == *p2) {
                match = match == nullptr ? p1 : match;
                p2++;

                if (*p2 == '\0') {
                    flag = false; // Substring found, exit the loop
                }
            }
            else {
                p2 = str2;
                match = nullptr;
            }

            p1++;
        }

        return match; // Return match (nullptr if substring not found)
    }

    // strCat: Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src)
    {
        int des_len = strLen(des); // Get the length of 'des'
        int src_len = strLen(src); // Get the length of 'src'

        // Copy characters from 'src' to the end of 'des'
        for (int i = 0; i <= src_len; i++) {
            des[des_len + i] = src[i];
        }
    }

    string subStr(const char* str, size_t start, size_t length) {
        std::string result;

        if (str != nullptr) {
            size_t strLength = 0;
            while (strLength < length && str[strLength] != '\0') {
                strLength++;
            }

            if (start < strLength && length > 0) {
                for (size_t i = 0; i < length && str[start + i] != '\0'; i++) {
                    result += str[start + i];
                }
            }
        }

        return result;
    }


}