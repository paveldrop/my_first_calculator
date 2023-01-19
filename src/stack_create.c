#include "s21_smartcalc.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOLS "+-*/"

void push(double value, int prior, TYPE type_value, stack **head) {
    stack *tmp = (stack*)malloc(sizeof(stack));
    tmp->value = value;
    tmp->priority = prior;
    tmp->type = type_value;
    tmp->next = *head;
    *head = tmp;
}

void printList(stack *head) {
    while(head != NULL) {
        printf("\n%f = value", head->value);
        printf("\n%d = priority", head->priority);
        printf("\n%d = type - ↓\n\n", head->type);
        head = head->next;
    }
    printf("\nNULL or stack is free\n");
}


void deleteList(stack **head) {
    stack *prev = NULL;
    while((*head)->next) {
        prev = *head;
        *head = (*head)->next;
        free(prev);
    }
    free(*head);
}


void pushback(double value, int priority_value, TYPE type_value, stack *head) {
    stack *last = getLast(head);
    stack *tmp = (stack*) malloc(sizeof(stack));
    tmp->value = value;
    tmp->priority = priority_value;
    tmp->type = type_value;
    tmp->next = NULL;
    last->next = tmp;
}

stack *getLast(stack *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

int popBack(stack **head) {
    stack *pFwd = NULL;  //текущий узел
    stack *pBwd = NULL;  //предыдущий узел
    //Получили NULL
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
    pFwd = *head; 
    while (pFwd->next) { 
        pBwd = pFwd;
        pFwd = pFwd->next;
    }
    if (pBwd == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(pFwd->next);
        pBwd->next = NULL;
    }
}


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

void parser(char *input_expression, stack *head) {
    double chislo;
    char *p = input_expression;
    size_t len_expr_str;
    len_expr_str = strlen(p);
    pushback(99, 99, 99, head);
    pushback(99, 99, 99, head);
    for (int i = 0; i < len_expr_str; i++) {
        if (p[i] == 40 || p[i] == 41) {
            printf("\n\nya zdes'!!!!!!!!!!!");
            pushback(0, 5, 4, head);
            // continue;
        }
        if (p[i] == 43) { // symbol "+
            pushback(0, 1, 2, head);
            printf("\n\nya zdes'!!!!!!!!!!!");
            // continue;
        }
        if (p[i] == 45) {
            pushback(0, 1, 3, head);
            // continue;
        }
        if (p[i] == 42) {
            pushback(0, 2, 5, head);
            // continue;
        }
        if (p[i] == 47) {
            pushback(0, 2, 6, head);
            // continue;
        }
        if ((p[i] >= '0' && p[i] <= '9')) {
            chislo = strtod((p + i), NULL);
            printf("\n double number - %f", chislo);
            for (int j = 0; j < 256; j++) {
                if ((p[i] >= '0' && p[i] <= '9') || p[i] == '.') {
                    i++;
                } else {
                    break;
                }
            }
                // printf("\n nachalo str - %lu\n", i);

            // }
            // for (double f = strtod(p, &chislo); p != chislo; f = strtod(p, &chislo)) {
            //     printf("\n%s остаток строки\n", chislo);
            //     printf("'%.*s' -> ", (int)(chislo-p), p); //I can't understand this line
            //     p = chislo;
            //     printf("%f\n", f);
            // }
        }
    }
}
