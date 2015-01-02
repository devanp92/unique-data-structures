/*
 * =====================================================================================
 *
 *       Filename:  linked_list.h
 *
 *    Description:  Doubly Linked List
 *
 *        Version:  1.0
 *        Created:  01/01/2015 21:38:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (), devanp92@ufl.edu
 * =====================================================================================
 */

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define LIST_FOR_EACH(L, F, N, C) node* temp;\
    node* cur;\
    for(C = temp = L->F; temp; cur = temp = temp->N)

#include <stdlib.h>
#include <stdio.h>
#include "node.h"


typedef struct linked_list {
    struct node* first;
    struct node* last;
    int size;
} linked_list;


/*
 *  Initializes the double linked list
 *
 *  @param linked_list - linked list to initialize
 *
 */

void init(linked_list*);

/*
 * Insert element into LL
 *
 * @param linked_list - linked list to insert element in
 * @param element - element to insert
 *
 */
void insert(linked_list*, int);

/*
 * delete element from LL
 *
 * @param linked_list - linked list to insert element in
 * @param element - element to delete
 *
 * @return ERRNO - 1 if element is deleted, -1 if error
 *
 */
int delete(linked_list*, node*);


/*
 * Returns the number of elements in the linked list
 *
 * @param linked_list - linked list to get size from
 *
 * @return size - number of elements
 */

int getSize(linked_list*);

#endif
