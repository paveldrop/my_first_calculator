#include "smartcalc.h"


#define read_full_line() ( dynamic_char_line(stdin) )


double smart_calc(double x, char *input_expression, double result) {
    // char *input_expression = {0};
    // input_expression = read_full_line();
    stack *input = NULL;
    stack *ready = NULL;
    // double result = 0;
    validator(input_expression);
    parser(input_expression, &input);
    // printList(input);
    // reverse(&input);
    rpn(&input, &ready, x);
    result = calculate(&ready);
    printList(input);
    printf("\n My string_______%s", input_expression);
    deleteList(&input);
    // deleteList(&ready);

//    free(input_expression);
    return result;
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
