#include <iostream>
#include <vector>

using namespace std;

class Item
{ public:
    int v;
    int w;
    int k;
};

int max(int a, int b) { return (a > b)? a : b; }
int fill(Item arr[], vector<vector<int>> &memo, int n, int c)
{
    cout << "fill" << endl;
    int result;
    int temp1, temp2;
    if(memo[n][c - 1] != -1)
    {
        cout << "CASE 1" << endl;
        return memo[n][c - 1];
    }
    else if((n == 0) || (c == 0))
    {
        cout << "CASE 2" << endl;
        result = 0;
    }
    else if(arr[n].w > c)
    {
        cout << "CASE 3" << endl;
        result = fill(arr, memo, (n - 1), c);
    }
    else
    {
        cout << "CASE 4" << endl;
        temp1 = fill(arr, memo, (n - 1), c);
        temp2 = arr[n].v + fill(arr, memo, (n - 1), (c - arr[n].w));
        result = max(temp1, temp2);
    }
    memo[n][c - 1] = result;
    return result;
}

int main()
{
    int n, c;

    cout << "Enter number of unique items: ";
    cin >> n;

    Item arr[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Item " << (i + 1) << ": ";
        cin >> arr[i].v >> arr[i].w >> arr[i].k;
    }
    cout << "Enter knapsack capacity: ";
    cin >> c;

    printf("Item number\tValue\tWeight\tQuantity\n");
    for(int i = 0; i < n; i++)
    {
        printf("Item #%d\t\t  %d\t  %d\t   %d\n", (i + 1), arr[i].v, arr[i].w, arr[i].k);
    }

    vector<vector<int>> memo;
    memo.resize(n, vector<int> (c, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }

    int total = fill(arr, memo, (n - 1), c);

    cout << "Filled knapsack value: " << total << endl;
}

//REFERENCES
/*
    https://www.youtube.com/watch?v=xOlhR_2QCXY
    https://stackoverflow.com/questions/10164263/how-to-pass-two-dimensional-array-of-an-unknown-size-to-a-function#
    https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
*/
