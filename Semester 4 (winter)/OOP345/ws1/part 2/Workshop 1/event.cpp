//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Name : Gyeongrok oh
//Email : goh3@myseneca.ca
//Student number : 119140226

#include "event.h"

using namespace std;

namespace seneca {

    size_t g_sysClock;

    Event::Event() : desc(nullptr), time(0) {
    }

    void Event::display() const {

        static int counter = 1;

        g_sysClock = time;

        cout.width(2);
        cout.setf(ios::right);
        cout << counter;
        cout << ". ";

        if (desc != nullptr && desc[0] != 0) {
            size_t hours = time / 3600;
            g_sysClock %= 3600;

            size_t minutes = g_sysClock / 60;
            g_sysClock %= 60;

            size_t seconds = g_sysClock;

            cout.fill('0');
            cout.width(2);
            cout << hours;
            cout << ":";
            cout.width(2);
            cout << minutes;
            cout << ":";
            cout.width(2);
            cout << seconds;
            cout << " => ";
            cout << desc;

            cout.fill(' ');
        }
        else {
            cout << "| No Event |";
        }

        cout << endl;

        counter++;
    }

    void Event::set(const char* description) {

        delete[] desc;
        desc = nullptr;

        if (description != nullptr && description[0] != 0) {
            time = g_sysClock;
            desc = new char[strlen(description) + 1];
            strcpy(desc, description);
        }
    }

    Event::Event(const Event& event) : desc(nullptr)
    {
        time = event.time;

        delete[] desc;
        desc = nullptr;

        if (event.desc != nullptr && event.desc[0] != 0) {
            desc = new char[strlen(event.desc) + 1];
            strcpy(desc, event.desc);
        }
       
    }

    Event& Event::operator=(const Event& event)
    {
        if (this != &event) {
            time = event.time;

   
            delete[] desc;
            desc = nullptr;

            // Copy the description
            if (event.desc != nullptr) {
                desc = new char[strlen(event.desc) + 1];
                strcpy(desc, event.desc);
            }
        }

        return *this;
    }

    Event::~Event()
    {
        delete[] desc;
        desc = nullptr;
    }

}
