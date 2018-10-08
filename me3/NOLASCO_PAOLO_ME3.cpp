#include <iostream>
#include <stack>

using namespace std;

void span(int n, int heights[], int flooded[])
{
    flooded[0] = 1;
    stack<int> cities;

    cities.push(1);         //cities start at 1 since 0 is a wall

    for(int i = 2; i < (n - 1); i++)    //the parameters avoid including the walls
    {
        while((!cities.empty()) && (heights[cities.top()] <= heights[i]))
        {
            cities.pop();
        }
        if(!cities.empty())
        {
            flooded[i - 1] = i - cities.top();
        }
        else
        {
            flooded[i - 1] = i;
        }
        cities.push(i);
    }

    while(!cities.empty())
    {
        cities.pop();
    }
    
    cities.push(n - 2);     //cities start at (n - 2) since (n - 1) is a wall

    for(int i = (n - 3); i > 0; i--)    //the parameters avoid including the walls
    {
        while((!cities.empty()) && (heights[cities.top()] <= heights[i]))
        {
            cities.pop();
        }
        if(!cities.empty())
        {
            flooded[i - 1] = flooded[i -1] + (cities.top() - (i + 1));
        }
        else
        {
            flooded[i - 1] = flooded[i - 1] + ((n - 2) - i);
        }
        cities.push(i);
    }
}

void print(int n, int flooded[])
{
    for(int i = 0; i < n; i++)
    {
        cout << flooded[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int heights[n];
    int flooded[n - 2];  //the walls are not included

    for(int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    span(n, heights, flooded);
    print((n - 2), flooded);

    return 0;
}

//REFERENCES:
/*
    https://www.geeksforgeeks.org/the-stock-span-problem/
*/
