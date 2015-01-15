/*
 * =====================================================================================
 *
 *       Filename:  TwoFourTree.c
 *
 *    Description:  Implementation of Two Four Tree
 *
 *        Version:  1.0
 *        Created:  01/01/2015 23:59:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Devan Patel (), devanp92@ufl.edu
 *
 * =====================================================================================
 */
#include "TwoFourTree.h"
#include <assert.h>

tft* init() {
    printf("Initializing Two Four Tree.\n");
    tft *t = malloc(sizeof(tft));
    t->root = initNode();
    t->size = 0;
    assert(0 == t->size);
    return t;
}

node* insertFirst(tft* t, int element) {
    node* temp;
    temp = initNode();
    if(3 == t->root->numChildren) {
        temp->children[0] = t->root;
        temp->isLeaf = 0;
        t->root = temp;
        splitTree(temp, 0);
        return insert(t, temp, element);
    } else {
        return insert(t, t->root, element);
    }
}
node* insert(tft* t, node* n, int element) {
    int i = 0;
    while (i < n->numChildren && element > n->keys[i]) {
        i++;
    }
    if (n->isLeaf) {
        int j;
        for (j = n->numChildren; j > i; j--) {
            n->keys[j] = n->keys[j-1];
        }
        n->keys[j] = element;
        n->numChildren++;
        t->size++;
        return n;
    } else {
        if (3 == n->children[i]->numChildren) {
            splitTree(n , i);
            if (element > n->keys[i]) {
                i++;
            }
        }
        return insert(t, n->children[i], element);
    }
}

void splitTree(node* n, int position) {
    node* temp;
    temp = n->children[position];
    node* cur;
    cur = initNode();
    int i;
    for (i = n->numChildren; i > position; i--) {
        n->children[i+1] = n->children[i];
        n->keys[i] = n->keys[i-1];
    }
    n->keys[position] = temp->keys[1];
    n->children[position+1] = cur;
    n->numChildren++;
    if (temp->isLeaf) {
        cur->isLeaf = 1;
        for (i = 0; i < 1; i++) {
            cur->keys[i] = temp->keys[i + 2];
            cur->numChildren++;
        }
        temp->numChildren = 1;
    } else {
        cur->isLeaf = 0;
        for (i = 0; i < 1; i++) {
            cur->keys[i] = temp->keys[i + 2];
            cur->children[i] = temp->children[i + 2];
            cur->numChildren++;
        }
        cur->children[1] = temp->children[2];
        temp->numChildren = 1;
    }
}

node* search(node* n, int element) {
    if(n->isLeaf) {
        return n;
    }
    int i;
    i = 0;
    while(i < n->numChildren && element > n->keys[i]) {
        i++;
    }
    if(element == n->keys[i]) {
        return n;
    } else{
        return search(n->children[i], element);
    }
}

int getSize(tft* t){
    return (!t) ? -1 : t->size;
}

node* initNode(){
    node* temp = malloc(sizeof(node));
    int i;
    for(i = 0; i < 3; i++){
        temp->children[i] = 0;
        temp->keys[i] = 0;
    }
    temp->children[3] = 0;
    temp->numChildren = 0;
    temp->isLeaf = 1;
    return temp;
}

void destruct(tft* t, node* n) {
    if(!t->root) {
        return;
    }
    destruct(t, t->root->children[0]);
    destruct(t, t->root->children[1]);
    destruct(t, t->root->children[2]);
    destruct(t, t->root->children[3]);
    free(n);
}

void print(node* n) {
    if (!n) {
        printf("Sorry no node there.\n");
        return;
    } else if (1 > n->numChildren) {
        printf("There are no keys in this node.\n");
        return;
    }
    printf("Node's children are: \n");
    int i;
    for (i = 0; i < n->numChildren - 1; i++) {
        printf("Child %d is: %d.\n", i, n->keys[i]);
    }
    printf("Child %d is: %d.\n", i, n->keys[i]);
}