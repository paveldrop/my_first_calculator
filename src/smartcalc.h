#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

typedef enum {number = 0, x = 1, plus = 2, minus = 3, bracket_open = 4,
              mult = 5, in_div = 6, in_cos = 7, in_sin = 8, in_tan = 9,
              in_acos = 10, in_asin = 11, in_atan = 12, in_sqrt = 13,
              in_ln = 14, in_log = 15, in_pow = 16, bracket_close = 17,
              in_mod = 18, unar_minus = 19, unar_plus = 20} TYPE;

// pririty: -2 = unar -+, 0 = number, 1 = +-, 2 = */mod, 3 = ^ or sqrt, 4 = sin cos...., 5 = ();


// -ln(9)+atan(9)-2*tan(9)
// cos(9+2)-1
// 99*(-10)+21

typedef struct credit{
    double amount;
    double rate;
    int mounth;
    double max_tax;
    double min_tax;
    double total;
    double overpay;
    double general_pay;
    double rates_to_pay;
} credit;
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
stack *rpn(stack **head, stack **ready, double x);
double calculate(stack **source);
double smart_calc(double x, char *input_expression, double *result);
void *no_space(char *input);
int expr_is_null_or(char *input);


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
void pull_to_insert(stack **source, stack **dest);
int GetLastPriority(stack **source);
void pull_to_bracket(stack **source, stack **dest);
char stack_to_array(stack *source, char *output);
double peek_dbl(stack *head, int pos);

/*CREDIT CALCULATOR*/

void total_pay(double *mpayment, int const *mounth, double *total_pay);
void make_str(double rate, int mounth, double credit_sum, char **in);
double credit_calc(double rate, int mounth, double credit_sum, double *mpayment, double *total_payment, double *pay_rates);
void overpay(double total_payment, double credit_sum, double *pay_rates);

void *str_for_general_pay(int mounth, double credit_sum, char **general);
credit *calc_diff_credit(credit *x);
void *str_for_pay_rates(double rate, double credit_sum, char **rates_pay);
void calculate_diff(char *general, char *rates, double *pay_rates, double *general_pay);
void calculate_min_and_max(double rate, double credit_sum,double general_payment, double rates_to_pay, int mounth, double max_payment);
void deleteListforreuse(stack **head);