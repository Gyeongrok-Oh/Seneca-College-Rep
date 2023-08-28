/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :gyeongrok oh
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

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////
int inputInt() {
    int num;
    char c;
    int result = scanf("%d%c", &num, &c);


    if (result != 2 || c != '\n') {
        printf("Error! Input a whole number: ");
        clearInputBuffer();

        return inputInt();
    }

    return num;
}

int inputIntPositive(void) {
    int received = inputInt();

    while (received < 0) {
        printf("ERROR! Value must be > 0: ");
        scanf("%d", &received);
    }
    return received;
}

int inputIntRange(int lower_bound, int upper_bound) {

    int received = inputInt();
    while (received < lower_bound || received > upper_bound) {
        printf("ERROR! Value must be between %d and %d inclusive: ", lower_bound, upper_bound);
        scanf("%d", &received);
        clearInputBuffer();
    }
    
    return received;
}

char inputCharOption(const char* valid_chars) {
    char c[4];
    int isValid = 0, i;

    while (!isValid) {

        scanf(" %3s", c);
        c[3] = '\0';
        clearInputBuffer();
        for (i = 0; valid_chars[i] != '\0'; i++) {
            if (valid_chars[i] == c[0] && c[1] == '\0') {
                isValid = 1;
                break;
            }
        }
        if (!isValid) {
            printf("ERROR: Character must be one of [%s]: ", valid_chars);

        }
    }

    return c[0];
}





void inputCString(char* st, int min_len, int max_len) {
    int len = 0;

    do {

        scanf(" %[^\n]s", st);
        clearInputBuffer();

        len = 0;
        while (st[len] != '\0') {
            len++;
        }

        if (min_len == max_len) {
            if (len != min_len) {
                printf("ERROR: String length must be exactly %d chars: ", min_len);
            }
        }
        else if (len > max_len) {
            printf("ERROR: String length must be no more than %d chars: ", max_len);
        }
        else if (len < min_len) {
            printf("ERROR: String length must be between %d and %d chars: ", min_len, max_len);
        }
    } while (len < min_len || len > max_len);
}
//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////


void displayFormattedPhone(const char* st) {
    if (st == NULL) {
        printf("(___)___-____");
    }
    else {
        int len = 0, i;
        while (st[len] != '\0') len++;

        if (len != 10) {
            printf("(___)___-____");
        }
        else {
            int valid = 1;
            for (i = 0; i < 10; i++) {
                if (st[i] < '0' || st[i] > '9') {
                    valid = 0;

                }
                else {

                }
            }

            if (valid) {
                printf("(%c%c%c)%c%c%c-%c%c%c%c", st[0], st[1], st[2], st[3], st[4], st[5], st[6], st[7], st[8], st[9]);
            }
            else {
                printf("(___)___-____");
            }
        }
    }
}

