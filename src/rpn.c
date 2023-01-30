#include "s21_smartcalc.h"
#include <stdio.h>


void rpn(stack **head) {
  stack *p = NULL;
  stack *ready = NULL;
  stack *support = NULL;
  int length_ready = 0;
  int lastprior = 0;
  int length = search_pos_elem(*head);
//   p = getLast(head);
//   p = head;
  reverse(head);
  for (int i = 0; i < length; i++) {
    p = peek(*head, i);
    lastprior = GetLastPriority(&support);
    printf("\n\n\n\n _________________________________________________________________\nlist in rpn p_PRIOR_%d________BEGIN", p->priority);
    printList(p);

    if (p->type == 0) {
        pushback(p->value, p->priority, p->type, &ready);
        // popBack(&p);
    }
    if (p->priority == 1) {
      if (support == NULL) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior == 1) {
        pull_to_insert(&support, &ready);
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior > 1) {
        move_all_in_Ready(&support, &ready);
        pushback(p->value, p->priority, p->type, &support);
      }
      printf("\n\n\n_____________________________________\nSUPPORT PRIORITY _%d", GetLastPriority(&support));
    }
    
    if (p->priority == 2) {
      if (support == NULL) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior < 2) {
        pushback(p->value, p->priority, p->type, &support);
        
      } else if (lastprior == 2) {
        pull_to_insert(&support, &ready);
        pushback(p->value, p->priority, p->type, &support);
      } else {
        move_all_in_Ready(&support, &ready);
        pushback(p->value, p->priority, p->type, &support);
      }
      printf("\n\n\n_____________________________________\nSUPPORT PRIORITY _%d", GetLastPriority(&support));
      
    }

    if (p->priority == 3) {
      if (support == NULL) {

      } else if (lastprior < 3) {
      
      } else if (lastprior == 3) {
      
      } else {
      
      }
    }
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
      printf("\n\n\n_____________________________________SUPPORT PRIORITY _%d", GetLastPriority(&support));
    printf("\n - ______________SUPPORT before pushback recurce %d___________", i);
    printList(support);
    printf("\n\n\n_________________________READY______________________");
    printList(ready);
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


// 1+8/2*8-2+5/8