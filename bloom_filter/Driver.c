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
#include <string.h>

int main(){
    Bloom bloom;
//    memset(bloom, 0, sizeof(Bloom));
    init(&bloom, 100, 3);

    printf("---------------------------------------\n\n");

    put(&bloom, "H");
    put(&bloom, "m");
    put(&bloom, "n");
    put(&bloom, "i");
    put(&bloom, "D");

    printf("---------------------------------------\n\n");

    get(&bloom, "S");
    get(&bloom, "H");
    get(&bloom, "m");
    get(&bloom, "e");

    printf("---------------------------------------\n");

    destruct(&bloom);
    return 0;
}