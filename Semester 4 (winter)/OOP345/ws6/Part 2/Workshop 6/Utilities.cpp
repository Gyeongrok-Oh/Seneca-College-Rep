//Student Name: Gyeongrok oh
//Student Email: goh3@myseneca.ca
//Student Id: 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include "Utilities.h"

namespace seneca {

    Person* buildInstance(std::istream& in)
    {
        char tag;
        in >> tag;

        if (!in.good()) {

            return nullptr;
        }

        if (tag == 's' || tag == 'S') {
            return new Student(in);
        }

        if (tag == 'p' || tag == 'P') {
            return new Professor(in);
        }

        if (tag == 'e' || tag == 'E') {
            return new Employee(in);
        }

        in.ignore(1000, '\n');
        return nullptr;
    }

}
