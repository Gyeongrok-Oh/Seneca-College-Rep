#include "ConfirmOrder.h"

using namespace std;

namespace seneca {
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
    {
        bool is_add{ true };

        for (size_t i = 0; i < cnt; i++) {
            if (m_toys[i] == &toy) {
                is_add = false;
            }
        }

        if (is_add) {
            const Toy** temp = new const Toy * [cnt + 1];

            for (size_t i = 0; i < cnt; i++) {
                temp[i] = m_toys[i];
            }

            temp[cnt++] = &toy;

            // Delete the old array
            delete[] m_toys;

            // Update m_toys to point to the new array
            m_toys = temp;
        }

        return *this;
    }


    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        // Search for the address of toy in the array
        for (size_t i = 0; i < cnt; ++i) {
            if (m_toys[i] == &toy) {
                // Set the pointer to nullptr to remove the toy from the array
                m_toys[i] = nullptr;
                cnt--;
                for (size_t j = i; j < cnt; j++) {
                    m_toys[j] = m_toys[j + 1];
                }
                return *this;
            }
        }

        return *this; // Toy not found in the array, do nothing
    }




    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& other)
    {
        os << "--------------------------" << endl;
        os << "Confirmations to Send" << endl;
        os << "--------------------------" << endl;

        if (other.cnt == 0) {
            os << "There are no confirmations to send!" << endl;
        }
        else {
            for (size_t i = 0; i < other.cnt; i++) {
                os << *other.m_toys[i];
            }
        }

        os << "--------------------------" << endl;

        return os;
    }

    ConfirmOrder::ConfirmOrder() : m_toys(0), cnt(0)
    {

    }

    ConfirmOrder::~ConfirmOrder() {
        // Deallocate memory for the array
       /* delete[] m_toys;*/
    }

}

