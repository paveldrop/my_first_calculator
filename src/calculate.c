#include "smartcalc.h"
#include <stdio.h>

double calculate(stack **source) {
    // char rpn_output[10000] = "";
    // stack_to_array(*source, rpn_output);
    stack *p = NULL;
    stack *done = NULL;
    // stack *result = NULL;
    double end_number = 0;
    printList(*source);
    int length = search_pos_elem(*source);
    for (int i = 0; i < length; i++) {
        double p2 = 0;
        double p3 = 0;
        p = peek(*source, i);
        int done_length = search_pos_elem(done);
        if ((search_pos_elem(done) >= 2 && (p->type >= 1 && p->type <= 6)) ||
            (search_pos_elem(done) >= 2 && (p->type >= 16 && p->type <= 18))) {
            p2 = peek_dbl(done, done_length - 2);
            p3 = peek_dbl(done, done_length - 1);
            if (p->type == minus) {
                popBack(&done);
                popBack(&done);
                pushback(p2 - p3, 0, 0, &done);
            } else if (p->type == plus) {
                popBack(&done);
                popBack(&done);
                pushback(p2 + p3, 0, 0, &done);
            } else if (p->type == mult) {
                popBack(&done);
                popBack(&done);
                pushback(p2 * p3, 0, 0, &done);
            } else if (p->type == in_div) {
                popBack(&done);
                popBack(&done);
                pushback(p2 / p3, 0, 0, &done);
            // } else if (p->type == mult) {
            //     popBack(&done);
            //     popBack(&done);
                // pushback(p2 * p3, 0, 0, &done);
            }  else if (p->type == in_pow) {
                popBack(&done);
                popBack(&done);
                pushback(pow(p2, p3), 0, 0, &done);
            } else if (p->type == in_mod) {
                popBack(&done);
                popBack(&done);
                pushback(fmod(p2, p3), 0, 0, &done);
            }
        } else if ((p->type >= in_cos && p->type <= in_log) ||
                    (p->type >= unar_minus && p->type <= unar_plus)) {
            p2 = peek_dbl(done, done_length - 1);
            if (p->type == in_cos) {
                popBack(&done);
                pushback(cos(p2), 0, 0, &done);
            } else if (p->type == in_sin) {
                popBack(&done);
                pushback(sin(p2), 0, 0, &done);
            }  else if (p->type == in_tan) {
                popBack(&done);
                pushback(tan(p2), 0, 0, &done);
            } else if (p->type == in_acos) {
                popBack(&done);
                pushback(acos(p2), 0, 0, &done);
            } else if (p->type == in_asin) {
                popBack(&done);
                pushback(asin(p2), 0, 0, &done);
            } else if (p->type == in_atan) {
                popBack(&done);
                pushback(atan(p2), 0, 0, &done);
            } else if (p->type == in_sqrt) {
                popBack(&done);
                pushback(sqrt(p2), 0, 0, &done);
            } else if (p->type == in_ln) {
                popBack(&done);
                pushback(log(p2), 0, 0, &done);
            } else if (p->type == in_log) {
                popBack(&done);
                pushback(log10(p2), 0, 0, &done);
            } else if (p->type == unar_minus) {
                popBack(&done);
                pushback(-(p2), 0, 0, &done);
            }
        }
        if (p->type == 0) {
            pushback(p->value, p->priority, p->type, &done);
        }
        printf("\n_____ P STACK______after_recurce %d", i);
        printList(p);
        printf("\n_____ DONE STACK______after_recurce %d", i);
        printList(done);
    }
    end_number = done->value;
    printf("\n_____ RESULT STACK______");
        printList(done);
    deleteList(&done);
    // deleteList(&result);
    deleteList(source);
    return end_number;
    
}
