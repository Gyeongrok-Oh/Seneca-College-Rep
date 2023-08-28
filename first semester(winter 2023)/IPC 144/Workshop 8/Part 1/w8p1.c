/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
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



// System Libraries
#include <stdio.h>

// User Libraries

#include "w8p1.h"

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


// 7. Logic entry point

void start() {

    int i;
    struct CatFoodInfo catFoodInfo[max_product];

    openingMessage(max_product, number_of_grams);

    for (i = 0; i < max_product; i++) {
        catFoodInfo[i] = getCatFoodInfo(i + 1);
        printf("\n");
    }

    displayCatFoodHeader();

    for (i = 0; i < max_product; i++) {
        displayCatFoodData(catFoodInfo[i].sku, catFoodInfo[i].prices, catFoodInfo[i].lb, catFoodInfo[i].calories);
    }
 

}

