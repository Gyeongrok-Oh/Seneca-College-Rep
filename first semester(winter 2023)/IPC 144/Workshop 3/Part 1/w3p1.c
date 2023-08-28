
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Gyeongrok oh
Student ID#: 119140226
Email      : goh3@myseneca.ca
Section    : NGG
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int product_1_id = 111;
    const int product_2_id = 222;
    const int product_3_id = 111;
    const double product_1_price = 111.49;
    const double product_2_price = 222.99;
    const double product_3_price = 334.49;
    const char product_1_taxed = 'Y';
    const char product_2_taxed = 'N';
    const char product_3_taxed = 'N';

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", product_1_id);
    printf("  Taxed: %c\n", product_1_taxed);
    printf("  Price: $%.4lf\n\n", product_1_price);

    printf("Product-2 (ID:%d)\n", product_2_id);
    printf("  Taxed: %c\n", product_2_taxed);
    printf("  Price: $%.4lf\n\n", product_2_price);

    printf("Product-3 (ID:%d)\n", product_3_id);
    printf("  Taxed: %c\n", product_3_taxed);
    printf("  Price: $%.4lf\n\n", product_3_price);

    printf("The average of all prices is: $%.4lf\n\n", (product_1_price + product_2_price + product_3_price) / 3);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n",!!product_1_taxed);
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", !(!product_2_taxed && !product_3_taxed));

    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, product_3_price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", product_3_price >= product_1_price + product_2_price);
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", product_1_price >= product_3_price - product_2_price, product_3_price - product_2_price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", product_2_price >= (product_1_price + product_2_price + product_3_price) / 3);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", product_1_id == (product_3_id || product_2_id));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", product_2_id != (product_3_id || product_1_id));
    printf("9. Based on product ID, product 3 is unique -> %d\n", product_3_id == (product_2_id || product_1_id));




    return 0;
}