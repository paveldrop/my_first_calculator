#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {number = 0, x = 1, plus = 2, minus = 3} TYPE;

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
stack *create(int value);
