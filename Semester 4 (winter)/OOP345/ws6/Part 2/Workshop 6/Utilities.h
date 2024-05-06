//Student Name: Gyeongrok oh
//Student Email: goh3@myseneca.ca
//Student Id: 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "Person.h"  
#include "Employee.h" 
#include "Professor.h"
#include "Student.h"

namespace seneca {
	Person* buildInstance(std::istream& in);
}
#endif
