#include "s21_smartcalc.h"


#define read_full_line() ( dynamic_char_line(stdin) )


int main() {
    char *input_expression = {0};
    input_expression = read_full_line();
    stack *input = NULL;
    stack *ready = NULL;
    validator(input_expression);
    parser(input_expression, &input);
    // printList(input);
    reverse(&input);
    rpn(&input, &ready);
    calculate(&ready);
    // printList(input);
    
    deleteList(&input);
    // deleteList(&ready);

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
