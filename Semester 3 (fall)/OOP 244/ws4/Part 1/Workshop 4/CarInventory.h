#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H

namespace sdds {
    class CarInventory {
        char* m_type; // not null
        char* m_brand; // not null
        char* m_model; // not null
        int m_year; // year >= 1990
        int m_code; // three-digit integer
        double m_price; // price > 0
        void resetInfo();
        

    public:
        CarInventory();
        ~CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year = 0, int code = 0, double price = 0);
        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;
    };
    int find_similar(CarInventory car[], const int num_cars);
}

#endif
