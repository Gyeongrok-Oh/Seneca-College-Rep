#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#include <iostream>
#include <cstring>
namespace sdds {
    class Student
    {
    private:
        char* m_name{};
        int m_age{};
    public:
        Student();
        Student(const char* name, int age);
        Student(const Student& student);
        Student& operator=(const Student& student);
        virtual~Student();
        void display();

    };
}
#endif