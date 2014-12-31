#ifndef __NODE.H__
#define __NODE.H__
#define ALPHABET_SIZE ( 26 )


struct node {
    int isLeaf;
    node* char[ALPHABET_SIZE];
}

typedef struct node Node;

#endif
