#include "s21_smartcalc.h"
#include <stdio.h>
#include <string.h>

int validator(char *input_expression) {
    int err = -339;
    char test[32] = {43, 99, 111, 115, 105, 110, 116, 97, 108, 109, 100, 113, 114, 94, 45, 42, 47, 40, 41, 46, 44, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // printf("%s", test);
    unsigned int count = 0;
    for (unsigned int i = 0; i < strlen(input_expression); i++) {
        for (unsigned int j = 0; j < strlen(test); j++) {
                // printf("\nbefor This is input %c", input_expression[i]);
                // printf("\nbefore This is diff %c", test[j]);
            if (input_expression[i] == test[j]) {
                // printf("\nThis is input %c", input_expression[i]);
                // printf("\nThis is diff %c", test[j]);
                count++;
                
                // if((input_expression[i] == input_expression[i + 1]) && input_expression[i] == '+') {
                //     err = 0;
                //     break;
                // } else if ((input_expression[i] == input_expression[i + 1]) && input_expression[i] == '-') {
                //     err = 0;
                //     break;
                // } else if ((input_expression[i] == input_expression[i + 1]) && input_expression[i] == '*') {
                //     err = 0;
                //     break;
                // } else if ((input_expression[i] == input_expression[i + 1]) && input_expression[i] == '/') {
                //     err = 0;
                //     break;
                // }
            }
        }
    }
    printf("\ncount = %d symbol in input = %ld", count, strlen(input_expression));

    if (count == strlen(input_expression)) {
        err = 0;
        printf("\nProverka na simvoly done count = %d symbol in input = %ld", count, strlen(input_expression));
    }
    return err;
}
