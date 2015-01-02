/*
 * =====================================================================================
 *
 *       Filename:  LinkedList.c
 *
 *    Description: Implementation of linked list 
 *
 *        Version:  1.0
 *        Created:  01/01/2015 22:10:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (), devanp92@ufl.edu
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include  <string.h>
#include "LinkedList.h"

void init(linked_list* l) {
    printf("Linked List is being initialized\n");

    calloc(1, sizeof(l));
    l->size = 0;
}

void insert(linked_list* l, int element) {
    if(!l) {
        printf("Error.\n");
        return;
    }
    node* temp = calloc(1, sizeof(node));
    temp->val = element;

    if(!l->last) {
        l->first = temp;
        l->last = temp;
    } else {
        l->last->next = temp;
        temp->prev = l->last;
        l->last = temp;
    }
    l->size++;
}

int delete(linked_list* l, node* element) {
    if(!l || !getSize(&l)) {
        printf("Error.\n");

        return -1;
    }

    if(element == l->first && element == l->last) {
        l->first = l->last = 0;
    } else if(element == l->first) {
        l->first = element->next;
        l->first->prev = 0;
    } else if(element == l->last) {
        l->last = element->prev;
        l->last->next = 0;
    } else {
        node* next = element->next;
        node* prev = element->prev;
        next->prev = prev;
        prev->next = next;
    }
    l->size--;

    return 1;
}


int getSize(linked_list* l) {
    return (!l) ? -1 : l->size;
}
