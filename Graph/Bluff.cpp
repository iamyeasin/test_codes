#include<bits/stdc++.h>

using namespace std;

long edges,nodes,visited=0,high=0;
long lev[1024],vis[1024];
vector < long > graph[300];
set < long > st;


void bfs(long s) // Just simple bfs code
{
    memset(vis,0,sizeof(vis));
    memset(lev,0,sizeof(lev));

    queue< long > q;
    q.push(s);
    lev[s] = 0;
    vis[s] = 1;
    visited = 1;

    while(!q.empty())
    {
        long cur = q.front(); q.pop();

        for(int i=0; i< graph[cur].size(); i++)
        {
            long v  = graph[cur][i];
            if(!vis[v])
            {
                vis[v] = 1;
                lev[v] = lev[cur] + 1;
                q.push(v);
                visited++;
            }
        }

    }

}

long unvisited(int limit)
{
    long how = 0;

    for(int i=0; i<=high; i++)
    {
        if(lev[i]>limit)
        {
            how++;
        }
    }

    return how;
}


void clean() /// Will clean the data like surfexcel
{
    memset(lev,0,sizeof(lev));
    memset(vis,0,sizeof(vis));
    st.clear();
    nodes = 0;
    edges = 0;
    high = 0;
    visited = 1;

}


void graphIn()
{
    for(int i=1; i<=edges; i++)
    {
        long x,y;
        cin >> x >> y;

        st.insert(x);
        st.insert(y);

        if(x>high) high = x;
        if(y>high) high = y;

        //For undirected graph
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    nodes = st.size();
}


int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    long kase=0;

    while(scanf("%ld",&edges))
    {
        if(!edges) break;
        graphIn();

        long s,t;
        while(scanf("%ld %ld",&s,&t),(s||t))
        {
            bfs(s);
            long n = (nodes - visited) > 0 ? (nodes-visited) : 0;
            cout << "Case " << ++kase << ": " << unvisited(t) + n << " nodes not reachable from node " <<  s << " with TTL = " << t << "." << endl;
        }

        clean();


    }



    return 0;
}
