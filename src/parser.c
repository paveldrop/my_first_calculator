#include "s21_smartcalc.h"

void parser(char *input_expression, stack **head) {
    double chislo;
    char *p = input_expression;
    size_t len_expr_str;
    len_expr_str = strlen(p);
    for (uint i = 0; i < len_expr_str; i++) {
        printf("\n %d - проход\nsymbol - %c\nplace %s", i, p[i], &p[i]);
        if ((p[i] >= '0' && p[i] <= '9') || p[i+1] == '.') {
            chislo = strtod((p + i), NULL);
            printf("\n double number - %f", chislo);
            if (i >= 2 && p[i-1] == 45 && p[i-2] == 40 ) {
                chislo *= -1;
                pushback(chislo, 0, 0, head);
            // } else if (i-1 == 0 && p[i-1] == 45) {
            //     pushback(chislo, 0, 3, head);
            } else {
                pushback(chislo, 0, 0, head);
            // }
            i = index_cursor(i, input_expression);
            printf("\n\nya zdes'!!!!!!!!!!!%d!!!!!", i);
        }
        if (p[i] == 40 || p[i] == 41) { // symbols "( and )"
            printf("\n\nya zdes'!!!!!!!!!!!");
            pushback(0, 5, 4, head);
            // continue;
        }
        if (p[i] == 43) { // symbol "+""
            pushback(0, 1, 2, head);
            printf("\n\nya zdes'!!!!!!!!!!!");
        }
        if (p[i] == 45) { // symbol "-"
            if (i == 0 && isdigit(p[i+1])) {
                continue;
            } else if(isdigit(p[i+1]) && p[i-1] == 40) { // "(-a...."
                continue;
            } else {
                pushback(0, 1, 3, head);
            }
            // continue;
        }
        if (p[i] == 42) { // symbol "*"
            pushback(0, 2, 5, head);
            // continue;
        }
        if (p[i] == 47) { // symbol "/"
            pushback(0, 2, 6, head);
            // continue;
        }
        // printf("\n\nya zdes'!!!!!!!!!!!%d!!!!!", strncmp(&p[i], "sin(", 2));
        // if (strncmp(&p[i], "sin(", 2) == 0) {
        //     chislo = strtod(p + (i + 4), NULL);
            
        //     pushbackback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle sin SIN index!!!!!!!!!!!%d", i);
        // }
        // if (strncmp(&p[i], "cos(", 2) == 0) {
        //     chislo = strtod(p + (i + 4), NULL);
            
        //     pushback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle sin COS index!!!!!!!!!!!%d", i);
        // }
        // if (strncmp(&p[i], "tg", 2) == 0) {
        //     chislo = strtod(p + (i + 3), NULL);
            
        //     pushback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle tg index!!!!!!!!!!!%d", i);
        // }
        // if (strncmp(&p[i], "acos(", 2) == 0) {
        //     chislo = strtod(p + (i + 5), NULL);
            
        //     pushback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle ACOS index!!!!!!!!!!!%d", i);
        // }
        // if (strncmp(&p[i], "asin(", 2) == 0) {
        //     chislo = strtod(p + (i + 5), NULL);
            
        //     pushback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle sin ACOS index!!!!!!!!!!!%d", i);
        // }
        // if (strncmp(&p[i], "atan(", 2) == 0) {
        //     chislo = strtod(p + (i + 5), NULL);
            
        //     pushback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle sin ATAN index!!!!!!!!!!!%d", i);
        // }
        // if (strncmp(&p[i], "ln(", 2) == 0) {
        //     chislo = strtod(p + (i + 3), NULL);
            
        //     pushback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle sin LN index!!!!!!!!!!!%d", i);
        // }
        // if (strncmp(&p[i], "log", 3) == 0) {
        //     chislo = strtod(p + (i + 4), NULL);
            
        //     pushback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle sin LOG index!!!!!!!!!!!%d", i);
        // }
        // if (strncmp(&p[i], "^", 1) == 0) {
        //     chislo = strtod(p + (i + 1), NULL);
            
        //     pushback(chislo, 4, 0, head);
        //     i = index_cursor(i, input_expression);
        //     printf("\n\nposle sin ACOS index!!!!!!!!!!!%d", i);
        }
    }
}


int index_cursor(int index, char *input_expression) { // проверка если следующий символ не является цифрой или закрытием скобки?????
    for (int j = 0; j < 256; j++) {
                if (isdigit(input_expression[index]) || input_expression[index] == '.' || 
                    (input_expression[index] >= 'a' && input_expression[index] <= 'z') ||
                    input_expression[index] == '(' || input_expression[index] == ')') {
                    index++;
                } else {
                    break;
                }
            }
    return index;
}
