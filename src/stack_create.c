#include "s21_smartcalc.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOLS "+-*/"

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
    }
    // } else {
    //     return NULL;
    // }
    return NULL;
}


// stack *add_element_input(double value, stack *head, int priority_value, TYPE type_value) {
//     stack *add_elem = (stack*)malloc(sizeof(stack));
//     add_elem->value = value;
//     add_elem->priority = priority_value;
//     add_elem->next = head;
//     add_elem->type = type_value;
//     return(add_elem);
// }

void Lexem_Print(char *input_expression) {
        int i = 0;
        char *ptr;
        char **lexems = NULL;
        lexems = (char **) malloc(sizeof(char*) * 3);
        ptr = strtok(input_expression, SYMBOLS);
        while (ptr != NULL) {
            lexems[i] = (char*) malloc((strlen(ptr) + 1) * sizeof(char));
            strcpy(lexems[i], ptr);
            parser(lexems[i]);
            ptr = strtok(NULL, SYMBOLS);
            i++;
        }
        for (int j = 0; j < i; j++) {
            printf("\nlexems[%d] = %s", j, lexems[j]);
            free(lexems[j]);
        }
        free(lexems);
}

void parser(char *lexems) {
    if (strncmp(lexems, "sin", 3)) {

    } else if (strncmp(lexems, "cos", 3)) {

    } else if (strncmp(lexems, "tg", 2)) {

    } else if (strncmp(lexems, "aco", 3)) {

    } else if (strncmp(lexems, "atg", 3)) {

    } else if (strncmp(lexems, "asi", 3)) {
        
    }
}