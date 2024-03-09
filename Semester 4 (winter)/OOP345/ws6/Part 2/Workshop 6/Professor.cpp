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
