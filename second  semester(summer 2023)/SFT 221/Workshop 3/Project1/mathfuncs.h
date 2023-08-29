#pragma once
#ifndef MATHFUNCS_H
#define MATHFUNCS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct customer {
    char firstName[20];
    char lastName[20];
    char streetAddress[50];
    char city[50];
    char province[50];
    char postalCode[8];

};
int isLastName(char* last_name);
int check_postal_code(char* code);

#endif