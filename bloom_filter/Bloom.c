#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Bloom.h"
#include "PMurHash.h"

int init(Bloom *bloom, int size, int numHashes) {

    if (!size || !numHashes) {
        printf("Size must be greater than 0. Number of hashes must be greater than 0.\n");
        return -1;
    }
    memset(bloom, 0, sizeof(*bloom));
    bloom->size = size;
    bloom->numHashes = numHashes;
    bloom->bloomFilter = (unsigned int *) malloc(sizeof(int) * size >> 3);

    return 1;
}

void put(Bloom *bloom, const char *input) {
    printf("Inserting key: %s.\n", input);

    int i;
    unsigned int tmp;

    for (i = 0; i < bloom->numHashes; i++) {
        tmp = (unsigned int) PMurHash32((uint32_t) rand(), input, (int) strlen(input));
        tmp %= bloom->size;
        printf("%d\n", tmp);
        setBit(bloom, tmp);
    }
}

int get(Bloom *bloom, const char *input) {
    printf("Searching for key: %s.\n", input);

    int i;
    unsigned int tmp;

    for (i = 0; i < bloom->numHashes; i++) {
        tmp = (unsigned int) PMurHash32((uint32_t) rand(), input, (int) strlen(input));
        tmp %= bloom->size;
        printf("%d\n", getBit(bloom, tmp));
        if (!getBit(bloom, tmp)) {
            printf("\"%s\" is definitely not in the bloom filter.\n\n", input);
            return -1;
        }
    }
    printf("\"%s\" might be in the bloom filter.\n\n", input);
    return 1;
}

int destruct(Bloom *bloom){
    printf("Freeing bloom's memory into bit heaven.\n");
    if(!bloom) {
        return -1;
    }
    free(bloom->bloomFilter);
    return 1;
}



void setBit(Bloom *bloom, int position) {
    bloom->bloomFilter[(position) >> 3] |= (0x1 << (0x7 - ((position) & 0x7)));
}

int getBit(Bloom *bloom, int position) {
    return bloom->bloomFilter[position];//bloom->bloomFilter[position >> 3] & (0x1 << (0x7 - (position & 0x7)));;
}



