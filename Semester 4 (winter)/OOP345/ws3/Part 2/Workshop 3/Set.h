//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student id : 119140226

#ifndef SENECA_SET_H
#define SENECA_SET_H

#include "Collection.h"
#include <cmath>

namespace seneca {
    template<typename T>
    class Set : public Collection<T, 100> {

    public:
        bool add(const T& item);
        void addElement(const T& item);
    };

    template<typename T>
    inline bool Set<T>::add(const T& item)
    {
        for (size_t i = 0; i < this->currElements; i++) {
            if (this->elements[i] == item) {
                return false;
            }
        }

        addElement(item);

        return true;
    }

    template<>
    bool Set<double>::add(const double& item) {

        for (size_t i = 0; i < currElements; i++) {
            if (std::fabs(elements[i] - item) <= 0.01) {
                return false;
            }
        }

        addElement(item);

        return true;
    }

    template <typename T>
    inline void Set<T>::addElement(const T& item)
    {
        this->elements[this->currElements] = item;
        this->currElements++;
    }
}
#endif
