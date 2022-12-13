#include "s21_smartcalc.h"
#include <stdio.h>
#include <stdlib.h>

#define read_full_line() ( dynamic_char_line(stdin) )


int main() {
    char *input_expression = {0};
    // scanf("%s", input_expression);
    input_expression = read_full_line();
    printf("%s", input_expression);
    free(input_expression);
    return 0;
}

char *dynamic_char_line(FILE *stdin) {
    // size_t capacity = 16;
    // char *str = malloc(capacity);
    // size_t length = 0;
    // int sizeofbit = sizeof(char);
    // char *p;
    // if (!str) return NULL;

    // int ch;
    // while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
    //     if (length >= capacity) {
    //         p = (char *) realloc(str, capacity * sizeofbit);
    //         if(!p) break;
    //         str = p;
    //     }
        
    //     str[length++] = ch;
    // }
    // free(p);
    // str[length] = '\0';
    // return str;

    char* str = NULL;
    size_t capacity = 0;
    ssize_t length = getline(&str, &capacity, stdin);

    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';  // убирает перевод строки
    }
    return str;
}
