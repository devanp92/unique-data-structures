/*
 * =====================================================================================
 *
 *       Filename:  Queap.h
 *
 *    Description: "In computer science, a queap is a priority queue data structure. The data structure allows insertions and deletions of arbitrary elements, as well as retrieval of the highest-priority element" (https://en.wikipedia.org/wiki/Queap)
 *              
 *              Contains the following operations:
 *                      - init(Q)
 *                      - insert(Q,x)
 *                      - min(Q)
 *                      - delete(Q,x)
 *                      - deleteMin(Q)
 *                      - cleanUp(Q)
 *
 *        Version:  1.0
 *        Created:  01/01/2015 21:30:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (dp), devanp92@ufl.edu
 *
 * =====================================================================================
 */
/*
 * L = doubly linked list
 * minL =  pointer that points to the minimum element in L
 * c_{x_0} = minimum element stored in the T
 * T = 2-4 tree
 * k = number of elements stored in T 
 * n = total number of elements stored in queap Q
 * Q = Queap
 *
 */
#include <stdlib.h>
#include <stdio.h>

struct queap;

typedef struct queap {
    int size;
    int numElementsInT;
    int minElementInT;
    QueapTree qT;
    LinkedList dLL;
} Queap;


void init(Queap* q);


