#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "cStrTools.h"
#include "Phone.h"

using namespace std;

namespace sdds {

    void phoneDir(const char* programTitle, const char* fileName) {

        cout << programTitle << " phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* file = fopen(fileName, "r");

        if (file == nullptr) {
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl << endl;
        }
        else {
            char name[MAX_LENGTH + 1];
            string temp;
            bool flag = true;
            const char* found_location = 0;
            while (flag) {
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl << "> ";
                cin >> name;
                toLowerCaseAndCopy(name, name);
                if (strCmp(name, "!") == 0) {

                    cout << "Thank you for using " << programTitle << " directory." << endl;
                    flag = false;
                }
                else {
                    fseek(file, 0, SEEK_SET);
                    Phone phone;
                    while (fscanf(file, "%[^\t]\t%s\t%s\t%s\n", phone.name, phone.area, phone.prefix, phone.number) != EOF) {
                        temp = phone.name;
                        toLowerCaseAndCopy(phone.name, phone.name);
                        found_location = strStr(phone.name, name);
                        if (found_location != nullptr) {
                            cout << temp << ": (" << phone.area << ") " << phone.prefix << "-" << phone.number << endl;
                        }
                    
                    }
 
                }
            }
        }
        fclose(file);
		file = nullptr;
    }
}



