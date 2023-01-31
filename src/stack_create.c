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
    printf("\nBEGIN\n");
    while(head != NULL) {
        // printf("%f = value| %d = priority| %d = type ->__", head->value, head->priority, head->type);
        printf("%f = value| %d = type <------   ", head->value, head->type);
        // printList(head->next);
        head = head->next;
    }
    printf("END");
    printf("\nNULL or stack is free\n");
}

void pull_to_bracket(stack **source, stack **dest) {
    stack *last = getLast(*source);
    while (last->type != bracket_open) {
        pushback(last->value, last->priority, last->type, dest);
        popBack(source);
        last = getLast(*source);
    }
    popBack(source);
}

void deleteList(stack **head) {
    if(*head != NULL) {
        if (head != NULL) {
            stack *prev = NULL;
            while ((*head)->next) {
                prev = *head;
                *head = (*head)->next;
                free(prev);
            }
        }
        free(*head);
    } else {
        free(*head);
        printf("\nStrack is EMPTY\n");
    }
}


void pushback(double value, int priority_value, TYPE type_value, stack **head) {
        if (*head != NULL) {
            stack *last = getLast(*head);
            stack *tmp = (stack*) malloc(sizeof(stack));
            // stack *tmp = NULL;
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

stack *getLastButOne(stack *head) {
    if (head == NULL) {
        exit(-2);
    }
    if (head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
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
    val = prev->type;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

void popBack(stack** head){
    stack *last = NULL;
    //Получили NULL
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
    last = getLastButOne(*head);
    //Если в списке один элемент
    if (last == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(last->next);
        last->next = NULL;
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

void pull_to_insert(stack **source, stack **dest) {
    stack *last = NULL;
    last = getLast(*source);
    pushback(last->value, last->priority, last->type, dest);
    popBack(source);
}

void move_all_in_Ready (stack **in_sup, stack **in_ready) {
    stack *last = NULL;
    while (*in_sup != NULL) {
        last = getLast(*in_sup);
        pushback(last->value, last->priority, last->type, in_ready);
        popBack(in_sup);
  }
}

char stack_to_array(stack *source, char *output) {
    while (source != NULL) {
        // if (source->type != 0) {
        //     sprintf(output + strlen(output), "%s ", source->type);
        
        // }
        sprintf(output + strlen(output), "%f ", source->value);
        source = source->next;
    }
    return *output;
}

int GetLastPriority(stack **source) {
    stack *last = NULL;
    last = getLast(*source);
    if (last == NULL) {
        return 0;
    }
    return last->priority;
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

int search_type_elem(TYPE type, stack **head) {
    stack *current = NULL;
    current = *head;
    int count = 0;
    int flag = 0;
    if (head == NULL) {
        exit(-1);
    }
    // if (head == NULL) {
    //     exit(-1);
    // }
    while (current != NULL || flag != 1) {
        if (current->type == type) {
            flag = 1;
        }
        current = current->next;
        count++;
        
    }
    return count;
}