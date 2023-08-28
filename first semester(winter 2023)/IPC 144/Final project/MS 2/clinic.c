/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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

#include <stdio.h>
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);

    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i, found = 0;

    if (fmt == FMT_TABLE) {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            found = 1;
        }
    }

    if (found == 0) {
        printf("\n\n*** No records found ***\n");
    }

    putchar('\n');
}








// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {
    int select = 0;
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        select = inputIntRange(0, 2);

        if (select == 1) {
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();
        }
        else if (select == 2) {
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();
        }
        else {
            putchar('\n');
        }
    } while (select != 0);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {
    int found = -1, new_stored, i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == 0) {
            found = i;
            i += max + 1;
        }
    }
    if (found == -1) {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
        new_stored = nextPatientNumber(patient, max);
        patient[found].patientNumber = new_stored;
        inputPatient(&patient[found]);
        printf("*** New patient record added ***\n\n");
    }

}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {
    int edit_num;
    printf("Enter the patient number: ");
    edit_num = inputIntPositive();
    putchar('\n');

    edit_num = findPatientIndexByPatientNum(edit_num, patient, max);
    if (edit_num != -1) {
        menuPatientEdit(&patient[edit_num]);
        
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
        suspend();
        putchar('\n');
    }
    
    
    
}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    int patientNum, index;
    char confirm;
    printf("Enter the patient number: ");
    patientNum = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNum, patient, max);
    putchar('\n');
    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        confirm = inputCharOption("yn");
        if (confirm == 'y') {
            patient[index].patientNumber = 0;
            strcpy(patient[index].name, "");
            strcpy(patient[index].phone.description, "");
            printf("Patient record has been removed!\n\n");
        }
        else {
            printf("Operation aborted.\n\n");
        }
    }
    
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int search, i, found = 0;
    printf("\nSearch by patient number: ");
    search = inputIntPositive();
    putchar('\n');
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == search) {

            displayPatientData(&patient[i], FMT_FORM);
            found = 1;
        }
    }
    if (found == 0) {
        printf("*** No records found ***\n");
    }
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int i, found = 0;
    char phoneNumber[PHONE_LEN + 1];
    printf("\nSearch by phone number: ");
    inputCString(phoneNumber, 0, PHONE_LEN);

    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            found = 1;
        }
    }
    if (found == 0) {
        printf("\n*** No records found ***\n");
    }
}



// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
    int max_num = 0, i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > max_num) {
            max_num = patient[i].patientNumber;
        }
    }

    return max_num + 1;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i, found = -1;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            found = i;
        }
    }

    return found;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 0, NAME_LEN);
    putchar('\n');
    inputPhoneData(&(patient->phone));
    putchar('\n');
}




// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone* phone) {
    int select = 0;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    select = inputIntRange(0, 4);
 
    if (select == 1) {
        strcpy(phone->description, "CELL");
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 0, PHONE_LEN);
        putchar('\n');
    }
    else if (select == 2) {
        strcpy(phone->description, "HOME");
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 0, PHONE_LEN);
 
    }
    else if (select == 3) {
        strcpy(phone->description, "WORK");
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 0, PHONE_LEN);
        putchar('\n');
    }
    else {
        strcpy(phone->description, "TBD");
    }

}
