#include "Trie.h"
#include <stdio.h>

int main(){
    char* a = "Hi";
    char* b = "my";
    char* c = "name";
    char* d = "is";
    char* e = "Devan";

    Trie trie;
    init(&trie);
    
    printf("---------------------------------------\n");

    insert(&trie, a);
    insert(&trie, b);
    insert(&trie, c);
    insert(&trie, d);
    insert(&trie, e);

    printf("---------------------------------------\n");

    printf("%s = %d\n", "Hi", search(&trie, "Hi"));
    printf("%s = %d\n", "Hit", search(&trie, "Hit"));
    printf("%s = %d\n", "names", search(&trie, "names"));
    printf("%s = %d\n", "Devan", search(&trie, "Devan"));

    printf("---------------------------------------\n");

    destruct(&trie);

    return 0;
}
