#include "s21_smartcalc.h"
#include <stdio.h>


stack *rpn(stack **head, stack **ready) {
  stack *p = NULL;
  stack *support = NULL;
  stack *pow_push = NULL;
  int lastprior = 0;
  int length = search_pos_elem(*head);
//   p = getLast(head);
//   p = head;
  // reverse(head);
  for (int i = 0; i < length; i++) {
    p = peek(*head, i);
    lastprior = GetLastPriority(&support);
    printf("\n\n\n\n ___________________________ITERATION - %d_____________________________________\nlist INPUT_PRIOR_%d________BEGIN", i, p->priority);
    printList(p);

    if (p->type == 0) {
        pushback(p->value, p->priority, p->type, ready);
        // popBack(&p);
    }
    if (p->priority == -2) {
      pushback(p->value, p->priority, p->type, &support);
    }
    if (p->priority == 1) {
      if (support == NULL) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior == 1) {
        pull_to_insert(&support, ready);
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior > 1 || lastprior == -2) {
        move_all_in_Ready(&support, ready);
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior == -1) {
        pushback(p->value, p->priority, p->type, &support);
      }
    }
    if (support != NULL) {
    printf("\n\n\n_____________________________________\nSUPPORT PRIORITY _last%d and first? %d", GetLastPriority(&support), support->priority);
    }
    if (p->priority == 2) {
      if (support == NULL) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior < 2) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior == 2) {
        pull_to_insert(&support, ready);
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior == 3) {
        pow_push = getLast(support);
        pushback(pow_push->value, pow_push->priority, pow_push->type, ready);
        popBack(&support);
        pushback(p->value, p->priority, p->type, &support);
      } else {
        move_all_in_Ready(&support, ready);
        pushback(p->value, p->priority, p->type, &support);
      }
      // printf("\n\n\n_____________________________________\nSUPPORT PRIORITY _%d", GetLastPriority(&support));
      
    }
    if (p->priority == 3) {
      // if (support == NULL) {
      //   pushback(p->value, p->priority, p->type, &support);
      // } else if (lastprior < 3) {
        pushback(p->value, p->priority, p->type, &support);
      // } else if (p->type == support->type && p->type == in_pow) {
      //   pushback(p->value, p->priority, p->type, &support);
      // } else if (lastprior == 3) {
      //   pull_to_insert(&support, ready);
      //   pushback(p->value, p->priority, p->type, &support);
      // } else {
      //   move_all_in_Ready(&support, ready);
      //   pushback(p->value, p->priority, p->type, ready);
      // }
    }

    if (p->priority == 4) {
      if (support == NULL) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior < 4) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (lastprior == 4) {
        pull_to_insert(&support, ready);
        pushback(p->value, p->priority, p->type, &support);
      } else {
        move_all_in_Ready(&support, ready);
        pushback(p->value, p->priority, p->type, &support);
      }
    }

    if (p->priority == -1) {
      if (support == NULL || p->type == bracket_open) {
        pushback(p->value, p->priority, p->type, &support);
      } else if (p->type == bracket_close) {
        pull_to_bracket(&support, ready);
        }
      }
      // printf("\n\n\n_____________________________________SUPPORT PRIORITY _%d", GetLastPriority(&support));
    printf("\n - ______________READY AFTER pushback recurce %d___________", i);
    printList(*ready);
    printf("\n\n\n_________________________SUPPORT______________________");
    printList(support);
  }
    printf("\n\n\n_________________________READY______________________");
    printList(*ready);
    printf("\n - ______________SUPPORT before pushback recurce ___________");
    printList(support);
  move_all_in_Ready (&support,ready);

  
  printf("\n\n\n_________________________READY______________________");
  printList(*ready);
  printf("\n - ______________SUPPORT___________");
  printList(support);
  printf("\n - ______________P___________");
  printList(p);

      // deleteList(&ready);
      deleteList(&support);
      // deleteList(&p);
    // deleteList(&head);
    return *ready;
}


// 1+8/2*8-2+5/8