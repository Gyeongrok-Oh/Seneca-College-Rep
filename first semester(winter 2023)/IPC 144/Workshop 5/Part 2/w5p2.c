/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
#include <stdio.h>

int main(void)
{
    const int JAN = 1, DEC = 12;
    double morning, evening, sum_morning, sum_evening;
    int year, month, MMM;

    sum_morning = 0;
    sum_evening = 0;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year < MIN_YEAR || year > MAX_YEAR) && (month < JAN || month > DEC))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else
        {
            printf("\n");
        }
    } while ((year < MIN_YEAR || year > MAX_YEAR) || (month < JAN || month > DEC));

    printf("*** Log date set! ***\n\n");

    int DD = 1;
    for ( DD = 1; DD <= LOG_DAYS; DD++)
    {
        MMM = 65;

        if (month == 1)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 9, MMM, MMM + 13, DD);
        }

        else if (month == 2)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 5, MMM + 4, MMM + 1, DD);
        }
        else if (month == 3)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 12, MMM, MMM + 17, DD);            
        }
        else if (month == 4)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM, MMM + 15, MMM + 17, DD);
        }
        else if (month == 5)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 12, MMM, MMM + 24, DD);                
        }
        else if (month == 6)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 9, MMM + 20, MMM + 13, DD);
        }
        else if (month == 7)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 9, MMM + 20, MMM + 11, DD);              
        }
        else if (month == 8)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM, MMM + 20, MMM + 6, DD);
        }
        else if (month == 9)
        {
            printf("Log starting date: %4d-%c%c%c-%02d\n", year, MMM + 18, MMM + 4, MMM + 15, DD);
        }
        else if (month == 10)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 14, MMM + 2, MMM + 19, DD);
        }
        else if (month == 11)
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 13, MMM + 14, MMM + 21, DD);
        }
        else
        {
            printf("%4d-%c%c%c-%02d\n", year, MMM + 3, MMM + 4, MMM + 2, DD);
        }

        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morning);

            if (morning < 0.0 || morning > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                sum_morning += morning;
            }
        } while (morning < 0.0 || morning > 5.0);

        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening);

            if (evening < 0.0 || evening > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                sum_evening += evening;
            }
        } while (evening < 0.0 || evening > 5.0);
        printf("\n");
    }


    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", sum_morning);
    printf("Evening total rating:  %.3lf\n", sum_evening);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", sum_morning + sum_evening);

    printf("Average morning rating:  %.1lf\n", sum_morning / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", sum_evening / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", ((sum_morning / LOG_DAYS) + (sum_evening / LOG_DAYS)) / 2);

    
    return 0;
}