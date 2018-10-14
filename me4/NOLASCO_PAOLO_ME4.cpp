#include <iostream>

using namespace std;

int ave(int n, int nums[], int m);
void sort(int n, int nums[], int order[]);
void assign(int n, int nums[], int m);

int main()
{
    int m, n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> m;

    assign(n, nums, m);

    return 0;
}

void assign(int n, int nums[], int m)
{
    int mean = ave(n, nums, m);

    int order[n];
    for(int i = 0; i < n; i++)
    {
        order[i] = i;
    }
    printf("\n%d\n\n", mean);

    sort(n, nums, order);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", order[i]);
    }
    printf("\n");
}

int ave(int n, int nums[], int m)
{
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        total = total + nums[i];
    }
    total = total / m;

    return total;
}

void sort(int n, int nums[], int order[])
{
    for(int leading = 1; leading < n; leading++)
    {
        int current = order[leading];
        int trailing = leading - 1;
        while((trailing >= 0) && (nums[order[trailing]] < nums[current]))
        {
            order[trailing + 1] = order[trailing];
            trailing = trailing - 1;
        }
        order[trailing + 1] = current;
    }
    cout << "done sort" << endl;
}

//REFERENCES:
/*
    https://www.toptal.com/developers/sorting-algorithms
*/
