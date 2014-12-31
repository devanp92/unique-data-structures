#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Bloom.h"
#include "GeneralHashFunctions.h"

#define LOG_E log(2.718281828459)
#define LOG_2 log(2)

int init(Bloom *bloom, int size, double falsePositiveRate) {
    if (0 >= size || 0 >= falsePositiveRate) {
        printf("Size must be greater than 0. False Positive Rate must be greater than 0.\n");
        return -1;
    }

    printf("Initializing Bloom Filter\n");
    bloom->bloomFilter = (unsigned char *) calloc((unsigned int) size, sizeof(unsigned char));
    bloom = malloc(sizeof(Bloom));

    bloom->size = size;
    double error = -1 * size * log(bloom->falsePositiveRate) / (pow(LOG_2 / LOG_E, 2));
    int bits = (int) ((double) size * error);
    int bytes = (bits) ? bits / 8 + 1 : bits / 8;
    bloom->bloomFilter = (unsigned char *) calloc((unsigned int) bytes, sizeof(unsigned char));
    bloom->numHashes = (int) (LOG_2 / LOG_E * error);

    return 1;
}

int put(Bloom *bloom, const char *input) {
    printf("Inserting key: %s\n", input);

    if (!bloom) {
        return 0;
    }
    unsigned int *hashes = calloc(bloom->size, sizeof(unsigned int));
    hashInput(hashes, (char *) input);
    int i;
    for (i = 0; i < bloom->numHashes; ++i) {
        hashes[i] = (hashes[i] >> bloom->size) ^ (hashes[i] & ((1 << (bloom->size - 1))));
        bloom->bloomFilter[hashes[i] >> 3] |= 1 << (hashes[i] & 7);
    }

    return 1;
}

int get(Bloom *bloom, const char *input) {
    printf("Searching for key: %s\n", input);

    if (!bloom) {
        return 0;
    }
    unsigned int *hashes = malloc(sizeof(unsigned int) * bloom->size);
    hashInput(hashes, (char *) input);
    int i;
    for (i = 0; i < bloom->numHashes; ++i) {
        hashes[i] = (hashes[i] >> bloom->size) ^ (hashes[i] & ((1 << (bloom->size - 1))));
        if (0 == (bloom->bloomFilter[hashes[i] >> 3] & (1 << hashes[i] & 7))) {
            printf("%s is definitely not in the bloom filter\n", input);
            return 0;
        }
    }
    printf("%s might be in the bloom filter\n", input);
    return 1;
}

unsigned int *hashInput(unsigned int *hashes, char *input) {
    unsigned int length = (unsigned int) strlen(input);

    hashes[0] = RSHash(input, length);
    hashes[1] = DJBHash(input, length);
    hashes[2] = FNVHash(input, length);
    hashes[3] = JSHash(input, length);
    hashes[4] = PJWHash(input, length);
    hashes[5] = SDBMHash(input, length);
    hashes[6] = DEKHash(input, length);

    return hashes;
}

int destruct(Bloom *bloom) {
    printf("Freeing bloom filter into memory heaven!\n");

    if (!bloom) {
        return 0;
    } else {
        free(bloom->bloomFilter);
    }

    return 0;
}