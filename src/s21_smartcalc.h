#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct stack{
    char *top;
    unsigned capacity;
    int *array;
} stack;


void init_struct(stack *stack);
void iota(stack *stack, int leng_expression);