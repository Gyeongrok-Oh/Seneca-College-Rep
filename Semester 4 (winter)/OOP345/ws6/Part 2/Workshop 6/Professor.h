//Student Name: Gyeongrok oh
//Student Email: goh3@myseneca.ca
//Student Id: 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "Employee.h"
#include "Professor.h"
#include "Utilities.h"

namespace seneca {

    class Professor : public Employee {
        std::string m_department;
    public:
        Professor(std::istream& in);
        void display(std::ostream& out) const override;
        std::string status() const override;
        std::string department() const;
    };

} 

#endif 

