/*
*****************************************************************************
                          workshop - #4 (p2)
full name  : gyeongrok oh
student id#: 119140226
email      : goh3@myseneca.ca
section    : Ngg

authenticity declaration:
i declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. this submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _crt_secure_no_warnings

#include <stdio.h>

int main(void)
{

    int a_count, o_count, p_count, t_count, c_count, is_one;

    do {
        

        printf("Grocery Shopping\n");
        printf("================\n");

        do {

            printf("How many APPLES do you need? : ");
            scanf("%d", &a_count);

            if (a_count < 0) {

                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (a_count < 0);

        printf("\n");
     

        do {

            printf("How many ORANGES do you need? : ");
            scanf("%d", &o_count);

            if (o_count < 0) {

                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (o_count < 0);

        printf("\n");

        do {

            printf("How many PEARS do you need? : ");
            scanf("%d", &p_count);

            if (p_count < 0) {

                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (p_count < 0);

        printf("\n");

        do {

            printf("How many TOMATOES do you need? : ");
            scanf("%d", &t_count);

            if (t_count < 0) {

                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (t_count < 0);

        printf("\n");

        do {

            printf("How many CABBAGES do you need? : ");
            scanf("%d", &c_count);

            if (c_count < 0) {

                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (c_count < 0);

        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        if (a_count > 0) {

            int a_product;

 
                do {
                    printf("Pick some APPLES... how many did you pick? : ");
                    scanf("%d", &a_product);

                    if (a_product > a_count) {

                        printf("You picked too many... only %d more APPLE(S) are needed.\n", a_count);
                    }
                    else if (a_product < 1) {

                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else {

                        a_count -= a_product;

                        if (a_count == 0) {

                            printf("Great, that's the apples done!\n\n");
                        }
                        else {

                            printf("Looks like we still need some APPLES...\n");
                        }
                    }
                } while (a_count != 0);
            

        }
        else  {

            
        }
        if (o_count > 0) {

            int o_product;

   
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &o_product);

                if (o_product > o_count) {

                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", o_count);
                }
                else if (o_product < 1) {

                    printf("ERROR: You must pick at least 1!\n");
                }
                else {

                    o_count -= o_product;

                    if (o_count == 0) {

                        printf("Great, that's the oranges done!\n\n");
                    }
                    else {

                        printf("Looks like we still need some ORANGES...\n");
                    }
                }
            } while (o_count != 0);


        }
        else  {


        }
        if (p_count > 0) {

            int p_product;

     
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &p_product);

                if (p_product > p_count) {

                    printf("You picked too many... only %d more PEAR(S) are needed.\n", p_count);
                }
                else if (p_product < 1) {

                    printf("ERROR: You must pick at least 1!\n");
                }
                else {

                    p_count -= p_product;

                    if (p_count == 0) {

                        printf("Great, that's the pears done!\n\n");
                    }
                    else {

                        printf("Looks like we still need some PEARS...\n");
                    }
                }
            } while (p_count != 0);


        }
        else  {


        }
        if (t_count > 0) {

            int t_product;

   
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &t_product);

                if (t_product > t_count) {

                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", t_count);
                }
                else if (t_product < 1) {

                    printf("ERROR: You must pick at least 1!\n");
                }
                else {

                    t_count -= t_product;

                    if (t_count == 0) {

                        printf("Great, that's the tomatoes done!\n\n");
                    }
                    else {

                        printf("Looks like we still need some TOMATOES...\n");
                    }
                }
            } while (t_count != 0);


        }
        else  {


        }
        if (c_count > 0) {

            int c_product;


            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &c_product);

                if (c_product > c_count) {

                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", c_count);
                }
                else if (c_product < 1) {

                    printf("ERROR: You must pick at least 1!\n");
                }
                else {

                    c_count -= c_product;

                    if (c_count == 0) {

                        printf("Great, that's the cabbages done!\n\n");
                    }
                    else {

                        printf("Looks like we still need some CABBAGES...\n");
                    }
                }
            } while (c_count != 0);


        }
        else  {

 
        }
        printf("All the items are picked!\n\n");

        printf("Do another shopping? (0=NO): ");
        scanf("%d", &is_one);
        printf("\n");
    } while (is_one == 1);
    
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;

    
}



