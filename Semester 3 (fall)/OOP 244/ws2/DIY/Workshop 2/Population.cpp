

#include <iostream>
#include "Population.h"
#include "File.h"
#include <cstring> // added 

using namespace std;

namespace sdds
{
    // Global variables:
    int numPostal;
    PostalCode* postalCode;


    void init(PostalCode code[], const int cycle) {
        for (int i = 0; i < cycle; i++) {
            code[i].code = nullptr;
            code[i].population = 0;
        }
    }

    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }

    void sort(PostalCode postalCode[], int numPostal)
    {
        int i{}, j{};
        PostalCode key;

        for (i = 1; i < numPostal; i++) {
            key = postalCode[i];

            for (j = i - 1; j >= 0 && postalCode[j].population > key.population; j--) {
                postalCode[j + 1] = postalCode[j];
            }

            postalCode[j + 1] = key;
        }


    }


    
    bool load(PostalCode& post)
    {
        bool ok = false;

        if (read(post.code) && read(post.population)) {

            ok = true;
        }

        return ok;
    }

    bool load(const char filename[])
    {
        bool check = true;
        int i{};
        numPostal = noOfRecords();

        postalCode = new PostalCode[numPostal + 1];

        init(postalCode, numPostal + 1);
 
        for (i = 0; i < numPostal && check; i++) {
            if (!load(postalCode[i])) {
                check = false;
            }
        }

        check = (i == numPostal);

        if (!check) {
            cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
        }

        

        return check;
    }

    void display(const PostalCode& code)
    {
        cout << code.code << ":  " << code.population << endl;
    }

    bool getPostalCode(char* postal_code_prefix) {
        bool is_end = true;

        cout << "Population Report" << endl;
        cout << "-----------------" << endl;
        cout << "Enter postal code:" << endl << "> ";
        cin >> postal_code_prefix;

        // Check for the exit condition
        if (strcmp(postal_code_prefix, "!") == 0) {
            is_end = false;
        }

        return is_end;
    }

    bool load(const char* filename, const char* partial) {
        int found = 0;
        bool value = false;

        if (!openFile(filename) || !load(filename)) {
            cerr << "Could not open data file or data load failed." << endl;
            return false;
        }

        if (strcmp(partial, "all") == 0) {
            value = true;
        }
        else {
            PostalCode* temp = new PostalCode[numPostal + 1];

            init(temp, numPostal + 1);

            // Copy matching entries to temp
            for (int i = 0; i < numPostal; i++) {
                if (startsWith(postalCode[i].code, partial)) {
                    temp[found].code = new char[strlen(postalCode[i].code) + 1];
                    strcpy(temp[found].code, postalCode[i].code);
                    temp[found].population = postalCode[i].population;

                    found++;
                }
            }

            // Deallocate old memory
            deallocateMemory();

            // Allocate new memory for postalCode
            postalCode = new PostalCode[found + 1];
 
            init(postalCode, found + 1);

            // Copy data from temp to postalCode
            for (int i = 0; i < found; i++) {
                postalCode[i].code = new char[strlen(temp[i].code) + 1];
                strcpy(postalCode[i].code, temp[i].code);
                postalCode[i].population = temp[i].population;
            }

            // Deallocate temp memory
            for (int i = 0; i < numPostal + 1; i++) {
                delete[] temp[i].code;
                temp[i].code = nullptr;
                
            }
            delete[] temp;
            temp = nullptr;
            numPostal = found;
            value = true;
        }

        closeFile();
        return value;
    }

    void display() {
        int i = 0, totalPop = 0;
        
        cout << "Postal Code: " << "population" << endl;
        cout << "-------------------------" << endl;
        
        
        sort(postalCode, numPostal);

        
        for (; i < numPostal; i++) {
            cout << i + 1 << "- ";
            display(postalCode[i]);
            totalPop += postalCode[i].population;
        }
        

        cout << "-------------------------" << endl;
        cout << "Population of the listed areas: " << totalPop << endl << endl;;
    }


    void deallocateMemory()
    {

        if (postalCode != nullptr) {
            for (int i = 0; i < numPostal; i++) {
                delete[] postalCode[i].code;
                postalCode[i].code = nullptr;
            }

            delete[] postalCode;
            postalCode = nullptr;
        }
    }
} // namespace sdds