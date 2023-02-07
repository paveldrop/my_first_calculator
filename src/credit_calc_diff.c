#include "smartcalc.h"
#include <stdio.h>
#include <stdlib.h>


double *calc_diff_credit(double rate, int mounth, double credit_sum, double *mpayment, double *total_payment, double *pay_rates) {
    // stack *ready = NULL;
    // stack *input = NULL;
    char *general = NULL;
    char *rates_to_pay = NULL;
    double general_payment = 0;
    double to_pay_rates = 0;
    double max_payment = 0;
    str_for_general_pay(mounth, credit_sum, &general);
    str_for_pay_rates(rate, credit_sum, &rates_to_pay);
    calculate_diff(general, rates_to_pay, &to_pay_rates, &general_payment);
    calculate_min_and_max(rate, credit_sum, general_payment, to_pay_rates, mounth, max_payment);


    printf("\n\n%lf\t%lf", general_payment, to_pay_rates);
    return 0;
}

void calculate_min_and_max(double rate, double credit_sum, double general_payment, double rates_to_pay, int mounth, double max_payment) {
    double total = 0;
    double tax_pay = 0;
    double overpay = credit_sum;
    double min_payment = 0;
    max_payment = general_payment + rates_to_pay;
    for (int i = 0; i < mounth - 1; i++) {
        credit_sum -= general_payment;
        if (i % 2 == 0) {
            tax_pay = (credit_sum*(rate/100)*31)/365 + general_payment;
            total += tax_pay;
            if (i == mounth - 2) {
                min_payment = tax_pay;
            }
        } else if (i == 12) {
            tax_pay = (credit_sum*(rate/100)*28)/365 + general_payment;
            total += tax_pay;
            if (i == mounth - 2) {
                min_payment = tax_pay;
            }
        } else {
            tax_pay = (credit_sum*(rate/100)*30)/365 + general_payment;
            total += tax_pay;
            if (i == mounth - 2) {
                min_payment = tax_pay;
            }
        }
    }
    total += max_payment;
    overpay -= total;

    printf("\n%f\t%f\t%f\t%f", overpay, total, min_payment, max_payment);
}
    


void calculate_diff(char *general, char *rates, double *pay_rates, double *general_pay) {
    stack *ready = NULL;
    stack *input = NULL;
    stack *input_pay = NULL;
    stack *ready_pay = NULL;
    parser(general, &input);
    rpn(&input, &ready, 0);
    *general_pay = calculate(&ready);
    // deleteListforreuse(&input);
    // deleteListforreuse(&ready);
    parser(rates, &input_pay);
    rpn(&input_pay, &ready_pay, 0);
    *pay_rates = calculate(&ready_pay);
    deleteList(&input);
    deleteList(&input_pay);
    free(general);
    free(rates);
}


void *str_for_general_pay(int mounth, double credit_sum, char **general) {
    char *pay_general = NULL;
    char *rate_pay = NULL;
    size_t length = 0;
    length = (size_t)snprintf(NULL, 0, "%.2f/%d",
                credit_sum, mounth) + 1;
    pay_general = malloc(length);
    snprintf(pay_general, length, "%.2f/%d",
                credit_sum, mounth);
    *general = pay_general;
}

void *str_for_pay_rates(double rate, double credit_sum, char **rates_pay) {
    char *pay_general = NULL;
    char *rate_pay = NULL;
    double rate_for_expr = rate/100;
    size_t length = 0;
    length = (size_t)snprintf(NULL, 0, "(%.2f*%.3f*30)/365",
                credit_sum, rate_for_expr) + 1;
    rate_pay = malloc(length);
    snprintf(rate_pay, length, "(%.2f*%.2f*30)/365",
                credit_sum, rate_for_expr);
    *rates_pay = rate_pay;
}



int main() {
  double credit_sum = 120000;
  double rate = 15;
  int mounth = 13;
  // char type = 'a';
  double payment = 0, overpayment = 0, total_payments = 0;
  calc_diff_credit(rate, mounth, credit_sum, &payment, &total_payments, &overpayment);
  return 0;
}

// void d