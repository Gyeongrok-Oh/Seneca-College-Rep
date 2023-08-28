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

#include <stdio.h>

int main(void)
{
    const int JAN = 1, DEC = 12, DD = 01;
    int year, month;

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

    int MMM;
    MMM = 65;
    
    if (month == 1)
    {
        printf("Log starting date: %4d-%c%c%c-%02d\n", year, MMM + 9, MMM, MMM + 13, DD);
    }
    else if (month == 2)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 5, MMM + 4, MMM + 1, DD);
    }
    else if (month == 3)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 12, MMM , MMM + 17, DD);
    }
    else if (month == 4)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM , MMM + 15, MMM + 17, DD);
    }
    else if (month == 5)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 12, MMM , MMM + 24, DD);
    }
    else if (month == 6)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 9, MMM + 20, MMM + 13, DD);
    }
    else if (month == 7)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 9, MMM + 20, MMM + 11, DD);
    }
    else if (month == 8)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM, MMM + 20, MMM + 6, DD);
    }
    else if (month == 9)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 18, MMM + 4, MMM + 15, DD);
    }
    else if (month == 10)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 14, MMM + 2, MMM + 19, DD);
    }
    else if (month == 11)
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 13, MMM + 14, MMM + 21, DD);
    }
    else
    {
        printf("Log starting date: %d-%c%c%c-%02d\n", year, MMM + 3, MMM + 4, MMM + 2, DD);
    }

    

    return 0;
}