#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

typedef enum {number = 0, x = 1, plus = 2, minus = 3, bracket_open = 4, add = 5, sub = 6, in_cos = 7, in_sin = 8, in_tg = 9,
              in_acos = 10, in_asin = 11, in_atan = 12, in_sqrt = 13, in_ln = 14, in_log = 15, in_pow = 16, bracket_close = 17 } TYPE;

// pririty: 0 = number, 1 = +-, 2 = */mod, 3 = ^ or sqrt, 4 = sin cos...., 5 = ();


// -ln(9)+atan(9)-2*tan(9)
// cos(9+2)-1
typedef struct stack{
    double value;
    int priority;
    TYPE type;
    struct stack *next;
} stack;


char *dynamic_char_line(FILE *stdin);
int validator(char *input_expression);
void parser(char *indef, stack **head);
int index_cursor(int index, char *input_expression);
void rpn(stack **head);


/*WORK WITH STACK LINKED LIST*/

stack *getLast(stack *head);
void push(double value, int prior, TYPE type_value, stack **head);
void pushback(double value, int priority_value, TYPE type_value, stack **head);
void popBack(stack **head);
void printList(stack *head);
int search_type_elem(TYPE x, stack **head);
void deleteList(stack **head);
void create_Node(double value, int priority_value, TYPE type_value, stack **head);
void reverse(stack **head);
double pop(stack **head);
stack *peek(stack *head, int pos);
int search_pos_elem(stack *head);
stack *getLastButOne(stack *head);
void move_all_in_Ready (stack **in_sup, stack **in_ready);
