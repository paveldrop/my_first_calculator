#include "s21_smartcalc.h"

#define SYMBOLS "+-*/"

// stack* createStack() {
//     stack out = NULL;
//     out = malloc(sizeof(stack));
//     if (out == NULL) {
//         printf("Stack is empty");
//     }
//     out->size = 10;
//     out->data = malloc(out->size * sizeof(double));
//     if (out->data == NULL) {
//         free(out);
//         exit(-8);
//     }
//     out->top = 0;
//     return out;
// }

stack *create(int value) {
    stack *input = (stack*)malloc(sizeof(stack));
    input->value = value;
    input->priority = 0;
    input->next = NULL;
    input->type = number;
    return(input);
}

stack *add_element_input(double value, stack *head, int priority_value, TYPE type_value) {
    stack *add_elem = (stack*)malloc(sizeof(stack));
    add_elem->value = value;
    add_elem->priority = priority_value;
    add_elem->next = head;
    add_elem->type = type_value;
    return(add_elem);
}

void Lexem_Print(char *input_expression) {
    // for (unsigned int i = 0; i < strlen(input_expression); i++) {
        char *ptr = strtok(input_expression, SYMBOLS);
        printf(ptr);
        printf(input_expression);
        while (ptr != NULL) {
            printf("\n%s", ptr);
            ptr = strtok(NULL, SYMBOLS);
            printf("\nafter %s", ptr);
        }
    }

