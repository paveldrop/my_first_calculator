#include "s21_smartcalc.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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

stack *create(double value, int prior, TYPE type_value) {
    stack *pnt = (stack*)malloc(sizeof(stack));
    pnt->value = value;
    pnt->priority = prior;
    pnt->next = NULL;
    pnt->type = type_value;
    return(pnt);
}

void printList(stack *top) {
    if (top != NULL) {
        printf("\n%f = value", top->value);
        printf(" %d = priority", top->priority);
        printf(" %d = type -> ", top->type);
        printList(top->next);
    }
    else {
        printf("NULL\n");
    }
}

stack *deleteList(stack *top) {
    if (top != NULL) {
        deleteList(top->next);
        free(top);
    } else {
        return NULL;
    }
}

// stack *add_element_input(double value, stack *head, int priority_value, TYPE type_value) {
//     stack *add_elem = (stack*)malloc(sizeof(stack));
//     add_elem->value = value;
//     add_elem->priority = priority_value;
//     add_elem->next = head;
//     add_elem->type = type_value;
//     return(add_elem);
// }

// stack *last()

void Lexem_Print(char *input_expression) {
    // for (unsigned int i = 0; i < strlen(input_expression); i++) {
        int i = 0;
        size_t copy;
        char *str;
        char *ptr;
        // char lexems[i];
        
        // ptr = strtok(input_expression, SYMBOLS);
        str = input_expression;
        // printf(ptr);
        ptr = strtok(str, SYMBOLS);
        // **str = (char) malloc(20 * sizeof(char*));
        // printf(input_expression);

        while (ptr != NULL) {
            
            // strncpy(ptr, "\0", 1);
            printf("\nPTR = %s", ptr);
            // printf("%s", ptr);
            strcat(ptr, "\0");
            printf("\nPTR with 0 = %s", ptr);
            strcat(str, ptr);
            ptr = strtok(NULL, SYMBOLS);
        }
        printf("\nafter %s", str);
        // free(ptr);
}

