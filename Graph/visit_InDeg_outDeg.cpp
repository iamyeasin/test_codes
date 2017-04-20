/*E= 8  N = 5
1 2 // nodes
2 5
3 2
3 1
4 2
4 5
4 3
5 1*/


#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

vector < int >graph[500];
vector < int >in[500],out[500];
long n,e; // Nodes and edges

void gi()
{
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        in[y].push_back(x); // Taking in the IN degrees
        out[x].push_back(y); // Taking in the out degrees
        //The graph is undirected
        graph[x].push_back(y);
//        graph[y].push_back(x);
    }
}



void print()
{
    for(int i=0; i<=n; i++)
    {
        int sz = graph[i].size();
        cout << i << ": ";
        for(int j=0; j<sz; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void inDeg()
{
    cout << "Indegree: " << endl;
    for(int i=0; i<=n; i++)
    {
        int sz = in[i].size();
        cout << i << ": ";
        for(int j=0; j<sz; j++)
        {
            cout << in[i][j] << " ";
        }
        cout << endl;
    }
}

void outDeg()
{
    cout << "Outdegree: " << endl;
    for(int i=0; i<=n; i++)
    {
        int sz = out[i].size();
        cout << i << ": ";
        for(int j=0; j<sz; j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
}



int main()
{
    cin>>e>>n;

    gi();
    print();
    inDeg();
    cout << endl;
    outDeg();

    return 0;
}
