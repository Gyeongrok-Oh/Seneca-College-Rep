/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Gyeongrok oh
Student ID#: 119140226
Email      : goh3@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros
#define u_s_lb 2.20462
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

 struct ReportData {
     int product_sku;
     double product_price;
     double product_lb;
     double product_kg;
     int product_g;
     int per_serving_calorie;
     double total_serving;
     double cost_per_serving;
     double per_cost_calorie_serving;
 };
// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
 double convertLbsKg(const double* lbs, double* dblA);

// 9. convert lbs: g
 int convertLbsG(const double* lbs, int* intA);

// 10. convert lbs: kg / g
 void convertLbs(const double* lbs, double* dblA, int* intB);

// 11. calculate: servings based on gPerServ
 double calculateServings(const int serving_size_grams, const int total_grams, double* servings_ptr);

// 12. calculate: cost per serving
 double calculateCostPerServing(const double* product_price, const double* total_servings, double* cost_per_serving);

// 13. calculate: cost per calorie
 double calculateCostPerCal(const double* product_price, const double* cost_per_calorie_serving, double total_serving);


// 14. Derive a reporting detail record based on the cat food product data
 struct ReportData calculateReportData(const struct CatFoodInfo info);

// 15. Display the formatted table header for the analysis results
 void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
 void displayReportData(const struct ReportData report, int is_cheapest);

// 17. Display the findings (cheapest)
 void displayFinalAnalysis(const struct CatFoodInfo cheapest_info);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
