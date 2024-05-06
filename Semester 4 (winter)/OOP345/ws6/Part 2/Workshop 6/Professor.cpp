//Student Name: Gyeongrok oh
//Student Email: goh3@myseneca.ca
//Student Id: 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "Professor.h"
#include "Utilities.h"

using namespace std;

namespace seneca {

    Professor::Professor(istream& in) : Employee(in) {
        m_department = Employee::m_deptartment;
    }

    void Professor::display(ostream& out) const {
        Employee::display(out);

        out << m_department;
        out << "| Professor";

    }

    string Professor::status() const {
        return "Professor";
    }

    string Professor::department() const {
        return m_department;
    }



}
