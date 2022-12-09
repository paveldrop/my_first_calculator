#include "s21_smartcalc.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    stack string;
    init_struct(&string);
    int leng_expression;
    string.top =(char *) calloc (10000, sizeof(char));
    scanf("%s", string.top);
    leng_expression = strlen(string.top);
    printf("\n%d", leng_expression);
    // string.top = malloc(sizeof(char) * (leng_expression) + 1);
    // atoi(string.top);
    printf("%s", string.top);
    free(string.top);
    
    return 0;
}

void init_struct(stack *stack) {
    stack->array = NULL;
    stack->capacity = 0;
    stack->top = NULL;
}

// void iota(stack *stack, int leng_expression) {
//     double n = 0.0;
//     for (int x = 0; x < leng_expression; x++) {
//         stack->top[x] = n % 10 + '0';
//     }
// }
