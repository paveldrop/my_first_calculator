#include "s21_smartcalc.h"
#include <stdio.h>


void rpn(stack **head) {
  stack *p = NULL;
  stack *ready = NULL;
  stack *support = NULL;
  int length_ready = 0;
  int length = search_pos_elem(*head);
//   p = getLast(head);
//   p = head;
  reverse(head);
  for (int i = 0; i < length; i++) {
    printf("\n - ______________SUPPORT before pushback recurce %d___________", i);
    printList(support);
    printf("\n\n\n_________________________READY______________________");
    printList(ready);
    p = peek(*head, i);
    printf("\n list in rpn p_TYPE_%d", p->type);
    printList(p);
    if (p->type == 0) {
        pushback(p->value, p->priority, p->type, &ready);
        // popBack(&p);
    }
    if (p->priority == 1) {
      if (support == NULL) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (support->priority == 1) {
        pushback(support->value, support->priority, support->type, &ready);
        popBack(&support);
        pushback(p->value, p->priority, p->type, &support);
      } else if (support->priority > 1) {
        pushback(support->value, support->priority, support->type,  &ready);
        popBack(&support);
        pushback(p->value, p->priority, p->type, &support);
      }
    }
    if (p->priority == 2) {
      if (support == NULL) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (support->priority < 2) {
        pushback(support->value, support->priority, support->type, &ready);
      } else if (support->priority >= 2) {
        pushback(support->value, support->priority, support->type, &ready);
      }
    }

    // if (p->type != 0 && p->type != 17) {
        
    //     // popBack(&p);
    // }
    if (p->type == 17) {
        length_ready = search_pos_elem(support) - search_type_elem(bracket_open, &support) + 1;
        printf("zdes' error %d kolichestvo elements %d, zdes' bracket %d\n", length_ready, search_pos_elem(support),search_type_elem(bracket_open, &support));
        if (length_ready == 1) {
          popBack(&support);
        } else {
          for (int j = 0; j < length_ready; j++) {
            pushback(support->value, support->priority, support->type, &ready);
            popBack(&support);
          }
        }
      }
  }
    // pushback(support->value, support->priority, support->type, &ready);
    printf("\n\n\n_________________________READY______________________");
    printList(ready);
    printf("\n - ______________SUPPORT before pushback recurce ___________");
    printList(support);
  // stack *last = NULL;
  // while(support != NULL) {
  //   last = getLast(support);
  //   pushback(last->value, last->priority, last->type, &ready);
  //   popBack(&support);
  // }
  move_all_in_Ready (&support,&ready);

  
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