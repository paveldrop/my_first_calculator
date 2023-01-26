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
        printf("%f = value| %d = priority| %d = type ->", head->value, head->priority, head->type);
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

stack *deleteList(stack *head) {
    while (head != 0) {
        stack *p = head;
        head = head-> next;
        free(p);
    }
    free(head);
    return NULL;
}

// void push_back(double value, int priority_value, TYPE type_value, stack *head) {
//     // # Force tail constraints, new tail must be end of list.
//     value->next = 0;
//     // item.next = null
//     priority_value->next = 0;
//     type_value->next = 0;

//     //# If list empty, simply set head/tail.

//     if (stack *head == NULL) {
//         list.head = item
//         list.tail = item
//         return
//     }

//     # In non-empty list, tail will always be last element.

//     curr.tail.next = item   # Point current tail to new tail.
//     curr.tail = item        # Update tail
//     }

void pushback(double value, int priority_value, TYPE type_value, stack **head) {
        stack *last = (stack*) malloc(sizeof(stack));
        if (getLast(*head) == NULL) {
            last->value = value;
            last->priority = priority_value;
            last->type = type_value;
            last->next = NULL;
            *head = last;
        } else {
            stack *tmp = (stack*) malloc(sizeof(stack));
            tmp->value = value;
            tmp->priority = priority_value;
            tmp->type = type_value;
            tmp->next = NULL;
            last->next = tmp;
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

void popBack(stack **head) {
    stack *current = NULL;  //текущий узел
    stack *prev = NULL;  //предыдущий узел
    //Получили NULL
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
    current = *head; 
    while (current->next) { 
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(current->next);
        prev->next = NULL;
    }
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
    for (int i = 0; (i < pos-1 && head!=NULL); i++)
    {
        head = head->next;
    }
    if(head!=NULL){
        return head;
    } else {
        return NULL;
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

