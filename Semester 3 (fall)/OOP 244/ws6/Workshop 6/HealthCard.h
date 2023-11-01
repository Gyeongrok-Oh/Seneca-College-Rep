#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds {
    const int MaxNameLength = 55;
    class HealthCard {
        char* m_name{}; // Full name is a Cstring that is not null and not empty.
        long long m_number{}; // The main health number consists of 10 digits (>999999999 and <9999999999)
        char m_vCode[3]{}; // The version number consists of two characters
        char m_sNumber[10]{}; // The Stock control number consists of nine characters
        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
        void setEmpty();
        void allocateAndCopy(const char* name);
        void extractChar(std::istream& istr, char ch) const;
        void set(const char* name, long long number, const char vCode[], const char sNumber[]);
        std::ostream& printIDInfo(std::ostream& ostr) const;
    public:
        HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});
        ~HealthCard();
        HealthCard(const HealthCard& hc);
        HealthCard& operator=(const HealthCard& hc);
        operator bool() const;
        std::ostream& print(std::ostream& ostr, bool toFile = true) const;
        std::istream& read(std::istream& istr);
        friend std::istream& operator>>(std::istream& istr, HealthCard& hc);
        friend std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
    };
}
#endif // !SDDS_HealthCard_H

