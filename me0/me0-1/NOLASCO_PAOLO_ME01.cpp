#include <iostream>
#include <math.h>

using namespace std;

/*
 * Returns an integer with the the first n least significant bits the same as x's, and the rest as 0
 * Example: getNBits(13,3) = 5
 * 13 (0000 1101) => 5 (0000 0101)
 */
int getNBits(int x, int n)
{
    int sigbits = pow(2, n) - 1;
    return x & sigbits;
}

/*
 * Returns an integer which is x, but with the first n least significant bits flipped (0->1, 1->0)
 * Example: flip_n(13,3) = 10
 * 13 (0000 1101) => 10 (0000 1010)
 */
int flip_n(int x, int n)
{
    int toflip = pow(2, n) - 1;
    return x ^ toflip;
}

/*
 * Returns an integer which is x, but with the a range of bits flipped
 * from a to b, inclusive, starting from the least significant bit (bit 0)
 * Example: flip_range(13,2,5) = 10
 * 13 (0000 1101) => 49 (0011 0001)
 */
int flip_range(int x, int a, int b);

/*
 * Returns an integer which is the most significant on-bit of x
 * If it does not exist, return 0
 * Example: getMSOB(74) = 64
 * 74 (0100 1010) => 64 (0100 0000)
 */
int getMSOB(int x);

/*
 * Returns an integer which is the *second* most significant on-bit of x
 * If it does not exist, return 0
 * Example: getMSOB2(74) = 8
 * 74 (0100 1010) => 8 (0000 1000)
 */
int getMSOB2(int x);

/*
 * Returns an integer which is the least significant on-bit of x
 * If it does not exist, return 0
 * Example: getLSOB(74) = 2
 * 74 (0100 1010) => 2 (0000 0010)
 */
int getLSOB(int x);

/*
 * Bonus challenge:
 * Implement all functions (except getMSOB and getMSOB2) without using any loops.
 */
