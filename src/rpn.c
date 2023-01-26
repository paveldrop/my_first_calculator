#include "s21_smartcalc.h"
#include <stdio.h>


void rpn(stack *head) {
  int length = search_pos_elem(head);
  stack *p = NULL;
  stack *ready = NULL;
  stack *support = NULL;
  for (int i = 0; i < length; i++) {
    printf("\n list in rpn");
    p = getLast(head);
    printList(p);
    if (p->type == 0) {
        pushback(p->value, p->priority, p->type, &ready);
    }
    if (p->type != 0) {
        pushback(p->value, p->priority, p->type, &support);
    }
  }
  printf("\n\n\n_________________________READY______________________");
  printList(ready);
  printf("\n - SUPPORT");
  printList(support);
}