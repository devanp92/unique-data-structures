/*
 * =====================================================================================
 *
 *       Filename:  LinkedListDriver.c
 *
 *    Description:  Driver for linked list
 *
 *        Version:  1.0
 *        Created:  01/01/2015 22:15:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (), devanp92@ufl.edu
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedList.h"

int main(){

    linked_list l;
    init(&l);

    printf("----------------------------\n");

    assert(0 == getSize(&l));

    int i;
    for(i = 0; i < 6; i++) {
        printf("Inserting %d into linked list.\n", i);

        insert(&l, i);
        assert((i+1) == getSize(&l));
    } 



    printf("----------------------------\n");
    printf("Removing node from linked list.\n");

    delete(&l, l.first->next);
    printf("Size is: %d.\n", getSize(&l));

    assert(5 == getSize(&l));
    

    printf("Removing node from linked list.\n");

    delete(&l, l.first->next);
    printf("Size is: %d.\n", getSize(&l));

    assert(4 == getSize(&l));

    return 0;
}


