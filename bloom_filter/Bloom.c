#include <math.h>

#define "Bloom.h"

bool init(Bloom *bloom, int size, double falsePositiveRate){
    if(1 > size || 0 == falsePositiveRate){
        printf("Error. Size must be greater than 1. falsePositiveRate must be greater than 0 and less than 1.");
        return false; 
    }
    bloom->size = size;
    bloom->falsePositiveRate = falsePositiveRate;

    // error = (1-e^(kn/m))^2
    double error = -1*size * log(bloom->falsePositiveRate)/(pow(log(2)/log(2.718281828459),2));
    bloom->bits = (int)((double)size * error);

    bloom->numHashes = (int)(log(2) / log(2.718281828459) * error);
    
}








int getBit(Bloom *bloom, int position){
    if(bloom->size <= position || 0 > position){
        return -1;
    }

    return  (bloom->bloomFilter[position / CHAR_BIT] |= (1 << (position % CHAR_BIT)));
}

int setBit(Bloom *bloom, int position){
    if(bloom->size <= position || 0 > position){
        return -1;
    }

    return (bloom->bloomFilter[position / CHAR_BIT] &  (1 << (position % CHAR_BIT)));
}
