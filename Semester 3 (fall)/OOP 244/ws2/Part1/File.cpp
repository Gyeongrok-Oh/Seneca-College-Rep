/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
#include <cstring> // added 

namespace sdds
{
 
    FILE* fptr; // global variable:

 
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
           while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
         }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

   
    bool read(char*& empName) {
        char getStr[128] = "\0"; // Initialize with NULL terminators
        bool success = false;

        if (fscanf(fptr, "%127[^\n]\n", getStr)) {
            size_t nameLen = strlen(getStr) + 1; // +1 is for the NULL terminator
            empName = new char[nameLen]; // Allocate memory
            strncpy(empName, getStr, nameLen - 1); // Copy the string up to length of name
            empName[nameLen - 1] = '\0'; // Ensure NULL termination
            success = true;
        }
        return success;
    }

    bool read(int& empNumber)
    {
        return fscanf(fptr, "%d,", &empNumber);
    }

    bool read(double& empSalary)
    {
        return fscanf(fptr, "%lf,", &empSalary) == 1;
    }


} 