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
