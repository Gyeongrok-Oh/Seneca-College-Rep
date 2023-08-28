/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  :gyeongrok oh
Student ID#:119140226
Email      :goh3@myseneca.ca
Section    :NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int cycle;
    int i;
    char user_word;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do {

        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &user_word, &cycle);


        if ( user_word == 'W' && (cycle > 2 && cycle < 21)) {
            printf("WHILE   : ");

            i = 0;
            while (i < cycle) {
                printf("%c", user_word);

                i++;
            };
            printf("\n\n");
        }
        else if (user_word == 'D' && (cycle > 2 && cycle < 21)) {
            printf("DO-WHILE: ");

            i = 0;
            do {
                i++;
                printf("%c", user_word);
                
                
            } while (i < cycle);
            printf("\n\n");
        }
        else if (user_word == 'F' && (cycle > 2 && cycle < 21)) {
            printf("FOR     : ");
            
            for (i = 0; i < cycle; i++) {
                printf("%c", user_word);
            }
            printf("\n\n");
        }
        else if (user_word == 'Q' && (cycle > 0 || cycle < 0))  {

            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }

        
        else if ((user_word == 'D' || user_word == 'W' || user_word == 'F') && (cycle < 3 || cycle > 20)) {

            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }
        else if (!(user_word == 'D' || user_word == 'W' || user_word == 'F') && !(user_word == 'Q' && cycle == 0) ){

            printf("ERROR: Invalid entered value(s)!\n\n");
        }
    
    } while (!(user_word == 'Q' && cycle == 0));

        
    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
        
        
        
        
     
        
 
 
 
    

    






        return 0;
    }
