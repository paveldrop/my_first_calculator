#include "s21_smartcalc.h"
#include <stdlib.h>
// Проверка на символы ввода, и на одинаковые знаки: + - * /

int validator(char *input_expression) {
    int err = -1;
    char *inp = NULL;
    inp = no_space(input_expression);
    char test[32] = {43, 99, 111, 115, 105, 110, 116, 97, 108, 109, 100, 113, 114, 94, 45, 42, 47, 40, 41, 46, 44, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    printf("%s", test);
    printf("%s", no_space(input_expression));
    unsigned int count = 0, count_bracket = 0;

    no_space(input_expression);
    for (unsigned int i = 0; i < strlen(input_expression); i++) {
        if (input_expression[i] == ')' || input_expression[i] == '(') {
            count_bracket++;
        }
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
                } else if (input_expression[i] == '(' && input_expression[i + 1] == ')') {
                    err = -1;
                    break;
                } else if (input_expression[i] == ' ') {
                    err = -2; // пробелы в здании
                    break;
                }
                count++;
            }
        }
    }
    printf("\ncount = !!!!!!!!!!!!!!!");
    if (count == strlen(input_expression)) {
        err = 0;
        // printf("\nProverka na simvoly done count = %d symbol in input = %ld", count, strlen(input_expression));
    }
    if (count_bracket % 2 == 1) {
        err = -3;  // недостаточно скобок
    }
    printf("\ncount = !!!!!!!!!!!!!!! %u", count_bracket);
    printf("\ncount = !!!!!!!!!!!!!!! %d", err);
    return err;
}

char no_space(char *input) {
    int i = 0, j = 0;
    char *output = (char*)malloc(sizeof(input));
    for (; input[i] != '\0'; i++) {
            if (input[i] != ' ') {
                output[j++] = input[i];
            }
        output[j] = '\0';
    }
    return *output;
}

