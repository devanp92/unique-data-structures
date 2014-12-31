#include "Trie.h"

void init(Trie* temp) {
    temp->root = getNode();
    temp->val = 0;
}

Node* getNode(void) {
    Node* temp = NULL;
    temp = (Node *) malloc(sizeof(Node));
    if(temp) {
        temp->isLeaf = 0;
        int i;
        for(i = 0; i < ALPHABET_SIZE; i++) {
            temp->children[i] = NULL;
        }
    }
    return temp;
}

void insert(Trie* temp, char key[]) {
    int i, length = strlen(key), index;
    Node* cur;

    for(i = 0; i < length; i++) {
        index = (int) key[i] - (int) 'a';

        if(!cur->children[index]) {
            cur->children[index] = getNode();
        }

        cur = cur->children[index];
    }
    cur->isLeaf = trie->val;
}

int search(Trie* temp, char key[]) {
    int i, length = strlen(key), index;
    Node* cur;
    cur = temp->root;

    for(i = 0; i < length; i++) {
        index = (int) key[i] - (int) 'a';
        
        if(!cur->children[index]) {
            return 0;
        }

        cur = cur->children[index];
    }
    return (0 != temp && temp->val);
}
