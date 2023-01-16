#include "s21_smartcalc.h"
#include <stddef.h>
#include <stdio.h>
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


stack *add_element_input(double value, stack *head, int priority_value, TYPE type_value) {
    stack *add_elem = (stack*)malloc(sizeof(stack));
    add_elem->value = value;
    add_elem->priority = priority_value;
    add_elem->next = head;
    add_elem->type = type_value;
    return add_elem;
}

// void pushBack(struct *head, double value, int priority_value, TYPE type_value) {
//     struct *head = getLast(head);
//     Node *tmp = (Node*) malloc(sizeof(Node));
//     tmp->value = value;
//     tmp->next = NULL;
//     last->next = tmp;
// }


// void Lexem_Print(char *input_expression) {
//         int i = 0;
//         char *ptr;
//         char **lexems = NULL;
//         lexems = (char **) malloc(sizeof(char*) * 3);
//         ptr = strtok(input_expression, SYMBOLS);
//         while (ptr != NULL) {
//             lexems[i] = (char*) malloc((strlen(ptr) + 1) * sizeof(char));
//             strcpy(lexems[i], ptr);
//             parser(lexems[i]);
//             ptr = strtok(NULL, SYMBOLS);
//             i++;
//         }
//         for (int j = 0; j < i; j++) {
//             printf("\nlexems[%d] = %s", j, lexems[j]);
//             free(lexems[j]);
//         }
//         free(lexems);
// }

void parser(char *input_expression, stack *ready) {
    char *chislo;
    char *p = input_expression;
    size_t len_expr_str;
    len_expr_str = strlen(input_expression);
    for (size_t i = 0; i < len_expr_str; i++) {
    //     if (input_expression[i] >= '0' && input_expression[i] <= '9') {
    //         if (input_expression[i + 1] == ',' || input_expression[i + 1] == '.') {
    //             chislo[256][i]
    //         }
    //     }
        if (p[i] == '(' || p[i] == ')') {
            add_element_input(0, ready, 5, 4);
            continue;
        }
        if (p[i] == '+') {
            add_element_input(0, ready, 1, 3);
            continue;
        }
        if (isdigit(p[i])) {
            for (double f = strtod(p, &chislo); p != chislo; f = strtod(p, &chislo)) {
                printf("\n%s остаток строки\n", chislo);
                printf("'%.*s' -> ", (int)(chislo-p), p); //I can't understand this line
                p = chislo;
                printf("%f\n", f);
            }
        }
    }
}
