#ifndef __TRIE.H__
#define __TRIE.H__
#include "Node.h"

struct trie {
    Node *root;
    int val;
}

typedef struct trie Trie;

/* Initialized with empty root and count */
void init(Trie* temp);

/* Returns a new Node */
Node* getNode(void);

/* Insert new Node */
void insert(Trie* temp, char key[]);

/* Searches for Node. Returns -1 if not present */
int search(Trie* temp, char key[]);

#endif
