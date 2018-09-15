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
    int x, n, a, b;

    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << endl;

	cout << "get NBits: " << getNBits(x, n) << endl;
    cout << "flip_n: " << flip_n(x, n) << endl;
    cout << "flip_range: " << flip_range(x, a, b) << endl;
    cout << "getMSOB: " << getMSOB(x) << endl;
    cout << "getMSOB2: " << getMSOB2(x) << endl;
    cout << "getLSOB: " << getLSOB(x) << endl;

    return 0;
}
