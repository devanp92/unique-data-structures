#include "Trie.h"
#include <stdio.h>

void init(Trie* temp) {
    temp->root = getNode();
    temp->count = 0;
    printf("Trie has been initialized!\n");
}

Node* getNode(void) {
    Node* temp = NULL;
    temp = (Node *) malloc(sizeof(Node));
    if(temp) {
        temp->isLeaf = 0;
        int i;
        for(i = 0; i < ALPHABET_SIZE; i++) {
            temp->children[i] = 0;
        }
    }
    return temp;
}

void insert(Trie* trie, char key[]) {
    printf("Inserting the key: %s\n", key); 

    int length = strlen(key);
    Node* cur = trie->root;
    trie->count++;

    int i;
    int index;
    for(i = 0; i < length; i++) {
        index = (int) key[i] - (int) 'a';

        if(!cur->children[index]) {
            cur->children[index] = getNode();
        }

        cur = cur->children[index];
    }
    cur->isLeaf = trie->count;
}

int search(Trie* trie, char key[]) {
    printf("Searching for the key: %s\n", key);

    int length = strlen(key);
    Node* cur = trie->root;
    
    int i;
    int index;
    for(i = 0; i < length; i++) {
        index = (int) key[i] - (int) 'a';

        if(!cur->children[index]) {
            return 0;
        }

        cur = cur->children[index];
    }
    return (0 != cur && cur->isLeaf);
}

void destruct(Trie* trie){
    printf("Freeing trie to memory heaven!\n");

    free(trie->root);

}

