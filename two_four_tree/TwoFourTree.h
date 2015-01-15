/*
 * =====================================================================================
 *
 *       Filename:  TwoFourTree.h
 *
 *    Description:  "In computer science, a 2–3–4 tree (also called a 2–4 tree) is a self-balancing data structure that is commonly used to implement dictionaries." (https://en.wikipedia.org/wiki/2%E2%80%933%E2%80%934_tree)
 *      
 *                  The following functions will be included:
 *                      -init
 *                      -insertFirst
 *                      -delete
 *                      -search
 *                      -splitTree
 *                      -insert
 *
 *        Version:  1.0
 *        Created:  01/01/2015 23:47:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (), devanp92@ufl.edu
 *
 * =====================================================================================
 */
#ifndef __TWO_FOUR_TREE_H__
#define __TWO_FOUR_TREE_H__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Node.h"

typedef struct two_four_tree {
    node* root;
    int size;
} tft;

tft* init();

node* search(node* n, int element);

int delete(tft* t, int element);

node* insertFirst(tft* t, int element);

node* insert(tft* t, node* n, int element);

void splitTree(node* n, int position);

int getSize(tft* t);

node* initNode();

void destruct(tft* t, node* n);

void print(node* n);

#endif
