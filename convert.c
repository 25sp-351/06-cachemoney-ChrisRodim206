#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"

#define BUFFER_SIZE 512

// number words description
char *ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void number_to_strings(int num, char *output) {
    output[0] = '\0';

    if (num == 0) {
        strcpy(output, "zero");
        return;
    }

    // Handle hundreds place
    if (num >= 100) {
        strcat(output, ones[num / 100 - 1]);
        strcat(output, " hundred");
        num %= 100;

        if (num > 0) {
            strcat(output, " ");
        }
    }

    // Handle tens place 
    if (num >= 20) {
        strcat(output, tens[num / 10 - 1]);
        num %= 10;

        if (num > 0) {
            strcat(output, " ");
        }
    }

    // Handle ones place 
    if (num > 0) {
        strcat(output, ones[num - 1]);
    }
}

char* convert_money_to_string(int cents) {
    int dollars = cents / 100;
    int getcents = cents % 100;

    char string_dollars[BUFFER_SIZE];
    char string_cents[BUFFER_SIZE];

    number_to_strings(dollars, string_dollars);
    number_to_strings(getcents, string_cents);

    char* result = (char*)malloc(BUFFER_SIZE);
    if (!result) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Format the output string
    if (dollars > 0 && getcents > 0) {
        snprintf(result, BUFFER_SIZE, "%s dollars and %s cents", string_dollars, string_cents);
    } else if (dollars > 0) {
        snprintf(result, BUFFER_SIZE, "%s dollars", string_dollars);
    } else if (getcents > 0) {
        snprintf(result, BUFFER_SIZE, "%s cents", string_cents);
    } else {
        snprintf(result, BUFFER_SIZE, "zero dollars and zero cents");
    }

    return result;
}


