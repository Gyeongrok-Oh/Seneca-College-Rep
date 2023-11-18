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
#include "Utils.h"

using namespace std;
namespace sdds {

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