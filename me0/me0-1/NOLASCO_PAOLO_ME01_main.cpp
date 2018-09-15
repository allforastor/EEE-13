#include <iostream>
#include <math.h>

extern int getNBits(int x, int n);
extern int flip_n(int x, int n);
extern int flip_range(int x, int a, int b);
extern int getMSOB(int x);
extern int getMSOB2(int x);
extern int getLSOB(int x);

using namespace std;

int main()
{
    int x, n;

    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;
    cout << endl;

	cout << "get NBits: " << getNBits(x, n) << endl;
    cout << "flip_n: " << flip_n(x, n) << endl;

    return 0;
}
