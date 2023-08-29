#include "mathfuncs.h"

int isLastName(char* last_name) {
    int i, flag = 0;

    // If the input string is NULL, empty, or longer than 20 characters, return 0 or if the user only enter 
    if (last_name == NULL || strlen(last_name) == 0 || strlen(last_name) > 20 || last_name[0] == '\n') {
        return 0;
    }

    // Loop through the input string
    for (i = 0; i < strlen(last_name); i++) {
        // If the i-th element of the input string is not a space
        if (last_name[i] != ' ') {
            // Set the flag to 1
            flag = 1;
            // Break out of the loop
            break;
        }
    }

    // If the flag is 0 (the input string only contains spaces), return 0
    if (flag == 0) {
        return 0;
    }
    // If all the conditions are met, the string is a valid last name
    return 1;
}



int check_postal_code(char* code) {
    // The Canadian postal code must be in the format A1A1A1 or A1A 1A1
    // A is an alphabet, 1 is a number
    // The alphabet can be uppercase or lowercase
    // The space can be present or absent

    // If the length of the input code is not 6 or 7, return 0
    if (strlen(code) != 6 && strlen(code) != 7) {
        return 0;
    }

    // If the length of the input code is 6
    if (strlen(code) == 6) {
        // Check if the first, third, and fifth characters are alphabets
        if (!isalpha(code[0]) || !isalpha(code[2]) || !isalpha(code[4])) {
            return 0;
        }

        // Check if the second, fourth, and sixth characters are numbers
        if (!isdigit(code[1]) || !isdigit(code[3]) || !isdigit(code[5])) {
            return 0;
        }

        // If the third character is a space, return 0 (added part)
        if (code[2] == ' ') {
            return 0;
        }
    }

    // If the length of the input code is 7
    if (strlen(code) == 7) {
        // Check if the first, third, and sixth characters are alphabets
        if (!isalpha(code[0]) || !isalpha(code[2]) || !isalpha(code[5])) {
            return 0;
        }

        // Check if the second, fifth, and seventh characters are numbers
        if (!isdigit(code[1]) || !isdigit(code[4]) || !isdigit(code[6])) {
            return 0;
        }

        // Check if the fourth character is a space
        if (code[3] != ' ') {
            return 0;
        }
    }

    // If all conditions are satisfied, return 1
    return 1;
}




int main() {

    struct customer customer;

    printf("Enter your first name: ");
    fgets(customer.firstName, sizeof(customer.firstName), stdin);
    customer.firstName[strcspn(customer.firstName, "\n")] = '\0';

    printf("Enter your last name: ");
    while (fgets(customer.lastName, sizeof(customer.lastName), stdin)) {
        if (isLastName(customer.lastName) == 1) {
            customer.lastName[strcspn(customer.lastName, "\n")] = '\0';
            break;
        }
        else {
            printf("Invalid Entry: Enter your last name: ");
        }
    }

    printf("Enter your street address: ");
    fgets(customer.streetAddress, sizeof(customer.streetAddress), stdin);
    customer.streetAddress[strcspn(customer.streetAddress, "\n")] = '\0';

    printf("Enter your city: ");
    fgets(customer.city, sizeof(customer.city), stdin);
    customer.city[strcspn(customer.city, "\n")] = '\0';

    printf("Enter your province: ");
    fgets(customer.province, sizeof(customer.province), stdin);
    customer.province[strcspn(customer.province, "\n")] = '\0';

    printf("Enter your postal code: ");
    while (fgets(customer.postalCode, sizeof(customer.postalCode), stdin)) {
        int right = check_postal_code(customer.postalCode);

        if (check_postal_code(customer.postalCode) == 1) {
            customer.postalCode[strcspn(customer.postalCode, "\n")] = '\0';
            break;
        }
        else {
            printf("Invalid Entry: Enter your postal code: ");
        }

    }

    printf("\nYou entered:\n");

    printf("%s %s\n", customer.firstName, customer.lastName);

    printf("%s\n", customer.streetAddress);

    printf("%s %s,\n", customer.city, customer.province);

    customer.postalCode[0] = toupper(customer.postalCode[0]);
    customer.postalCode[2] = toupper(customer.postalCode[2]);

    if (strlen(customer.postalCode) == 6) {
        customer.postalCode[4] = toupper(customer.postalCode[4]);
    }
    else {
        customer.postalCode[5] = toupper(customer.postalCode[5]);
    }
    printf("%s\n", customer.postalCode);

    return 0;
}
