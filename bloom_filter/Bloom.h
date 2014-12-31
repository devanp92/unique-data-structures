#ifndef __BLOOM.H__
#define __BLOOM.H__

/* Bloom Struct
 *
 * int* bloomFilter - Bit array for inserted elements
 * int numHashes - Number of hash functions desired
 * int size - Size of the bloomFilter
 * int numElementsToBeExpected - number of elements expected to be inserted
 * int count - number of elements inserted into bloom filter
 * int bits - number of number of elements expected to be inserted
 * int bytes - 
 *
 */
struct bloom {
    unsigned char* bloomFilter;
    int numHashes;
    int size;
    double falsePositiveRate;
    int bits, bytes;
    int count;
}

typedef struct bloom Bloom;

/* Init the bloom filter.
 *
 * @param bloom - This is the newly constructed bloom filter.
 * @param size - size of the bloom filter.
 * @param falsePositiveRate - false positive  rate.
 *
 * @return returnValue - False if falsePositiveRate, true otherwise.
 *
 * k = numberHashFunctions
 * m = bits in filter
 * n = elements that are expected to be inserted
 *
 * Since the false positive rate is (1-e^(k*n/m))^k, we can optimize the bloom filter by choosing a ballpark value for n, then m, then the optimal value for k. Lastly, we will calculate the falsePositiveRate rate for n, m, and k. If if is unacceptable, change m and recalculate; otherwise we're done
 *
 * Given m and n, the optimal value for k is (m/n)ln(2).
 * http://billmill.org/bloomfilter-tutorial 
 */

bool init(Bloom *bloom, int size, double falsePositiveRate); 

/* Inserts a given element.
 * 
 * @param
 * @return bool - False if not initialized or falsePositiveRate, true otherwise.
 *
 */
bool put();

/* Returns the bit at the current element
 *
 * @param position - element position
 *
 * @return bit - returns 0 or 1
 */
int getBit(Bloom *bloom, int position);

/* Sets the bit at the given position
 *
 * @param position - element position
 *
 * @return value - error code (if any)
 */
int setBit(Bloom *bloom, int position);
#endif
