/*
 * =====================================================================================
 *
 *       Filename:  Driver.c
 *
 *    Description:  Driver for Bloom Filter
 *
 *        Version:  1.0
 *        Created:  12/30/2014 23:11:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (dp), devanp92@ufl.edu
 *
 * =====================================================================================
 */
#include "Bloom.h"
#include <stdio.h>

int main(){

    Bloom bloom;
    init(&bloom, 50, .5);
    printf("---------------------------------------\n");
    put(&bloom, "Hi");
    put(&bloom, "my");
    put(&bloom, "name");
    put(&bloom, "is");
    put(&bloom, "Devan");
    printf("---------------------------------------\n");
    get(&bloom, "Something");
//    destruct(&bloom);
    return 0;
}