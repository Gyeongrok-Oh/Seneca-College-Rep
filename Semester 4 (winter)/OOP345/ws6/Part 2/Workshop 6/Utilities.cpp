#include "Utilities.h"

namespace seneca {

    Person* buildInstance(std::istream& in)
    {
        char tag;
        in >> tag;

        if (!in.good()) {
            // Handle the error or return nullptr
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

} // namespace seneca
