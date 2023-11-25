#ifndef SDDS_GRADUATE_H_
#define SDDS_GRADUATE_H_

#include "Student.h"
namespace sdds {
    class Graduate : public Student
    {
    private:
        char* m_thesis{};
        char* m_supervisor{};
    public:
        Graduate();
        Graduate(const char* name, int age, const char* thesis, const char* supervisor);
        Graduate(const Graduate& graduate);
        Graduate& operator=(const Graduate& graduate);
        ~Graduate();
        void display();
    };
}

#endif