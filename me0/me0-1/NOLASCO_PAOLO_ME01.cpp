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
int flip_range(int x, int a, int b)
{
    int toflip = pow(2, ((b - a) + 1)) - 1;
    toflip = toflip << a;       //this shifts the 1's to the starting position (which is a)
    return x ^ toflip;
}

/*
 * Returns an integer which is the most significant on-bit of x
 * If it does not exist, return 0
 * Example: getMSOB(74) = 64
 * 74 (0100 1010) => 64 (0100 0000)
 */
int getMSOB(int x)
{
    int compare = 1;
    while(x > compare)
    {
        if(x > (x ^ compare))   //1 ^ 1 would return 0, which would lower the value of x
        {
            x = x ^ compare;
        }
        compare = compare << 1;
    }
    return x;
}

/*
 * Returns an integer which is the *second* most significant on-bit of x
 * If it does not exist, return 0
 * Example: getMSOB2(74) = 8
 * 74 (0100 1010) => 8 (0000 1000)
 */
int getMSOB2(int x)
{
    x = x ^ getMSOB(x);
    return getMSOB(x);
}

/*
 * Returns an integer which is the least significant on-bit of x
 * If it does not exist, return 0
 * Example: getLSOB(74) = 2
 * 74 (0100 1010) => 2 (0000 0010)
 */
int getLSOB(int x)
{
    return x & ~(x - 1);    //(x - 1) will make the LSOB into 0
                            //using & on the inverse would make the LSOB the only bit that is 1
}

/*
 * Bonus challenge:
 * Implement all functions (except getMSOB and getMSOB2) without using any loops.
 */

//GITHUB LINK:  https://github.com/allforastor/EEE-13
//REFERENCES:
/*No references. I was unable to make earlier commits since there was a power outage in Marikina for several hours during the storm (I just tried everything until they worked since there was nothing else to do).*/
