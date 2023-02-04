#include "s21_smartcalc.h"
#include <stdio.h>
#include <stdlib.h>
// Проверка на символы ввода, и на одинаковые знаки: + - * /

int validator(char *input_expression) {
    int err = -1;
    // char *inp = NULL;
    char *wo_spaces_exp = input_expression;
    char test[32] = {43, 99, 111, 115, 105, 110, 116, 97, 108, 109, 100, 113, 114, 94, 45, 42, 47, 40, 41, 46, 44, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    printf("%s", test);
    printf("\n%s", wo_spaces_exp);
    unsigned int count = 0, count_bracket = 0;

    // no_space(input_expression);
    for (unsigned int i = 0; i < strlen(wo_spaces_exp); i++) {
        if (wo_spaces_exp[i] == ')' || wo_spaces_exp[i] == '(') {
            count_bracket++;
        }
        for (unsigned int j = 0; j < strlen(test); j++) {
            if (wo_spaces_exp[i] == test[j]) {
                if((wo_spaces_exp[i] == wo_spaces_exp[i + 1]) && wo_spaces_exp[i] == '+') {
                    err = -1;
                    break;
                } else if ((wo_spaces_exp[i] == wo_spaces_exp[i + 1]) && wo_spaces_exp[i] == '-') {
                    err = -1;
                    break;
                } else if ((wo_spaces_exp[i] == wo_spaces_exp[i + 1]) && wo_spaces_exp[i] == '*') {
                    err = -1;
                    break;
                } else if ((wo_spaces_exp[i] == wo_spaces_exp[i + 1]) && wo_spaces_exp[i] == '/') {
                    err = -1;
                    break;
                } else if (wo_spaces_exp[i] == '(' && wo_spaces_exp[i + 1] == ')') {
                    err = -1;
                    break;
                } else if (wo_spaces_exp[i] == ' ') {
                    err = -2; // пробелы в здании
                    break;
                }
                count++;
            }
        }
    }
    printf("\ncount = !!!!!!!!!!!!!!!");
    if (count == strlen(wo_spaces_exp)) {
        err = 0;
        // printf("\nProverka na simvoly done count = %d symbol in input = %ld", count, strlen(wo_spaces_exp));
    }
    if (count_bracket % 2 == 1) {
        err = -3;  // недостаточно скобок
    }
    printf("\ncount = !!!!!!!!!!!!!!! %u", count_bracket);
    printf("\ncount = !!!!!!!!!!!!!!! %d", err);
    return err;
}

char *no_space(char *input) {
    int j = 0;
    char *str = input;
    char *output = (char*)malloc(sizeof(input) + strlen("\0"));
    for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != ' ') {
                output[j] = str[i];
                j++;
            }
    }
    output[j] = '\0';
    printf("%s", output);
    return output;
}

