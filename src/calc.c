#include "s21_smartcalc.h"


#define read_full_line() ( dynamic_char_line(stdin) )


int main() {
    char *input_expression = {0};
    input_expression = read_full_line();
    stack *input = NULL;
    input = create(0,0,0);
    validator(input_expression);
    // printf("\n%d", validator(input_expression));
    // printf("%s", input_expression);
    parser(input_expression, input);
    printf("%s", input_expression);
    // Lexem_Print(input_expression);
    
    
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
