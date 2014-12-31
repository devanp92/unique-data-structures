#ifndef __TRIE_H__
#define __TRIE_H__
#include "Node.h"
#include <stdlib.h>
#include <string.h>

struct Trie;

typedef struct trie {
    Node *root;
    int count;
} Trie;


/* Initialized with empty root and count */
void init(Trie* temp);

/* Returns a new Node */
Node* getNode(void);

/* Insert new Node */
void insert(Trie* temp, char key[]);

/* Searches for Node. Returns -1 if not present */
int search(Trie* temp, char key[]);

#endif
