//#pragma once
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Name : Gyeongrok oh
//Email : goh3@myseneca.ca
//Student number : 119140226


#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <iostream>
#include <cstring>

namespace seneca {
    extern size_t g_sysClock;

    class Event {
        char desc[129];
        size_t time;

    public:
        Event();
        void display() const;
        void set(const char description[] = nullptr);
    };
}

#endif
