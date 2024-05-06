//Student Name: Gyeongrok oh
//Student Email: goh3@myseneca.ca
//Student Id: 119140226
//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H

#include "Person.h"
#include "Utilities.h"

namespace seneca {

    class Student : public Person {
        std::string m_name{""};
        std::string m_age{""};
        std::string m_id{""};
        std::string* m_courses{nullptr};
        unsigned int m_count{0};

    public:
        Student(std::istream& is);
        ~Student();
        std::string status() const override;
        std::string name() const;
        void display(std::ostream& out) const override;
        std::string age() const override;
        std::string id() const override;
        Student(const Student&) = delete;
        Student& operator=(const Student&) = delete;
    };
}

#endif