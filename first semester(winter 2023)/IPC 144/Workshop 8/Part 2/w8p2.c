/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
Full Name  : gyeongrok oh
Student ID#: 119140226
Email      : goh3@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

//// System Libraries
#include <stdio.h>

// User Libraries

#include "w8p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* positive) {

    int i, num;

    for (i = 0; i < max_product; i++) {

        scanf("%d", &num);
        if (num <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            i = max_product + 1;
        }
    }

    if (positive) {
        *positive = num;
    }

    return num;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePositive) {

    int i;
    double num;

    for (i = 0; i < max_product; i++) {

        scanf("%lf", &num);
        if (num <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            i = max_product + 1;
        }
    }

    if (doublePositive) {
        *doublePositive = num;
    }

    return num;
}



// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int a, const int b) {

    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n"
           "NOTE: A 'serving' is %dg\n", a, b);
    printf("\n");
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum) {

    struct CatFoodInfo info;
    info.sku = 0;

    printf("Cat Food Product #%d\n", sequenceNum);
    printf("--------------------\n");

    printf("SKU           : ");
    getIntPositive(&info.sku);

    printf("PRICE         : $");
    getDoublePositive(&info.prices);

    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&info.lb);

    printf("CALORIES/SERV.: ");
    getIntPositive(&info.calories);

    return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");

}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double prices, double lb, int calories) {
    
    printf("%07d %10.2lf %10.1lf %8d\n", sku, prices, lb, calories);
}





// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* dblA) {

    double converted;

    converted = (*lbs) / u_s_lb;

    if (dblA != NULL) {
        *dblA = converted;
    }
    return converted;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* intA) {

    int converted = (int)(convertLbsKg(lbs, NULL) * 1000);

    if (intA != NULL) {
        *intA = converted;
    }

    return converted;
}


// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* dblA, int* intB) {

    convertLbsKg(lbs, dblA);
    convertLbsG(lbs, intB);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int serving_size_grams, const int total_grams, double* servings_ptr) {
    double total_servings = (double)(total_grams) / serving_size_grams;

    if (servings_ptr != NULL) {
        *servings_ptr = total_servings;
    }
    return total_servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* product_price, const double* total_servings, double* cost_per_serving) {
    double cost_per_serving_value = *product_price / *total_servings;

    if (cost_per_serving != NULL) {
        *cost_per_serving = cost_per_serving_value;
    }

    return cost_per_serving_value;
}
// 13. calculate: cost per calorie
double calculateCostPerCal(const double* product_price, const double* cost_per_calorie_serving, double total_serving) {
    double result = *product_price / total_serving;

    if (cost_per_calorie_serving != NULL) {
        total_serving = result;
    }
    return result;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo info) {

    struct ReportData report;

    report.product_sku = info.sku;
    report.product_price = info.prices;
    report.product_lb = info.lb;
    report.per_serving_calorie = info.calories;
    convertLbsKg(&info.lb, &report.product_kg);
    convertLbsG(&info.lb, &report.product_g);
    calculateServings(number_of_grams, report.product_g, &report.total_serving);
    calculateCostPerServing(&info.prices, &report.total_serving, &report.cost_per_serving);
    double divided = info.prices / info.calories;
    report.per_cost_calorie_serving = calculateCostPerCal(&divided, &report.per_cost_calorie_serving, report.total_serving);
 
    return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", number_of_grams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, int is_cheapest) {

    if (is_cheapest) {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n",
            report.product_sku, report.product_price, report.product_lb, report.product_kg, report.product_g, report.per_serving_calorie, report.total_serving, report.cost_per_serving, report.per_cost_calorie_serving);
    }
    else {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n",
            report.product_sku, report.product_price, report.product_lb, report.product_kg, report.product_g, report.per_serving_calorie, report.total_serving, report.cost_per_serving, report.per_cost_calorie_serving);

    }
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest_info) {

    printf("\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%.7d Price: $%.2lf\n\n", cheapest_info.sku, cheapest_info.prices);
    printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    //part1
    int i;
    struct CatFoodInfo catFoodInfo[max_product];
    int cheapest[max_product];

    openingMessage(max_product, number_of_grams);

    for (i = 0; i < max_product; i++) {
        catFoodInfo[i] = getCatFoodInfo(i + 1);
        printf("\n");
    }

    displayCatFoodHeader();

    for (i = 0; i < max_product; i++) {
        displayCatFoodData(catFoodInfo[i].sku, catFoodInfo[i].prices, catFoodInfo[i].lb, catFoodInfo[i].calories);
    }

    //part 2





    struct ReportData report[max_product];


    for (i = 0; i < max_product; i++) {

        report[i] = calculateReportData(catFoodInfo[i]);
    }

    displayReportHeader();

    for (i = 1; i < max_product; i++) {
        
        if ((report[i - 1].product_price / report[i - 1].cost_per_serving) > (report[i].product_price / report[i].cost_per_serving)) {
            cheapest[i - 1] = 1;
            cheapest[i] = 0;
        }

        else{
            cheapest[i - 1] = 0;
            cheapest[i] = 1;
        }
    }
 
    for (i = 0; i < max_product; i++) {
        displayReportData(report[i], cheapest[i]);
    }

    for (i = 0; i < max_product; i++) {
        if (cheapest[i] == 1) {
            displayFinalAnalysis(catFoodInfo[i]);
        }
        else {

        }
    }


    
}



















