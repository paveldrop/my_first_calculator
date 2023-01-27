#include "s21_smartcalc.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void push(double value, int prior, TYPE type_value, stack **head) {
    
    stack *tmp = (stack*)malloc(sizeof(stack));
    tmp->value = value;
    tmp->priority = prior;
    tmp->type = type_value;
    tmp->next = *head;
    *head = tmp;
}

void reverse(stack **head) {
    stack *prev = NULL;
    stack *current = *head;
    stack *next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head = prev;
}


void printList(stack *head) {
    printf("\n");
    while(head != NULL) {
        printf("%f = value| %d = priority| %d = type ->__", head->value, head->priority, head->type);
        // printList(head->next);
        head = head->next;
    }
    printf("\nNULL or stack is free\n");
}


// void deleteList(stack **head) {
//     stack *prev = NULL;
//     while((*head)->next) {
//         prev = *head;
//         *head = (*head)->next;
//         free(prev);
//     }
//     free(*head);
// }

// stack *deleteList(stack *head) {
//     while (head != 0) {
//         stack *p = head;
//         head = head-> next;
//         free(p);
//     }
//     free(head);
//     return NULL;
// }

void deleteList(stack **head) {
    if (head != NULL) {
        stack *prev = NULL;
        while ((*head)->next) {
            prev = *head;
            *head = (*head)->next;
            free(prev);
        }
    free(*head);
    } else {
        printf("\nStrack is EMPTY\n");
    }
}


void pushback(double value, int priority_value, TYPE type_value, stack **head) {
        if (*head != NULL) {
            stack *last = getLast(*head);
            stack *tmp = (stack*) malloc(sizeof(stack));
            tmp->value = value;
            tmp->priority = priority_value;
            tmp->type = type_value;
            tmp->next = NULL;
            last->next = tmp;
        } else {
            push(value, priority_value, type_value, head);
        }
}

stack *getLast(stack *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

double pop(stack **head) {
    stack *prev = NULL;
    double val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

// void popBack(stack **head) {
//     stack *current = NULL;  //текущий узел
//     stack *prev = NULL;  //предыдущий узел
//     //Получили NULL
//     if (!head) {
//         exit(-1);
//     }
//     //Список пуст
//     if (!(*head)) {
//         exit(-1);
//     }
//     current = *head; 
//     while (current->next) { 
//         prev = current;
//         current = current->next;
//     }
//     if (prev == NULL) {
//         free(*head);
//         *head = NULL;
//     } else {
//         free(current->next);
//         prev->next = NULL;
//     }
// }

void popBack(stack** head){
    stack *temp = *head;
    stack * previous;

    if (*head == NULL){
        printf("Linked List Empty, nothing to delete");
        return;
    }

    if (temp->next == NULL){
        printf("%f deleted\n",(*head)->value);
        *head = NULL;
        return;
    }
    while (temp->next != NULL) 
    {
        previous = temp; 
        temp = temp->next; 
    }

    previous->next = NULL;

    printf("%f deleted\n", temp->value);
    free(temp);
}

int search_pos_elem(stack *head) {
    stack *current = NULL;
    int count = 0;
    
    if (head == NULL) {
      count = -1; // error if node not init
    }
    current = head;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
 
stack *peek(stack *head, int pos){
    // struct Node* ptr = top;
    int counter = 0;
    while (counter < pos && head) {
        head = head->next;
        counter++;
    }
    if (head != NULL) {
        return head;
    } else {
        return NULL;
    }
}

int peek_type(stack *head){
    if(head != NULL){
        return head->type;
    } else {
        return -999; // обработка ошибок
    }
}

stack *LastElem(stack *head) {
    stack *current = NULL;
    current = head;
    if (current == NULL) {
        return NULL;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

void create_Node(double value, int priority_value, TYPE type_value, stack **head) {
    // stack *tmp;
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->next = NULL;
    temp->value = value;
    temp->priority = priority_value;
    temp->type = type_value;
    *head = temp;
}

