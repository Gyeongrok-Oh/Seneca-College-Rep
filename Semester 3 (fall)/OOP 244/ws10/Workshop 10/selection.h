/***********************************************************************
// OOP244 Workshop # 10
//
// File: selection.h
// Version 1.0
// Date: 2023/11/25
// Author: Gyeongrok oh
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date  Nov/30/2023          Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H

#include <iostream>
#include "Student.h"
#include "Car.h"

namespace sdds {
    template <typename arrayType, typename keyType>
    int* select(const arrayType array[], const keyType& key, size_t size) {
        int* indices = new int[size + 1]; 
        int count = 0; 

        for (size_t i = 0; i < size; ++i) {

            if (array[i] == key) {
                indices[count++] = static_cast<int>(i); 
            }
        }

        indices[count] = -1; 
        return indices;
    }


    template <typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], const int* indices) {
        std::cout << title << std::endl;

        if (indices && indices[0] != -1) {

            for (int i = 0; indices[i] != -1; ++i) {
                std::cout << array[indices[i]];
                if (indices[i + 1] != -1) {
                    std::cout << ", ";
                }
            }
        }
        else {

            std::cout << "Empty Selection";
        }

        std::cout << std::endl;
    }
}

#endif 
