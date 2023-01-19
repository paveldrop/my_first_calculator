#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

typedef enum {number = 0, x = 1, plus = 2, minus = 3, bracket = 4, add = 5, sub = 6} TYPE;

// pririty: 0 = number, 1 = +-, 2 = */mod, 3 = ^ or sqrt, 4 = sin cos....

typedef struct stack{
    double value;
    int priority;
    struct stack *next;
    TYPE type;
} stack;

// void init_struct(stack *stack);
// void iota(stack *stack, int leng_expression);
char *dynamic_char_line(FILE *stdin);
int validator(char *input_expression);
void Lexem_Print(char *input_expression);
stack *create(double value, int prior, TYPE type_value);
void printList(stack *top);
stack *deleteList(stack *top);
void parser(char *indef, stack *ready);