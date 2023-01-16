#include "s21_smartcalc.h"


#define read_full_line() ( dynamic_char_line(stdin) )


int main() {
    char *input_expression = {0};
    input_expression = read_full_line();
    validator(input_expression);
    // printf("\n%d", validator(input_expression));
    // printf("%s", input_expression);
    parser(input_expression);
    printf("%s", input_expression);
    // Lexem_Print(input_expression);
    // stack *a = NULL;
    // a = create(2.58, 1, 2);
    // printList(a);
    // deleteList(a);
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
