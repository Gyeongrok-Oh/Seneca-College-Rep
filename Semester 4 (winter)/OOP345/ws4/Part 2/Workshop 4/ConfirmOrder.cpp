//Name : Gyeongrok Oh
//Email : goh3@myseneca.ca
//Student Id : 119140226
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "ConfirmOrder.h"

using namespace std;

namespace seneca {
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
    {
        for (size_t i = 0; i < cnt; i++) {
            if (m_toys[i] == &toy) {
                return *this;  
            }
        }

        const Toy** temp = new const Toy * [cnt + 1];

        for (size_t i = 0; i < cnt; i++) {
            temp[i] = m_toys[i];
        }

        temp[cnt] = &toy;

        deallocate();

        m_toys = temp;

        
        cnt++;

        return *this;
    }



    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        if (cnt > 0) { 
            bool found = false; 
            size_t index = 0; 
            
            for (size_t i = 0; i < cnt && !found; i++) { 
                if (m_toys[i] == &toy) { 
                    m_toys[i] = nullptr; 
                    found = true; 
                    index = i; 
                } 
            
            } 
            
            if (found) { 
                for (size_t j = index; j < cnt - 1; j++) { 
                    m_toys[j] = m_toys[j + 1]; 
                } 
                
                m_toys[cnt - 1] = nullptr; 
                
                cnt--; 
            } 
        
        } 
        
        return *this;
    }


    ConfirmOrder::ConfirmOrder(const ConfirmOrder& other)
    {
        *this = other;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other)
    {
        if (this != &other) {
            cnt = other.cnt;

 
            m_toys = new const Toy * [cnt];

            for (size_t i = 0; i < cnt; i++) {
                m_toys[i] = other.m_toys[i];
            }

        }
        return *this;
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& other) noexcept
    {
        *this = move(other);
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) noexcept
    {
        if (this != &other) {

            cnt = other.cnt;

            m_toys = other.m_toys;

            other.m_toys = nullptr;

            other.cnt = 0;
        }
        return *this;
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

    void ConfirmOrder::deallocate()
    {
        for (size_t i = 0; i < cnt; i++) {
            m_toys[i] = nullptr;
        }

        delete[] m_toys;
        m_toys = nullptr;
    }

    ConfirmOrder::ConfirmOrder() : m_toys(0), cnt(0)
    {

    }

    ConfirmOrder::~ConfirmOrder() {
        
        deallocate();
    }

}

