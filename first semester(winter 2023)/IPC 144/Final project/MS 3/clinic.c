/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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
            printf("\nPatient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
    int found = -1, new_stored;
    found = findPatientIndexByPatientNum(0, patient, max);
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



void sort(struct Appointment* appointments, int max_appointment) {
    int i, j;

    for (i = 0; i < allRecords + max_appointment; i++) {
        for (j = 0; j < (allRecords + max_appointment) - i - 1; j++) {
            if (appointments[j].date.year != 0) {
                if (appointments[j].date.year > appointments[j + 1].date.year ||
                    (appointments[j].date.year == appointments[j + 1].date.year &&
                        appointments[j].date.month > appointments[j + 1].date.month) ||
                    (appointments[j].date.year == appointments[j + 1].date.year &&
                        appointments[j].date.month == appointments[j + 1].date.month &&
                        appointments[j].date.day > appointments[j + 1].date.day) ||
                    (appointments[j].date.year == appointments[j + 1].date.year &&
                        appointments[j].date.month == appointments[j + 1].date.month &&
                        appointments[j].date.day == appointments[j + 1].date.day &&
                        appointments[j].time.hour > appointments[j + 1].time.hour) ||
                    (appointments[j].date.year == appointments[j + 1].date.year &&
                        appointments[j].date.month == appointments[j + 1].date.month &&
                        appointments[j].date.day == appointments[j + 1].date.day &&
                        appointments[j].time.hour == appointments[j + 1].time.hour &&
                        appointments[j].time.min > appointments[j + 1].time.min)) {

                    struct Appointment temp = appointments[j];
                    appointments[j] = appointments[j + 1];
                    appointments[j + 1] = temp;
                }
            }
        }
    }
}
// View ALL scheduled appointments
// Todo:
 
void viewAllAppointments(const struct ClinicData* data) {

    int i, j;
    displayScheduleTableHeader(NULL, 1);
    
    for (i = 0; i <= allRecords; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                j = data->maxPatient;
            }
        }     
    }
    putchar('\n');
}

void isLeap(int* year, int* month, int* day) {
    int maxDay;

    printf("Year        : ");
    *year = inputInt();

    printf("Month (1-12): ");
    *month = inputIntRange(1, 12);

    switch (*month) {
    case 2:
        if ((*year % 4 == 0) && ((*year % 100 != 0) || (*year % 400 == 0))){

            maxDay = 29;
            
        }
        else {
            maxDay = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDay = 30;
        break;
    default:
        maxDay = 31;
        break;
    }

    printf("Day (1-%d)  : ", maxDay);
    *day = inputIntRange(1, maxDay);

}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(const struct ClinicData* data) {
    int year, month, day, i, j;
    isLeap(&year, &month, &day);
    putchar('\n');
    for (i = 0; i < data->maxAppointments; i++) {
        if ((data->appointments[i].date.year == year) && (data->appointments[i].date.month == month) && (data->appointments[i].date.day == day)) {
            displayScheduleTableHeader(&data->appointments[i].date, 0);
            i = data->maxAppointments;
        }
    }

    for (i = 0; i < data->maxPatient && (data->appointments[i].patientNumber != 0); i++) {
        for (j = 0; j < data->maxAppointments && j < allRecords; j++) {
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                if (data->appointments[i].date.year == year && data->appointments[i].date.month == month && data->appointments[i].date.day == day)
                displayScheduleData(&data->patients[j], &data->appointments[i], 0);
            }
        }
    }

    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
int findAppointIndexByPatientNum(int patientNumber, const struct Appointment appointment[], int max) {
    int i, found = -1;
    for (i = 0; i < max; i++) {
        if (appointment[i].patientNumber == patientNumber) {
            found = i;
            i = max;
        }
    }

    return found;
}

void addAppointment(struct Appointment appointments[], int appointment_max, struct Patient patients[], int patient_max) {

    int patientNum, year, month, day, hour, minute, patientIndex = 0, i, is_error = 0;

    printf("Patient Number: ");
    patientNum = inputInt();
    patientIndex = findAppointIndexByPatientNum(patientNum, appointments, appointment_max);

    if (patientIndex != -1) {
        printf("ERROR: Appointment listing is full or duplicated\n");
        return;
    }

    do {
 
        if (is_error == 0 || is_error == 2) {
            isLeap(&year, &month, &day); 
            
        }
        is_error = 0;

        printf("Hour (0-23)  : ");
        hour = inputIntRange(0, 23);
        printf("Minute (0-59): ");
        minute = inputIntRange(0, 59);

        // Check appointment time validity
        if (hour < startHour || hour > endHour || (hour == endHour && minute != 0) || minute % appointmentInterval != 0) {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", startHour, endHour, appointmentInterval);
            is_error = 1;
        }
        else {
            for (i = 0; i < appointment_max; i++) {
                if (appointments[i].date.year == year && appointments[i].date.month == month && appointments[i].date.day == day
                    && appointments[i].time.hour == hour && appointments[i].time.min == minute) {
                    printf("\nERROR: Appointment timeslot is not available!\n\n");
                    is_error = 2;
                    i = appointment_max;
                }
            }
        }
    } while (is_error == 1 || is_error == 2);

    // Find patient index in the patients array

    for (i = 0; i < appointment_max; i++) {
        if (appointments[i].patientNumber == 0) {
            appointments[i].patientNumber = patientNum;
            appointments[i].date.year = year;
            appointments[i].date.month = month;
            appointments[i].date.day = day;
            appointments[i].time.hour = hour;
            appointments[i].time.min = minute;
            patientIndex = i;
            i = appointment_max;
        }
    }
    sort(appointments, 1);
    printf("\n*** Appointment scheduled! ***\n\n");

}
    



// Remove an appointment record from the appointment array
// Todo:

void removeAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatients) {
    int patientNum, index, year, month, day, i, found = 0;
    char confirm;
  
    printf("Patient Number: ");
    patientNum = inputIntPositive();
    index = findAppointIndexByPatientNum(patientNum, appointments, maxAppointments);
    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        isLeap(&year, &month, &day);
        appointments->date.year = year;
        appointments->date.month = month;
        appointments->date.day = day;
        putchar('\n');
        found = findPatientIndexByPatientNum(patientNum, patients, maxPatients);
        displayPatientData(&patients[found], 1);
        printf("Are you sure you want to remove this appointment (y,n): ");
        confirm = inputCharOption("yn");
        if (confirm == 'y') {
            if (index >= 0 && index < maxAppointments) {
                for (i = 0; i < maxAppointments; i++) {
                    if (appointments[i].patientNumber == patientNum) {
                        if (appointments[i].date.year == year) {
                            if (appointments[i].date.month) {
                                if (appointments[i].date.day == day) {
                                    appointments[i].patientNumber = 0;
                                    appointments[i].date.year = 0;
                                    appointments[i].date.month = 0;
                                    appointments[i].date.day = 0;
                                    appointments[i].time.hour = 0;
                                    appointments[i].time.min = 0;
                                    i = maxAppointments;
                                }
                            }
                        }
                    }
                }
                printf("\nAppointment record has been removed!\n\n");
            }
            else {
                    printf("ERROR: Appointment record not found!\n");
            }
        }
        else {
            printf("Operation aborted.\n");
        }     
    }
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i, found = -1;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            found = i;
            i = max;
        }
    }

    return found;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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

    if (select == 4) {
        strcpy(phone->description, "TBD");
    }
    else {
        if (select == 1) {
            strcpy(phone->description, "CELL");
        }
        else if (select == 2) {
            strcpy(phone->description, "HOME");
        }
        else {
            strcpy(phone->description, "WORK");
        }
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");

        do {
            
            scanf("%11s['\n]", phone->number);
            clearInputBuffer();
            if (strlen(phone->number) != 10) {
                printf("Invalid 10-digit number! Number: ");
                
            }
            
        } while (strlen(phone->number) != 10);
    }
}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* filename, struct Patient* patients, int maxPatients) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open the file %s\n", filename);
    }
    else {
        int count = 0;

        while (count < maxPatients) {
            int result = fscanf(fp, "%d|%[^|]|%[^|]|%[^|\n]\n", &patients[count].patientNumber, patients[count].name, patients[count].phone.description, patients[count].phone.number);

            if (result == EOF) {
                count = maxPatients;
            }
            count++;
        }

        fclose(fp);
        return count;
    }
    return 0;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* filename, struct Appointment* appointments, int maxAppointments) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open the file %s\n", filename); 
    }
    else {
        int count = 0, flag = 1;

        while (flag == 1 && count < maxAppointments) {
            int result = fscanf(fp, "%d,%d,%d,%d,%d,%d\n", &appointments[count].patientNumber, &appointments[count].date.year, &appointments[count].date.month, &appointments[count].date.day, &appointments[count].time.hour, &appointments[count].time.min);
            if (result == EOF) {
                flag = 0;
            }
            else {
                if (result != 6) {
                    printf("Failed to read record %d from %s\n", count + 1, filename);
                    flag = 0;
                }
                count++;
            }
        }

        sort(appointments, 0);

        return count;
    }
    return 0;
}




