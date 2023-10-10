#ifndef SDDS_LabelMaker_H_
#define SDDS_LabelMaker_H_

#include <iostream> // Don't forget to include necessary headers
#include "Label.h"

namespace sdds {

    class LabelMaker {
        int numLabels;
        Label* labelArr;

    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };

} // namespace sdds

#endif // SDDS_LABEL_H_

