#include <iostream>
#include <string>
#include <queue>
#define MAX(a, b) (((a) < (b)) ? (a):(b))
#define SQR(a) ((a) * (a))
#define INF 99999

using namespace std;

vector<vector<int>> graph;

bool check(int n, string allowed[], string word)    //checks if the word is part of the dictionary
{
    for(int i = 0; i < n; i++)
    {
        if(allowed[i] == word)
            return true;
    }
    return false;
}
void forbid(int n, string allowed[], string word)   //forbids the word
{
    for(int i = 0; i < n; i++)
    {
        if(allowed[i] == word)
            allowed[i] = "";
    }
}
bool allow(int n, string dictionary[], string allowed[], string word)   //allows the word
{
    int effect = 0;
    for(int i = 0; i < n; i++)
    {
        if((dictionary[i] == word) && (allowed[i] != dictionary[i]))   //prevents useless calls of allow()
        {
            allowed[i] = dictionary[i];
            effect++;
        }
    }

    if(effect > 0)
        return true;
    else
        return false;
}
int index(int n, string dictionary[], string word)  //returns the index of the word from dictionary[]
{
    for(int i = 0; i < n; i++)
    {
        if(dictionary[i] == word)
            return i;
    }
    return -1;
}
int distance(int len, string dictionary[], int a, int b)    //returns the individual cost
{
    int dist = len;
    int start = 0;

    for(int j = 0; j < len; j++)
    {
        for(int i = start; i < len; i++)
        {
            if(dictionary[b][j] == dictionary[a][i])
            {
                dist--;
                start = i;     //so it won't check the letters before the previous valid letter
                break;
            }
        }
    }
    dist = dist * 2;

    return SQR(dist);
}
void ginit(int n, int len, string allowed[])    //initializes a graph with the allowed words
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            graph[i][j] = INF;
    }

    for(int i = 0; i < n; i++)
    {
        if(allowed[i] != "")           //restricts forbidden words
        {
            for(int j = 0; j < n; j++)
            {
                if(allowed[j] != "")   //restricts forbidden words
                {
                    if(i == j)
                        graph[i][j] = 0;        //distance to itself is always 0
                    else
                        graph[i][j] = distance(len, allowed, i, j);
                }
            }
        }
    }
}
int cost(int n, int n1, int n2)     //returns the shortest path's cost
{
    int fwgraph[n][n];

    for(int i = 0; i < n; i++)      //sets the whole 2D array to INF
    {
        for(int j = 0; j < n; j++)
            fwgraph[i][j] = graph[i][j];
    }

    for(int k = 0; k < n; k++)      //floyd warshall algorithm
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(fwgraph[i][k] + fwgraph[k][j] < fwgraph[i][j])       //finds shorter paths
                    fwgraph[i][j] = fwgraph[i][k] + fwgraph[k][j];
            }
        }
    }

    return fwgraph[n1][n2];
}


int main()
{
    int n, q, len;
    cin >> n;

    graph.resize(n, vector<int> (n, INF));

    cin >> q;
    string dictionary[n], allowed[n];
    for(int i = 0; i < n; i++)
    {
        cin >> dictionary[i];
        if(i == 0)
        {
            len = dictionary[0].length();
            allowed[i] = dictionary[i];
        }
        else if((int)dictionary[i].length() == len)
            allowed[i] = dictionary[i];
        else
        {
            cout << ">>ERROR: words must be of the same length" << endl;
            i--;
        }
    }

    queue<int> clist;       //queue used for FIFO purposes
    string query, param1, param2;
    while(q > 0)
    {
        cin >> query;

        if(query == "COST")
        {
            cin >> param1;
            cin >> param2;
            if((check(n, allowed, param1) == true) && (check(n, allowed, param2) == true))
            {
                ginit(n, len, allowed);
                int n1 = index(n, dictionary, param1);
                int n2 = index(n, dictionary, param2);
                clist.push(cost(n, n1, n2));
                q--;
            }
            else
                cout << ">>ERROR: words must currently be in the dictionary" << endl;
        }
        else if(query == "FORBID")
        {
            cin >> param1;
            if(check(n, allowed, param1) == true)
            {
                forbid(n, allowed, param1);
                q--;
            }
            else
                cout << ">>ERROR: word must currently be in the dictionary" << endl;
        }
        else if(query == "ALLOW")
        {
            cin >> param1;
            if(check(n, dictionary, param1) == true)
            {
                if(allow(n, dictionary, allowed, param1) == true)
                    q--;
                else
                    cout << ">>ERROR: word is already allowed" << endl;
            }
            else
                cout << ">>ERROR: word must be in the dictionary" << endl;
        }
    }

    while(!clist.empty())
    {
        cout << clist.front() << endl;
        clist.pop();
    }
}

//REFERENCES:
/*
    https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
    https://www.youtube.com/watch?v=4OQeCuLYj-4

    http://www.cplusplus.com/reference/string/string/operator[]/
    http://www.cplusplus.com/reference/queue/queue/queue/
    http://www.cplusplus.com/reference/queue/queue/push/
    https://stackoverflow.com/questions/3437404/min-and-max-in-c
    https://stackoverflow.com/questions/25551779/intnm-where-n-and-m-are-known-at-runtime
*/
