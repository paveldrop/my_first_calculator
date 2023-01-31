#include "s21_smartcalc.h"
#include <stdio.h>

double calculate(stack **source) {
    // char rpn_output[10000] = "";
    // stack_to_array(*source, rpn_output);
    stack *p = NULL;
    double p2 = 0;
    double p3 = 0;
    stack *done = NULL;
    stack *result = NULL;
    double end_number = 0;
    
    int length = search_pos_elem(*source);
    for (int i = 0; i < length; i++) {
        p = peek(*source, i);
        int done_length = search_pos_elem(done);
        if (search_pos_elem(done) >= 2) {
            p2 = peek_dbl(done,  done_length - 2);
            p3 = peek_dbl(done, done_length - 1);
            if (p->type == minus) {
                popBack(&done);
                popBack(&done);
                pushback(p2 - p3, 0, 0, &done);
            }
        }
        if (p->type == 0) {
            pushback(p->value, p->priority, p->type, &done);
        }
        printList(p);
        printList(done);
    }
    // printList(done);
    // printList(result);
    deleteList(&done);
    deleteList(&result);
    deleteList(source);
    return 1.1;
    
}
