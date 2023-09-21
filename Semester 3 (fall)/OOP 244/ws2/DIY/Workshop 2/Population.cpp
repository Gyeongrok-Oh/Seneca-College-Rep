

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
    PostalCode* temp;


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

        for (i = 0; i < numPostal; i++) {
            postalCode[i].code = nullptr;
            postalCode[i].population = 0;
        }

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
        int i = 0, found = 0;
     
        bool value = false;

        if (!openFile(filename) || !load(filename)) {
            cerr << "Could not open data file: PCpopulations<ENDL> or data load is failed " << std::endl;
            return false;
        }
        

        if ((strcmp(partial, "all") == 0)) {
            value = true;
        
        }
        else {
            temp = new PostalCode[numPostal + 1];

            for (i = 0; i < numPostal; i++) {
                temp[i].code = nullptr;
                temp[i].population = 0;
            }

            for (i = 0; i < numPostal; i++) {
                if (startsWith(postalCode[i].code, partial)) {
                    temp[found].code = postalCode[i].code;
                    temp[found].population = postalCode[i].population;
                    found++;
                }
            }

            if (found != 0) {
                
                deallocateMemory();

                postalCode = new PostalCode[found + 1];
                
                for (i = 0; i < found; i++) {
                    postalCode[i].code = temp[i].code;
                    postalCode[i].population = temp[i].population;
                }

            
            }
            else {
                numPostal = 0;
            }
         
            if (temp != nullptr) {
                for (i = 0; i < found; i++) {
                    if (temp[i].code != nullptr) {
               
                        temp[i].code = nullptr;
                        delete[] temp[i].code;
                    }
                }
                temp = nullptr;
                delete[] temp;

                numPostal = found;
            }
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
        for (int i = 0; i < numPostal; i++) {
            postalCode[i].code = nullptr;
            delete[] postalCode[i].code;
        }

        // Lastly, delete the Postalcode pointer which memory was allocated
        delete[] postalCode;
        postalCode = nullptr;
        numPostal = 0;


    }
} // namespace sdds