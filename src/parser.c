#include "smartcalc.h"
#include <string.h>
// #include <unistd.h>

void parser(char *input_expression, stack **head) {
    double chislo;
    char *p = input_expression;
    
    int len_expr_str = strlen(p);
    for (int i = 0; i <= len_expr_str; i++) {
        printf("\n %d - проход\nsymbol - %c\nplace %s", i, p[i], &p[i]);
        if ((p[i] >= '0' && p[i] <= '9') || p[i+1] == '.') {
            chislo = strtod((p + i), NULL);
            printf("\n double number - %f", chislo);
            pushback(chislo, 0, 0, head);
            if (p[i+1] != 'm') {
                i = index_cursor(i, input_expression);
                printf("\n\nya zdes'!!!!!!!!!!!%d!!!!!", i);
            }
        }
        if (p[i] == 40) { // symbols "( and )"
            printf("\n\nya BRACKET(((('!!!!!!!!!!!");
            pushback(0, -1, 4, head);
            // continue;
        }
        if (p[i] == 41) {
            pushback(0, -1, 17, head);
            printf("\n\nya BRACKET)))))'!!!!!!!!!!!");
        }
        if (p[i] == 43) { // symbol "+""
            pushback(0, 1, 2, head);
            printf("\n\nya zdes'!!!!!!!!!!!");
        }
        if (p[i] == 45) { // symbol "-"
            if (i == 0) {
                pushback(0, -2, unar_minus, head);
            } else if (i >= 1 && p[i - 1] == 40) {
                pushback(0, -2, unar_minus, head);
            } else {
                pushback(0, 1, minus, head);
            }
        }
        if (p[i] == 42) { // symbol "*"
            pushback(0, 2, 5, head);
        }
        if (p[i] == 47) { // symbol "/"
            pushback(0, 2, 6, head);
        }
        if (p[i] == 94) { // symbol "^"
            pushback(0, 3, 16, head);
        }
        printf("\n\nya zdes'!!!!!!!!!!!%d!!!!!%s", strncmp(&p[i], "sin", 3), &p[i]);
        if (strncmp(&p[i], "sin", 3) == 0) {
        //     chislo = strtod(p + (i + 4), NULL);
            pushback(0, 4, 8, head);
            index_cursor(i, input_expression);
            printf("\n\nposle sin SIN index!!!!!!!!!!!%d", i);
        }
        if (strncmp(&p[i], "cos", 3) == 0) {
        //     chislo = strtod(p + (i + 4), NULL);
            pushback(0, 4, 7, head);
            i = index_cursor(i, input_expression);
            printf("\n\nposle sin COS index!!!!!!!!!!!%d", i);
        }
        if (strncmp(&p[i], "tan", 3) == 0) {
            // chislo = strtod(p + (i + 3), NULL);
            pushback(0, 4, 9, head);
            i = index_cursor(i, input_expression);
            printf("\n\nposle TG index!!!!!!!!!!!%d", i);
        }
        if (strncmp(&p[i], "acos", 4) == 0) {
            // chislo = strtod(p + (i + 5), NULL);
            
            pushback(0, 4, 10, head);
            i = index_cursor(i, input_expression);
            printf("\n\nposle ACOS index!!!!!!!!!!!%d", i);
        }
        if (strncmp(&p[i], "asin", 4) == 0) {
            // chislo = strtod(p + (i + 5), NULL);
            
            pushback(0, 4, 11, head);
            i = index_cursor(i, input_expression);
            printf("\n\nposle sin ASIN index!!!!!!!!!!!%d", i);
        }
        if (strncmp(&p[i], "atan", 4) == 0) {
            // chislo = strtod(p + (i + 5), NULL);
            
            pushback(0, 4, 12, head);
            i = index_cursor(i, input_expression);
            printf("\n\nposle sin ATAN index!!!!!!!!!!!%d", i);
        }
        if (strncmp(&p[i], "ln", 2) == 0) {
            pushback(0, 4, 14, head);
            i = index_cursor(i, input_expression); // -ln(9)+atan(9)-2.6*tg(9)
        }
        if (strncmp(&p[i], "log", 3) == 0) {
            pushback(0, 4, 15, head);
            i = index_cursor(i, input_expression);
        }
        if (strncmp(&p[i], "sqrt", 4) == 0) {
            pushback(0, 3, 13, head);
            i = index_cursor(i, input_expression);
        }
        printf("\n %d - проход\nsymbol - %c\nplace %s", i, p[i], &p[i]);
        if (strncmp(&p[i], "mod", 3) == 0) {
            pushback(0, 2, 18, head);
            i += 2;
        }
    }
}



int index_cursor(int index, char *input_expression) { // проверка если следующий символ не является цифрой или закрытием скобки?????
    for (int j = 0; j < 256; j++) {
                if ((isdigit(input_expression[index]) || input_expression[index] == '.') || 
                    (input_expression[index] >= 'a' && input_expression[index] <= 'z')) {
                    // (input_expression[index] == '^')input_expression[index] == '(' || input_expression[index] == ')'
                    index++;
                } else {
                    break;
                }
            }
    return index - 1;
}
