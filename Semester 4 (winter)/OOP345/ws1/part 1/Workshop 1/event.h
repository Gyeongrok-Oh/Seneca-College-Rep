// event.h
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
