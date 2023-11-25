#include "Student.h"
using namespace std;
namespace sdds {

    Student::Student() : m_name(nullptr), m_age(0) {}
    Student::Student(const char* name, int age) : m_age(age)
    {
        if (name != nullptr)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
    }
    Student::Student(const Student& student) : m_age(student.m_age)
    {
        m_name = new char[strlen(student.m_name) + 1];
        strcpy(m_name, student.m_name);
    }
    Student& Student::operator=(const Student& student)
    {
        if (this != &student)
        {
            m_age = student.m_age;
            delete[] m_name;
            if (student.m_name || student.m_name[0])
            {
                m_name = new char[strlen(student.m_name) + 1];
                strcpy(m_name, student.m_name);
            }
        }

        return *this;
    }
    Student::~Student()
    {
        delete[] m_name;
        m_name = nullptr;
    }
    void Student::display()
    {
        cout << "Name: " << m_name << endl;
        cout << "Age: " << m_age << endl;
    }

}