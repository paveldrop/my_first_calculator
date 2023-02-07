#include "smartcalc.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


credit *calc_diff_credit(credit *credit) {
    credit->max_tax = 0;
    credit->min_tax = 0;
    credit->total = 0;
    credit->overpay = 0;

    double min_tax_f = 0, max_tax_f = 0, total_with_over = 0, total_f = 0, overpay_f = 0, general_pay_f = 0, rates_pay = 0;
    rates_pay = (credit->amount*(credit->rate/100)*30)/365;
    general_pay_f = credit->amount /credit->mounth;
    max_tax_f = rates_pay + general_pay_f;
    total_f = credit->amount;
    total_f += rates_pay;
    min_tax_f = max_tax_f;
    for (int i = 0; i < credit->mounth - 1; i++) {
        total_f -= general_pay_f;
        if (i % 2 == 0) {
            rates_pay = (total_f*(credit->rate/100)*31)/365 + general_pay_f;
            total_with_over += rates_pay;
            if (i == credit->mounth - 2 && min_tax_f > rates_pay) {
                min_tax_f = rates_pay;
            }
        } else if (i == 2) {
            rates_pay = (total_f*(credit->rate/100)*28)/365 + general_pay_f;
            total_with_over += rates_pay;
            if (i == credit->mounth - 2 && min_tax_f > rates_pay) {
                min_tax_f = rates_pay;
            }
        } else {
            rates_pay = (total_f*(credit->rate/100)*30)/365 + general_pay_f;
            total_with_over += rates_pay;
            if (i == credit->mounth - 2 && min_tax_f > rates_pay) {
                min_tax_f = rates_pay;
            }
        }
        printf("\n%lf\t%lf\t%lf", rates_pay, rates_pay - general_pay_f, credit->rate/100);
        
    }
    total_with_over += max_tax_f;
    total_f = rates_pay + general_pay_f*credit->mounth;
    overpay_f = total_with_over - credit->amount;



    printf("\n\n%lf\t%lf\t%lf\t%lf\t%lf\t%lf", total_f, total_with_over, rates_pay, max_tax_f, min_tax_f, overpay_f);
    return credit;
}

// void calculate_min_and_max(double rate, double credit_sum, double general_payment, double rates_to_pay, int mounth, double max_payment) {
//     double total = 0;
//     double tax_pay = 0;
//     double overpay = credit_sum;
//     double min_payment = 0;
    
//     max_payment = general_payment + rates_to_pay;
//     for (int i = 0; i < mounth - 1; i++) {
//         credit_sum -= general_payment;
//         if (i % 2 == 0) {
//             tax_pay = (credit_sum*(rate/100)*31)/365 + general_payment;
//             total += tax_pay;
//             if (i == mounth - 2) {
//                 min_payment = tax_pay;
//             }
//         } else if (i == 12) {
//             tax_pay = (credit_sum*(rate/100)*28)/365 + general_payment;
//             total += tax_pay;
//             if (i == mounth - 2) {
//                 min_payment = tax_pay;
//             }
//         } else {
//             tax_pay = (credit_sum*(rate/100)*30)/365 + general_payment;
//             total += tax_pay;
//             if (i == mounth - 2) {
//                 min_payment = tax_pay;
//             }
//         }
//     }
//     total += max_payment;
//     overpay -= total;

//     printf("\n%f\t%f\t%f\t%f", overpay, total, min_payment, max_payment);
// }
    


// void calculate_diff(char *general, char *rates, double *pay_rates, double *general_pay) {
//     stack *ready = NULL;
//     stack *input = NULL;
//     stack *input_pay = NULL;
//     stack *ready_pay = NULL;
//     parser(general, &input);
//     rpn(&input, &ready, 0);
//     *general_pay = calculate(&ready);
//     // deleteListforreuse(&input);
//     // deleteListforreuse(&ready);
//     parser(rates, &input_pay);
//     rpn(&input_pay, &ready_pay, 0);
//     *pay_rates = calculate(&ready_pay);
//     deleteList(&input);
//     deleteList(&input_pay);
//     free(general);
//     free(rates);
// }


// void *str_for_general_pay(int mounth, double credit_sum, char **general) {
//     char *pay_general = NULL;
//     char *rate_pay = NULL;
//     size_t length = 0;
//     length = (size_t)snprintf(NULL, 0, "%.2f/%d",
//                 credit_sum, mounth) + 1;
//     pay_general = malloc(length);
//     snprintf(pay_general, length, "%.2f/%d",
//                 credit_sum, mounth);
//     *general = pay_general;
// }

// void *str_for_pay_rates(double rate, double credit_sum, char **rates_pay) {
//     char *pay_general = NULL;
//     char *rate_pay = NULL;
//     double rate_for_expr = rate/100;
//     size_t length = 0;
//     length = (size_t)snprintf(NULL, 0, "(%.2f*%.3f*30)/365",
//                 credit_sum, rate_for_expr) + 1;
//     rate_pay = malloc(length);
//     snprintf(rate_pay, length, "(%.2f*%.2f*30)/365",
//                 credit_sum, rate_for_expr);
//     *rates_pay = rate_pay;
// }



int main() {
    credit *cred_diff = NULL;
    cred_diff = (credit*)malloc(sizeof(credit));
  cred_diff->amount = 300000;
  cred_diff->rate = 10;
  cred_diff->mounth = 2;
  // char type = 'a';
  calc_diff_credit(cred_diff);
//   calc_diff_credit(rate, mounth, credit_sum, &payment, &total_payments, &overpayment);
  return 0;
}

// void d