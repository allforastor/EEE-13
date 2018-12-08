#include <iostream>
#include <vector>

using namespace std;

class Item
{ public:
    int v;
    int w;
    int k;
};

vector<vector<int>> memo;

int max(int a, int b) { return (a > b)? a : b; }
int fill(Item arr[], int n, int c)
{
    memo.resize(n + 1, vector<int> (c + 1, 0));

    int i = 0;
    int temp[c + 1] = {0};  //holds the values of the previous row

    for(int j = 1; j <= c; j++)
    {
        if(i >= n)
        {
            break;
        }

        if(arr[i].w <= j)
        {
            memo[i + 1][j] = max(arr[i].v + temp[j - arr[i].w], temp[j]);
        }
        else
        {
            memo[i + 1][j] = temp[j];
        }

        if(j == c)
        {
            for(int x = 0; x <= c; x++)     //copies the row for future reference
            {
                temp[x] = memo[i + 1][x];
            }
            if(arr[i].k > 1)    //stops the for loop from moving to the next row
            {
                arr[i].k--;
            }
            else
            {
                i++;
            }
            j = 0;  //returns to the beginning of the column
        }
    }

    return memo[n][c];
}

int main()
{
    int n, c;

    cin >> n;

    Item arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].v >> arr[i].w >> arr[i].k;
    }
    cin >> c;

    /*
    printf("Item number\tValue\tWeight\tQuantity\n");
    for(int i = 0; i < n; i++)
    {
        printf("Item #%d\t\t  %d\t  %d\t   %d\n", (i + 1), arr[i].v, arr[i].w, arr[i].k);
    }
    */

    int total = fill(arr, n, c);

    cout << total << endl;
}

//REFERENCES
/*
    https://www.youtube.com/watch?v=xOlhR_2QCXY
    https://stackoverflow.com/questions/10164263/how-to-pass-two-dimensional-array-of-an-unknown-size-to-a-function#
    https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
    https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
    https://www.dyclassroom.com/dynamic-programming/0-1-knapsack-problem
*/
