#include <bits/stdc++.h>

using namespace std;

void fill(unsigned short *array, short n);
void mirror(unsigned short *array, short current);
void prefix(unsigned short *array, short current);

int main()
{
    short n;
    cin >> n;
    if((n >= 1) && (n <= 10))   //even though 1 <= n <= 10 is assured, I included this in case I accidentally enter an invalid n while testing
    {
        short size = pow(2, n);
        unsigned short array[size];
        fill(array, n);
        for(short out = 0; out < size; out++)
        {
            //cout << "[" << out << "]\t- " << array[out] << endl;
            cout << array[out] << endl;
        }
    }
    return 0;
}

void fill(unsigned short *array, short n)
{
    short current = 2;  //set to 2 since the mirroring/prefixing starts at 2^2
    array[0] = 0;
    array[1] = 1;
    while(current <= n)
    {
        mirror(array, current);
        prefix(array, current);

        current++;
    }
}
void mirror(unsigned short *array, short current)
{
    short mid = pow(2, (current - 1));
    //cout << "mid:\t" << mid << endl;
    for(short copy = (mid - 1), paste = mid; copy >= 0; copy--, paste++)
    {
        array[paste] = array[copy];
        //cout << "copy:\t" << copy << "\t[copy]: " << array[copy] << endl << "paste:\t" << paste << "\t[paste]: " << array[paste] << endl;
    }
}
void prefix(unsigned short *array, short current)
{
    short mid = pow(2, (current - 1));
    for(short fix = mid; fix < pow(2, current); fix++)
    {
        //cout << "fix1:\t" << array[fix] << "\t";
        array[fix] = array[fix] | mid;  //the binary of the number 2^(current-1) always starts with 1 and is followed by zeroes
        //cout << "fix2:\t" << array[fix] << endl;
    }
}

//REFERENCES:
/*
http://www.cplusplus.com/reference/cmath/pow/
https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
*/
