/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare overloaded read function prototypes

	// Reads the name of the employee | Accepts as a parameter the address of an array of characters
	bool read(char*& empName);
	// Reads employee number | Accepts as a parameter a reference to an integer
	bool read(int& empNumber);
	// Reads the employee salary | Acceptes as a parameter a reference to an floating point number
	// in double precision
	bool read(double& empSalary);
} 
#endif 