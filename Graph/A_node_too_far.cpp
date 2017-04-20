#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

vector<int> graph[5000];
long vis[5000],lev[5000];
long nodes,edges,high=0;

void bfs(int s)
{
    memset(lev,0,sizeof(lev));
    memset(vis,0,sizeof(vis));

    queue<int>q;
    q.push(s);
    vis[s] = 1;
    lev[s] = 0;

    while(!q.empty()){
        int cur = q.front();q.pop();

        for(int i=0; i<graph[cur].size(); i++)
        {
            long v = graph[cur][i];
            if(!vis[v])
            {
                lev[v] = lev[cur]+1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }

//    lev.clear();
}

long printLev(int m)
{
    long how = 0;
    for(int i=1; i<=high+1; i++){
            if(lev[i]>m){
                how++;
            }
    }

    return how;
}


void takeIn(int e){

    for(int i=1; i<=e; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>high) high = x;
        if(y>high) high = y;


        graph[x].push_back(y);
        graph[y].push_back(x);
    }

}


void vec()
{
    for(int i=0; i<2*high; i++)
    {
        int s = graph[i].size();
        for(int j=0; j<s; j++)
        {
            graph[i][j]=0;
        }
    }
    memset(vis,0,sizeof(vis));
    memset(lev,0,sizeof(lev));
}


int main()
{
//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    long nc,kase=0,T=0;
    while(sf("%ld",&nc))
    {
        if(!nc)break;
        takeIn(nc);

        int t1,t2;
        while(sf("%d %d",&t1,&t2),t1||t2)
        {
            bfs(t1);
            long n = printLev(t2);
            printf("Case %ld: %ld nodes not reachable from node %d with TTL = %d.\n",++T,n,t1,t2);

        }

        vec();
        t1=0,t2=0;

    }


    return 0;
}
