#include "s21_smartcalc.h"
#include <stdio.h>


void rpn(stack *head) {
  stack *p = NULL;
  stack *ready = NULL;
  // push(0, 0, 0, &ready);
  stack *support = NULL;
  // push(0, 0, 0, &support);
  int length = search_pos_elem(head);
//   p = getLast(head);
//   p = head;
  for (int i = 0; i < length; i++) {
    p = peek(head, i);
    printf("\n list in rpn p_TYPE_%d", p->type);
    printList(p);
    if (p->type == 0) {
        pushback(p->value, p->priority, p->type, &ready);
        // popBack(&p);
    }
    if (p->type != 0) {
        pushback(p->value, p->priority, p->type, &support);
        // popBack(&p);
    }
  }
  printf("\n\n\n_________________________READY______________________");
  printList(ready);
  printf("\n - ______________SUPPORT___________");
  printList(support);
  printf("\n - ______________P___________");
  printList(p);

      deleteList(&ready);
      deleteList(&support);
      // deleteList(&p);
    // deleteList(&head);
}