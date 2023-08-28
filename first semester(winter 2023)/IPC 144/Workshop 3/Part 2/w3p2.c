/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Gyeongrok oh
Student ID#: 119140226
Email      : goh3@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char one_product_type;
    int one_product_weight;
    char one_product_cream;
    char two_product_type;
    int two_product_weight;
    char two_product_cream;
    char three_product_type;
    int three_product_weight;
    char three_product_cream;
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c", &one_product_type);
    printf("Bag weight (g): ");
    scanf("%d%*c", &one_product_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &one_product_cream);


    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &two_product_type);
    printf("Bag weight (g): ");
    scanf("%d%*c", &two_product_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &two_product_cream);


    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c%*c", &three_product_type);
    printf("Bag weight (g): ");
    scanf("%d%*c", &three_product_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &three_product_cream);
    printf("\n");

    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", one_product_type == 'l' || one_product_type == 'L', one_product_type == 'm' || one_product_type == 'M', one_product_type == 'r' || one_product_type == 'R', one_product_weight, one_product_weight / GRAMS_IN_LBS, one_product_cream == 'y' || one_product_cream == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", two_product_type == 'l' || two_product_type == 'L', two_product_type == 'm' || two_product_type == 'M', two_product_type == 'r' || two_product_type == 'R', two_product_weight, two_product_weight / GRAMS_IN_LBS, two_product_cream == 'y' || two_product_cream == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", three_product_type == 'l' || three_product_type == 'L', three_product_type == 'm' || three_product_type == 'M', three_product_type == 'r' || three_product_type == 'R', three_product_weight, three_product_weight / GRAMS_IN_LBS, three_product_cream == 'y' || two_product_cream == 'Y');
    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
    char coffeeS, prefer_cream;
    int daily_serving;
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf("%c%*c", &coffeeS);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &prefer_cream);
    printf("Typical number of daily servings: ");
    scanf("%d%*c", &daily_serving);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeeS == 'l' && one_product_type == 'l' ) || (coffeeS == 'l' && one_product_type == 'L') || (coffeeS == 'L' && one_product_type == 'l') || (coffeeS == 'L' && one_product_type == 'L') || (coffeeS == 'm' && one_product_type == 'm') || (coffeeS == 'm' && one_product_type == 'M') || (coffeeS == 'M' && one_product_type == 'm') || (coffeeS == 'M' && one_product_type == 'M') || (coffeeS == 'r' && one_product_type == 'r') || (coffeeS == 'r' && one_product_type == 'R') || (coffeeS == 'R' && one_product_type == 'r') || (coffeeS == 'R' && one_product_type == 'R')), ((daily_serving > 0 && daily_serving < 5) && one_product_weight == 250) || ((daily_serving > 4 && daily_serving < 10) && one_product_weight == 500) || ((daily_serving > 10) && one_product_weight == 1000), (prefer_cream == 'Y' && one_product_cream == 'Y') || (prefer_cream == 'y' && one_product_cream == 'Y') || (prefer_cream == 'Y' && one_product_cream == 'y') || (prefer_cream == 'y' && one_product_cream == 'y') || (prefer_cream == 'n' && one_product_cream == 'n') || (prefer_cream == 'N' && one_product_cream == 'N') || (prefer_cream == 'n' && one_product_cream == 'N') || (prefer_cream == 'N' && one_product_cream == 'n'));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeeS == 'l' && two_product_type == 'l') || (coffeeS == 'l' && two_product_type == 'L') || (coffeeS == 'L' && two_product_type == 'l') || (coffeeS == 'L' && two_product_type == 'L') || (coffeeS == 'm' && two_product_type == 'm') || (coffeeS == 'm' && two_product_type == 'M') || (coffeeS == 'M' && two_product_type == 'm') || (coffeeS == 'M' && two_product_type == 'M') || (coffeeS == 'r' && two_product_type == 'r') || (coffeeS == 'r' && two_product_type == 'R') || (coffeeS == 'R' && two_product_type == 'r') || (coffeeS == 'R' && two_product_type == 'R')), ((daily_serving > 0 && daily_serving < 5) && two_product_weight == 250) || ((daily_serving > 4 && daily_serving < 10) && two_product_weight == 500) || ((daily_serving > 10) && two_product_weight == 1000), (prefer_cream == 'Y' && two_product_cream == 'Y') || (prefer_cream == 'y' && two_product_cream == 'Y') || (prefer_cream == 'Y' && two_product_cream == 'y') || (prefer_cream == 'y' && two_product_cream == 'y') || (prefer_cream == 'n' && two_product_cream == 'n') || (prefer_cream == 'N' && two_product_cream == 'N') || (prefer_cream == 'n' && two_product_cream == 'N') || (prefer_cream == 'N' && two_product_cream == 'n'));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((coffeeS == 'l' && three_product_type == 'l') || (coffeeS == 'l' && three_product_type == 'L') || (coffeeS == 'L' && three_product_type == 'l') || (coffeeS == 'L' && three_product_type == 'L') || (coffeeS == 'm' && three_product_type == 'm') || (coffeeS == 'm' && three_product_type == 'M') || (coffeeS == 'M' && three_product_type == 'm') || (coffeeS == 'M' && three_product_type == 'M') || (coffeeS == 'r' && three_product_type == 'r') || (coffeeS == 'r' && three_product_type == 'R') || (coffeeS == 'R' && three_product_type == 'r') || (coffeeS == 'R' && three_product_type == 'R')), ((daily_serving > 0 && daily_serving < 5) && three_product_weight == 250) || ((daily_serving > 4 && daily_serving < 10) && three_product_weight == 500) || ((daily_serving > 10) && three_product_weight == 1000), (prefer_cream == 'Y' && three_product_cream == 'Y') || (prefer_cream == 'y' && three_product_cream == 'Y') || (prefer_cream == 'Y' && three_product_cream == 'y') || (prefer_cream == 'y' && three_product_cream == 'y') || (prefer_cream == 'n' && three_product_cream == 'n') || (prefer_cream == 'N' && three_product_cream == 'N') || (prefer_cream == 'n' && three_product_cream == 'N') || (prefer_cream == 'N' && three_product_cream == 'n'));
    
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf("%c%*c", &coffeeS);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf("%c%*c", &prefer_cream);
    printf("Typical number of daily servings: ");
    scanf("%d%*c", &daily_serving);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n", ((coffeeS == 'l' && one_product_type == 'l') || (coffeeS == 'l' && one_product_type == 'L') || (coffeeS == 'L' && one_product_type == 'l') || (coffeeS == 'L' && one_product_type == 'L') || (coffeeS == 'm' && one_product_type == 'm') || (coffeeS == 'm' && one_product_type == 'M') || (coffeeS == 'M' && one_product_type == 'm') || (coffeeS == 'M' && one_product_type == 'M') || (coffeeS == 'r' && one_product_type == 'r') || (coffeeS == 'r' && one_product_type == 'R') || (coffeeS == 'R' && one_product_type == 'r') || (coffeeS == 'R' && one_product_type == 'R')), ((daily_serving > 0 && daily_serving < 5) && one_product_weight == 250) || ((daily_serving > 4 && daily_serving < 10) && one_product_weight == 500) || ((daily_serving > 10) && one_product_weight == 1000), (prefer_cream == 'Y' && one_product_cream == 'Y') || (prefer_cream == 'y' && one_product_cream == 'Y') || (prefer_cream == 'Y' && one_product_cream == 'y') || (prefer_cream == 'y' && one_product_cream == 'y') || (prefer_cream == 'n' && one_product_cream == 'n') || (prefer_cream == 'N' && one_product_cream == 'N') || (prefer_cream == 'n' && one_product_cream == 'N') || (prefer_cream == 'N' && one_product_cream == 'n'));
    printf(" 2|       %d         |      %d      |   %d   |\n", ((coffeeS == 'l' && two_product_type == 'l') || (coffeeS == 'l' && two_product_type == 'L') || (coffeeS == 'L' && two_product_type == 'l') || (coffeeS == 'L' && two_product_type == 'L') || (coffeeS == 'm' && two_product_type == 'm') || (coffeeS == 'm' && two_product_type == 'M') || (coffeeS == 'M' && two_product_type == 'm') || (coffeeS == 'M' && two_product_type == 'M') || (coffeeS == 'r' && two_product_type == 'r') || (coffeeS == 'r' && two_product_type == 'R') || (coffeeS == 'R' && two_product_type == 'r') || (coffeeS == 'R' && two_product_type == 'R')), ((daily_serving > 0 && daily_serving < 5) && two_product_weight == 250) || ((daily_serving > 4 && daily_serving < 10) && two_product_weight == 500) || ((daily_serving > 10) && two_product_weight == 1000), (prefer_cream == 'Y' && two_product_cream == 'Y') || (prefer_cream == 'y' && two_product_cream == 'Y') || (prefer_cream == 'Y' && two_product_cream == 'y') || (prefer_cream == 'y' && two_product_cream == 'y') || (prefer_cream == 'n' && two_product_cream == 'n') || (prefer_cream == 'N' && two_product_cream == 'N') || (prefer_cream == 'n' && two_product_cream == 'N') || (prefer_cream == 'N' && two_product_cream == 'n'));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", ((coffeeS == 'l' && three_product_type == 'l') || (coffeeS == 'l' && three_product_type == 'L') || (coffeeS == 'L' && three_product_type == 'l') || (coffeeS == 'L' && three_product_type == 'L') || (coffeeS == 'm' && three_product_type == 'm') || (coffeeS == 'm' && three_product_type == 'M') || (coffeeS == 'M' && three_product_type == 'm') || (coffeeS == 'M' && three_product_type == 'M') || (coffeeS == 'r' && three_product_type == 'r') || (coffeeS == 'r' && three_product_type == 'R') || (coffeeS == 'R' && three_product_type == 'r') || (coffeeS == 'R' && three_product_type == 'R')), ((daily_serving > 0 && daily_serving < 5) && three_product_weight == 250) || ((daily_serving > 4 && daily_serving < 10) && three_product_weight == 500) || ((daily_serving > 10) && three_product_weight == 1000), (prefer_cream == 'Y' && three_product_cream == 'Y') || (prefer_cream == 'y' && three_product_cream == 'Y') || (prefer_cream == 'Y' && three_product_cream == 'y') || (prefer_cream == 'y' && three_product_cream == 'y') || (prefer_cream == 'n' && three_product_cream == 'n') || (prefer_cream == 'N' && three_product_cream == 'N') || (prefer_cream == 'n' && three_product_cream == 'N') || (prefer_cream == 'N' && three_product_cream == 'n'));

    printf("Hope you found a product that suits your likes!\n");

        return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/