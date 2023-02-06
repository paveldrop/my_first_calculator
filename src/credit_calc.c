#include "smartcalc.h"
#include <stdlib.h>


void make_str(double rate, int mounth, double credit_sum, char **in) {
    char *credit_buf = {0};
    double rate_for_expr = rate/(100*12); 
    size_t length = 0;
    length = (size_t)snprintf(NULL, 0, "(%.3f*%.3f)/(1-(1+%.3f)^(-%d)",
                credit_sum, rate_for_expr, rate_for_expr, mounth) + 1;
    credit_buf = malloc(length);
    snprintf(credit_buf, length, "(%.3f*%.3f)/(1-(1+%.3f)^(-%d)",
                credit_sum, rate_for_expr, rate_for_expr, mounth);
    *in = credit_buf;
}

double credit_calc(double rate, int mounth, double credit_sum, double *mpayment, double *total_payment, double *pay_rates) {
    char *credit = {0};
    stack *input = NULL;
    stack *ready = NULL;
    make_str(rate, mounth, credit_sum, &credit);
    parser(credit, &input);
    printList(input);
    rpn(&input, &ready, 0);
    *mpayment = calculate(&ready);
    total_pay(mpayment, &mounth, total_payment);
    overpay(*total_payment, credit_sum, pay_rates);
    // printf("\n\n%s", credit);
    // printf("\n\n%lf", *mpayment);
    // printf("\n\n%lf", *total_payment);
    // printf("\n\n%lf", *pay_rates);
    free(credit);
    deleteList(&input);
    return 0;
}

void total_pay(double *mpayment, int const *mounth, double *total_payment) {
    stack *total = NULL;
    stack *ready = NULL;
    int dblMounth = *mounth;
    dblMounth = (double)dblMounth;
    pushback(*mpayment, 0, number, &total);
    pushback(0, 2, mult, &total);
    pushback(dblMounth, 0, number, &total);
    printList(total);
    rpn(&total, &ready, 0);
    *total_payment = calculate(&ready);
    deleteList(&total);
}

void overpay(double total_payment, double credit_sum, double *pay_rates) {
    stack *total = NULL;
    stack *ready = NULL;
    pushback(total_payment, 0, number, &total);
    pushback(0, 1, minus, &total);
    pushback(credit_sum, 0, number, &total);
    rpn(&total, &ready, 0);
    *pay_rates = calculate(&ready);
    deleteList(&total);
}



int main() {
  double credit_sum = 1000000;
  double rate = 12;
  int mounth = 24;
  // char type = 'a';
  double payment = 0, overpayment = 0, total_payments = 0;
  credit_calc(rate, mounth, credit_sum, &payment, &total_payments, &overpayment);
  return 0;
}
