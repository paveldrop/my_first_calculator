#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>



// typedef struct stack{
//     double value;
//     int priority;
//     stack *next;
//     type_t type;
// } stack;


// typedef enum {number, x, plus, minus} TYPE;

// typedef struct stack {
//     double value;  // число
//     int priority;  // приоритет числа
//     struct sNode *next; // следующая нода
//     TYPE type; // тип лексемы
// } stack;



// typedef struct Stack_1 {
//     double value;
//     int priority;
//     int enum;
//     struct Node *next;
// } stack_1;


// void init_struct(stack *stack);
// void iota(stack *stack, int leng_expression);
char *dynamic_char_line(FILE *stdin);
int validator(char *input_expression);
void Lexem_Print(char *input_expression);
