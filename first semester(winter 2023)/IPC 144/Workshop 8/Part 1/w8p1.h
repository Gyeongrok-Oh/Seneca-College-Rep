/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Gyeongrok oh
Student ID#: goh3@myseneca.ca
Email      : goh3@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define max_product 3
#define number_of_grams 64

// ----------------------------------------------------------------------------
// structures
 struct CatFoodInfo {
    int sku;
    double prices;
    double lb;
    int calories;
};







// ----------------------------------------------------------------------------
// function prototypes




// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* positive);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePositive);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int a, const int b);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double prices, double lb, int calories);

// 7. Logic entry point
void start();
