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
    tft* t;
    printf("Initializing.\n");
    init(&t);
    printf("----------------------------\n");

    int i;
    for(i = 0; i < 6; i++){
        printf("Inserting %d into Two Four Tree.\n", i);

        insertFirst(&t, i);
    }
    return 0;
}
