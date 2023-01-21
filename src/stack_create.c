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
    double chislo_sin;
    char *p = input_expression;
    size_t len_expr_str;
    len_expr_str = strlen(p);
    // pushback(99, 99, 99, head);
    // pushback(99, 99, 99, head);
    for (int i = 0; i < len_expr_str; i++) {
        printf("\n %d - проход\nsymbol - %c\nplace %s", i, p[i], &p[i]);
        if ((p[i] >= '0' && p[i] <= '9')) {
            chislo = strtod((p + i), NULL);
            printf("\n double number - %f", chislo);
            if (p[i-1] == 45 && p[i-2] == 40 ) {
                pushback(chislo, 0, 3, head);
            } else if (i-1 == 0 && p[i-1] == 45) {
                pushback(chislo, 0, 3, head);
            } else {
                pushback(chislo, 0, 2, head);
            }
            index_cursor(i, input_expression);
            // for (int j = 0; j < 256; j++) {
            //     if ((p[i] >= '0' && p[i] <= '9') || p[i] == '.') {
            //         i++;
            //     } else {
            //         i -= 1;
            //         break;
            //     }
            // }
        }
        if (p[i] == 40 || p[i] == 41) { // symbols "( and )"
            printf("\n\nya zdes'!!!!!!!!!!!");
            pushback(0, 5, 4, head);
            // continue;
        }
        if (p[i] == 43) { // symbol "+""
            pushback(0, 1, 2, head);
            printf("\n\nya zdes'!!!!!!!!!!!");
        }
        if (p[i] == 45) { // symbol "-"
            if (i == 0 && isdigit(p[i+1])) {
                continue;
            } else if(isdigit(p[i+1]) && p[i-1] == 40) { // "(-a...."
                continue;
            } else {
                pushback(0, 1, 3, head);
            }
            // continue;
        }
        if (p[i] == 42) { // symbol "*"
            pushback(0, 2, 5, head);
            // continue;
        }
        if (p[i] == 47) { // symbol "/"
            pushback(0, 2, 6, head);
            // continue;
        }
        printf("\n\nya zdes'!!!!!!!!!!!%d!!!!!", strncmp(&p[i], "sin(", 2));
        if (strncmp(&p[i], "sin(", 2) == 0) {
            chislo_sin = strtod((p + i), NULL);
            
            pushback(chislo_sin, 4, 0, head);
            index_cursor(i + 1, input_expression);
            printf("\n\nya zdes' SIN!!!!!!!!!!!%d", i);
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

int index_cursor(int index, char *input_expression) { // проверка если следующий символ не является цифрой или закрытием скобки?????
    for (int j = 0; j < 256; j++) {
                if ((isdigit(input_expression[index])) || input_expression[index] == '.' ) {
                    index++;
                } else {
                    index -= 1;
                    break;
                }
            }
    return index;
}
