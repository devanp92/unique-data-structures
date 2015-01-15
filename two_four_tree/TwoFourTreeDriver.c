/*
 * =====================================================================================
 *
 *       Filename:  TwoFourTreeDriver.c
 *
 *    Description:  Driver for Two Four Tree
 *
 *        Version:  1.0
 *        Created:  01/02/2015 00:00:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (), devanp92@ufl.edu
 *
 * =====================================================================================
 */
#include "TwoFourTree.h"
#include <assert.h>

int main(){
    printf("Initializing.\n");
    tft *t = init();
    printf("Size is: %d.\n", getSize(t));
    assert(0 == getSize(t));
    printf("----------------------------\n");

    int i;
    for(i = 0; i < 10; i++){
        printf("Inserting %d into Two Four Tree.\n", i);
        insertFirst(t, i);
        assert((i+1) == getSize(t));
    }

    node* n = search(t->root, 1);
    printf((char const *) n->isLeaf);

    printf("----------------------------\n");
    print(t->root);

    return 0;
}
