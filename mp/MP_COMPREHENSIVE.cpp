#include <iostream>
#include <string>
#include <queue>
#define MIN(a, b) (((a) < (b)) ? (a):(b))
#define SQR(a) ((a) * (a))
#define INF 99999

using namespace std;

vector<vector<int>> graph;

bool check(int n, string allowed[], string word)    //checks if the word is part of the dictionary
{
    for(int i = 0; i < n; i++)
    {
        if(allowed[i] == word)
        {
            return true;
        }
    }
    return false;
}
void forbid(int n, string allowed[], string word)   //forbids the word
{
    for(int i = 0; i < n; i++)
    {
        if(allowed[i] == word)
        {
            allowed[i] = "";
        }
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
    cout << "index(" << word << ")" << endl;
    for(int i = 0; i < n; i++)
    {
        if(dictionary[i] == word)
        {
            return i;
        }
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
    cout << "ginit()" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = INF;
        }
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
                    {
                        graph[i][j] = distance(len, allowed, i, j);
                    }
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
        {
            fwgraph[i][j] = graph[i][j];
        }
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

    for(int i = 0; i < n; i++)      //printing function
    {
        for(int j = 0; j < n; j++)
        {
            if(fwgraph[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", fwgraph[i][j]);
        }
        printf("\n");
    }

    return MIN(fwgraph[n1][n2], fwgraph[n2][n1]);
}


int main()
{
    int n, q, len;
    cout << "Enter the number of words:\t";
    cin >> n;

    graph.resize(n, vector<int> (n, INF));

    cout << "Enter the number of queries:\t";
    cin >> q;
    cout << "Enter the words:\t" << endl;
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
        {
            allowed[i] = dictionary[i];
        }
        else
        {
            cout << ">>ERROR: words must be of the same length" << endl;
            i--;
        }
    }

    cout << endl << "DICTIONARY:" << endl;
    for(int i = 0; i < n; i++)
        cout << dictionary[i] << endl;

    cout << endl << "QUERIES:" << endl;

    int count = 1;
    queue<int> clist;       //queue used for FIFO purposes
    string query, param1, param2;
    while(q > 0)
    {
        cout << "Enter Query #" << count << "\t";
        cin >> query;

        if(query == "COST")
        {
            cin >> param1;
            cin >> param2;
            if((check(n, allowed, param1) == true) && (check(n, allowed, param2) == true))
            {
                cout << "cost(" << param1 << ", " << param2 << ")" << endl;
                ginit(n, len, allowed);
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(graph[i][j] == INF)
                            printf("%7s", "INF");
                        else
                            printf ("%7d", graph[i][j]);
                    }
                    printf("\n");
                }
                int n1 = index(n, dictionary, param1);
                int n2 = index(n, dictionary, param2);
                cout << "n1: " << n1 << "\tn2: " << n2 << endl;
                clist.push(cost(n, n1, n2));
                count++;
                q--;
            }
            else
            {
                cout << ">>ERROR: words must currently be in the dictionary" << endl;
            }

        }
        else if(query == "FORBID")
        {
            cin >> param1;
            if(check(n, allowed, param1) == true)
            {
                cout << "forbid(" << param1 << ")" << endl;
                forbid(n, allowed, param1);
                count++;
                q--;
            }
            else
            {
                cout << ">>ERROR: word must currently be in the dictionary" << endl;
            }
        }
        else if(query == "ALLOW")
        {
            cin >> param1;
            if(check(n, dictionary, param1) == true)
            {
                cout << "allow(" << param1 << ")" << endl;
                if(allow(n, dictionary, allowed, param1) == true)
                {
                    count++;
                    q--;
                }
                else
                {
                    cout << ">>ERROR: word is already allowed" << endl;
                }
            }
            else
            {
                cout << ">>ERROR: word must be in the dictionary" << endl;
            }
        }
    }

    cout << "COSTS:" << endl;
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
