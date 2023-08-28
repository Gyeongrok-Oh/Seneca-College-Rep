/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
#define minimum_forcast 1
#define maximum_forcast 10
#define cost 100.00


#include <stdio.h>

int main(void)
{
    double monthly_income;
    int wish_items, i = 0;
 
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do 
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthly_income);

        if (monthly_income < 500.00)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (monthly_income > 400000.00)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
        else 
        {
            printf("\n");
        }
    } while (monthly_income < 500.00 || monthly_income > 400000.00);

    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wish_items);

        if (wish_items < minimum_forcast || wish_items > maximum_forcast)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
        else
        {
            printf("\n");
        }
    } while (wish_items < minimum_forcast || wish_items > maximum_forcast);

    int priority[maximum_forcast];
    double items_cost[maximum_forcast];
    char financed[maximum_forcast];

    for ( i = 0; i < wish_items; i++)
    {
        printf("Item-%d Details:\n", i + 1);

        do
        {
            printf("   Item cost: $");
            scanf("%lf", &items_cost[i]);

            if (items_cost[i] < cost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {

            }
        } while (items_cost[i] < cost);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {

            }
        } while (priority[i] < 1 || priority[i] > 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%s", &financed[i]);

            if (!(financed[i] == 'y' || financed[i] == 'n'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else
            {

            }
        } while (!(financed[i] == 'y' || financed[i] == 'n'));
        printf("\n");
    }

        printf("Item Priority Financed        Cost\n");
        printf("---- -------- -------- -----------\n");

        double total = 0;

        for ( i = 0; i < wish_items; i++)
        {
            printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financed[i], items_cost[i]);
            total += items_cost[i];
        }
        printf("---- -------- -------- -----------\n");

        printf("                      $%11.2lf\n\n", total);
        printf("Best of luck in all your future endeavours!\n");



    return 0;
}