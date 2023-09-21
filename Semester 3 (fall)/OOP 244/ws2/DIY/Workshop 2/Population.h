#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds
{
    struct PostalCode
    {
        char* code;
        int population;
    };

 
    bool startsWith(const char* cString, const char* subString);
    void sort(PostalCode postalCode[], int numPostal);
    bool load(const char filename[]);
    bool load(PostalCode& post);
    void display(const PostalCode& code);
    bool getPostalCode(char* postal_code_prefix);
    bool load(const char* filename, const char* partial_postal_code_prefix);
    void display();
    void deallocateMemory();

} 
#endif 