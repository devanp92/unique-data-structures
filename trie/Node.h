#ifndef __NODE_H__
#define __NODE_H__
#define ALPHABET_SIZE 26

struct Node;

typedef struct node {
    int isLeaf;
    struct node *children[ALPHABET_SIZE];
} Node;


#endif
