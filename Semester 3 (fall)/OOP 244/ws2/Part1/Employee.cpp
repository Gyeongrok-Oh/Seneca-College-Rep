/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo, Gyeongrok oh
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds
{
    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employee) {
        bool ok = false;
     
        if (read(employee.m_empNo) && read(employee.m_salary) && read(*&employee.m_name)) {
            ok = true;
        }
        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
            
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
          
            for (; i < noOfEmployees; ) {
                if (load(employees[i])) {
                    i++; 
                }
            }

            if (i == noOfEmployees) {
                ok = true; 
            }
            else {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
        }
        else {
            cerr << "Could not open data file: employees.csv" << endl;
        }
        closeFile();
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& employee)
    {
        cout << employee.m_empNo << ": " << employee.m_name << ", " << '$' << employee.m_salary << endl;
    }

    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory() {
        
      
        for (int i = 0; i < noOfEmployees; ++i) {
            delete[] employees[i].m_name; 
            employees[i].m_empNo = 0;
            employees[i].m_salary = 0.00;
          
        }

        delete[] employees; 
        noOfEmployees = 0;
    }



} 