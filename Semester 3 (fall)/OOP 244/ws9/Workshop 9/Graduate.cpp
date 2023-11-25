#include <cstring>
#include "Graduate.h"
using namespace std;
namespace sdds {
    Graduate::Graduate() : m_thesis(nullptr), m_supervisor(nullptr)
    {
    }
    Graduate::Graduate(const char* name, int age, const char* thesis, const char* supervisor) : Student(name, age)
    {
        if (thesis && thesis[0])
        {
            m_thesis = new char[strlen(thesis) + 1];
            strcpy(m_thesis, thesis);
        }
        if (name && name[0]){
            m_supervisor = new char[strlen(supervisor) + 1];
            strcpy(m_supervisor, supervisor);
        }
    }

    Graduate::Graduate(const Graduate& graduate) : Student(graduate)
    {
        if (graduate.m_thesis && graduate.m_thesis[0])
        {
            m_thesis = new char[strlen(graduate.m_thesis) + 1];
            strcpy(m_thesis, graduate.m_thesis);
        }
        if (graduate.m_supervisor && graduate.m_supervisor[0]) {
            m_supervisor = new char[strlen(graduate.m_supervisor) + 1];
            strcpy(m_supervisor, graduate.m_supervisor);
        }
    }
    Graduate& Graduate::operator=(const Graduate& graduate)
    {
        if (this != &graduate)
        {
            Student::operator=(graduate);
            delete[] m_thesis;
            delete[] m_supervisor;

            if (graduate.m_thesis && graduate.m_supervisor)
            {
                m_thesis = new char[strlen(graduate.m_thesis) + 1];
                strcpy(m_thesis, graduate.m_thesis);

                m_supervisor = new char[strlen(graduate.m_supervisor) + 1];
                strcpy(m_supervisor, graduate.m_supervisor);
            }
        }

        return *this;
    }
    Graduate::~Graduate()
    {
        delete[] m_thesis;
        m_thesis = nullptr;
        delete[] m_supervisor;
        m_supervisor = nullptr;
    }
    void Graduate::display()
    {
        Student::display();
        cout << "Thesis Title: " << m_thesis << endl;
        cout << "Supervisor: " << m_supervisor << endl;
        cout << "---------------------------------------------" << endl;
    }

}