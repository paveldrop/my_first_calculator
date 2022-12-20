#include "s21_smartcalc.h"
#include <stdio.h>
#include <stdlib.h>

#define read_full_line() ( dynamic_char_line(stdin) )


int main() {
    char *input_expression = {0};
    // scanf("%s", input_expression);
    input_expression = read_full_line();
    printf("%d", validator(input_expression));
    // printf("%s", input_expression);

    free(input_expression);
    return 0;
}

char *dynamic_char_line(FILE *stdin) {

    char* str = NULL;
    size_t capacity = 0;
    size_t length = getline(&str, &capacity, stdin);

    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
    return str;
}
