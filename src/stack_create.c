#include "s21_smartcalc.h"

stack* createStack() {
    stack *out = NULL;
    out = malloc(sizeof(stack));
    if (out == NULL) {
        exit(-8);
    }
    out->size = 10;
    out->data = malloc(out->size * sizeof(T));
    if (out->data == NULL) {
        free(out);
        exit(-8);
    }
    out->top = 0;
    return out;
}
