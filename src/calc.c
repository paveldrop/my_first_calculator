#include "s21_smartcalc.h"


#define read_full_line() ( dynamic_char_line(stdin) )


int main() {
    char *input_expression = {0};
    input_expression = read_full_line();
    stack *input = NULL;
    // stack *ready = NULL;
    // stack *support = NULL;
    push(0, 0, 0, &input);
    printf("\nprint 0 Node\n");
    // printList(input);
    printf("\nprint 0 Node\n");
    validator(input_expression);
    parser(input_expression, input);
    printList(input);
    reverse(&input);
    // push(0, 0, 0,  &input);
    // pushback(0, 0, 0,  input);
    printf("\n%s\n", input_expression);

    printf("\n AFTER REVERSE");
    printf("\n popBack %d, %f, %f - value", popBack(&input), pop(&input), peek(input, 0));

    printList(input);
    
    deleteList(input);
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
