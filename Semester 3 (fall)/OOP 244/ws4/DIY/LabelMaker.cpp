#include <iostream>
#include "LabelMaker.h"


using namespace std;

namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {
        numLabels = noOfLabels;
		labelArr = new Label[numLabels];
	}

    void LabelMaker::readLabels() {
        cout << "Enter " << numLabels << " labels:" << endl;
        for (int i = 0; i < numLabels; ++i) {
            cout << "Enter label number " << i + 1 << endl;
            labelArr[i].readLabel(); // Read the content for the current label
        }
    }

    void LabelMaker::printLabels() {
        for (int i = 0; i < numLabels; ++i) {
            labelArr[i].printLabel(); // Print the current label
        }
    }

    LabelMaker::~LabelMaker() {
        delete[] labelArr;
        labelArr = nullptr;
    }
}