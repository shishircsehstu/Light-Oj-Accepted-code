#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#define pb push_back
#define mx 100001
#define sc scanf
#define pf printf
using namespace std;
vector<int>G[mx];
vector<int>cost[mx];
int visited[mx];
int level[mx];
int parent[mx];
void bfs(int src,int &ans)
{
    memset(level,0,sizeof level);
    memset(visited,0,sizeof visited);
    int maxm,sum=0;
    queue<int>Q;
    Q.push(src);
    visited[src]=1;
    level[src]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(!visited[v])
            {
                level[v]=level[u]+cost[u][i];
                if(level[v]>sum)
                {
                    sum=level[v];
                    ans=v;
                }
                visited[v]=1;
                Q.push(v);
            }
        }
        Q.pop();
    }
}
int main()
{
    int i,j,n,x,y,src,des,cst,t,cs=1;
    sc("%d",&t);
    while(t--)
    {
        sc("%d",&n);
        for(i=0; i<n-1; i++)
        {
            sc("%d%d%d",&x,&y,&cst);
            G[x].pb(y);
            G[y].pb(x);
            cost[x].pb(cst);
            cost[y].pb(cst);
        }
        int st,en;
        bfs(0,st);
        bfs(st,en);
        pf("Case %d: %d\n",cs++,level[en]);
        for(i=0; i<mx; i++)
        {
            G[i].clear();
            cost[i].clear();
        }
    }
}
 
