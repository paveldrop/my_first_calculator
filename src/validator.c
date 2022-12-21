#include "s21_smartcalc.h"
// Проверка на символы ввода, и на одинаковые знаки: + - * /

int validator(char *input_expression) {
    int err = -1;
    char test[32] = {43, 99, 111, 115, 105, 110, 116, 97, 108, 109, 100, 113, 114, 94, 45, 42, 47, 40, 41, 46, 44, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    printf("%s", test);
    unsigned int count = 0;
    for (unsigned int i = 0; i < strlen(input_expression); i++) {
        for (unsigned int j = 0; j < strlen(test); j++) {
            if (input_expression[i] == test[j]) {
                if((input_expression[i] == input_expression[i + 1]) && input_expression[i] == '+') {
                    err = -1;
                    break;
                } else if ((input_expression[i] == input_expression[i + 1]) && input_expression[i] == '-') {
                    err = -1;
                    break;
                } else if ((input_expression[i] == input_expression[i + 1]) && input_expression[i] == '*') {
                    err = -1;
                    break;
                } else if ((input_expression[i] == input_expression[i + 1]) && input_expression[i] == '/') {
                    err = -1;
                    break;
                }
                count++;
            }
        }
    }
    // printf("\ncount = %d symbol in input = %ld", count, strlen(input_expression));
    if (count == strlen(input_expression)) {
        err = 0;
        // printf("\nProverka na simvoly done count = %d symbol in input = %ld", count, strlen(input_expression));
    }
    return err;
}
