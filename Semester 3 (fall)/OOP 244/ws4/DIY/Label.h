#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_

#include <iostream> // Don't forget to include necessary headers

namespace sdds {

    class Label {
        char* cont;
        char frame[9];

    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        std::istream& readLabel();
        std::ostream& printLabel() const;
        Label& text(const char* content);
    };


} // namespace sdds

#endif // SDDS_LABEL_H_
