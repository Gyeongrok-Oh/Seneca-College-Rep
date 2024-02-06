//I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
//Name : Gyeongrok oh
//Email : goh3@myseneca.ca
//Studemt ID : 119140226
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <iostream>
#include <fstream>
#include <string>

namespace seneca {
    class StringSet {
        std::string* strings{ nullptr };
        size_t numStrings{ 0 };

    public:
        StringSet() = default;
        StringSet(const char* fileName);
        size_t size() const;
        std::string operator[](size_t index);
        StringSet& operator=(const StringSet& other);
        StringSet(const StringSet& other);
        StringSet(StringSet&& other) noexcept;
        StringSet& operator=(StringSet&& other)noexcept;
        ~StringSet();
        void deallocate();
    };
}
#endif
