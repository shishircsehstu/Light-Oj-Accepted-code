/******************************************************************
 *                   BISMIintAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
 //cpu 0.168sec
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) print f("%d\n",a)
#define PLN(a) print f("%I64d ",a)
#define pf print f

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pb push_back
#define pii pair<int ,int >
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 10001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)

using namespace std;
//int  dx[]= {-1,-1,0,0,1,1};
//int  dy[]= {-1,0,-1,1,0,1};
//int  dx[]= {0,0,1,-1};/*4 side move*/
//int  dy[]= {-1,1,0,0};/*4 side move*/
//int  dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int  dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int  dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int  dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
int  pr[siz];
int vis[siz],cnt1,cnt2,vis2[siz];
vector<int>G[10005],gcost[10005];
map<pii,int>mp;
struct edge
{
    int  u,v,w;
} graph[400002];
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
int  find(int  r)
{
    return (pr[r]==r) ? r:  find(pr[r]);
}
int node,r;
queue<int>qe;
void bfs(int src)
{
    int i,j;
    node=1;
    r=0;
    qe.push(src);
    mem(pr);
    pr[src]=src;
    while(!qe.empty())
    {
        int u=qe.front();
        qe.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            //cout<<"Yes\n";
            int v=G[u][i];
            graph[r].u=u;
            graph[r].v=v;
            graph[r].w=gcost[u][i];
            r++;
            if(pr[v]==0)
            {
                node++;
                pr[v]=v;
                qe.push(v);
            }
        }
    }

}

// cout<<node<<" "<<r<<endl;
int  krus(int src)
{
    bfs(src);
    int n,m;
    n=node,m=r;
    long long s=0;
    // cout<<n<<"  "<<m<<endl;
    if(m!=0)
    {
        //cout<<"m=="<<m<<endl;
        sort(graph,graph+m,cmp);
        int  i,x,y,u,v;
        int  count=0;
        for( i=0; i<m; i++)
        {
            x=graph[i].u;
            y=graph[i].v;
            u=find(graph[i].u);
            v=find(graph[i].v);
            if(u!=v)
            {
                vis[graph[i].u]=1,vis[graph[i].v]=1;
                pr[u]=v;
                count++;
                s+=graph[i].w;
                if(count==n-1) break;
            }
        }
    }
    return s;
}
int  main()
{
    int  i,j,n,k,r,m,cnt,u,v,cost,t,ck,cost_air,cs=1;
    int ans,res,res2;
    cnt1=cnt2=0;
    si(t);
    while(t--)
    {
        mem(pr);
        mem(vis);
        si(n),si(m),si(cost_air);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&cost);
            if(cost<cost_air)
            {
                G[u].pb(v);
                G[v].pb(u);
                gcost[u].pb(cost);
                gcost[v].pb(cost);
            }
        }
        long long  answ=0;
        k=0;
        //  answ =krus(1);
        //  cout<<answ<<endl;
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                answ+=krus(i)+cost_air;
                k++;
            }
        }
        printf("Case %d: %lld %d\n",cs++,answ,k);
        for(i=1; i<=n; i++)
        {
            G[i].clear();
            gcost[i].clear();
        }
    }
}
/*

7 10 100
1 2 7
1 4 5
2 3 8
2 5 7
2 4 9
3 5 5
4 5 15
4 6 6
5 7 9
6 7 11

4 6 12
1 2 1
1 4 1
1 3 2
3 4 3
3 2 2
4 2 1

7 6 12
1 2 11
2 3 2
1 3 1
3 5 2

6 7 4
4 6 4

*/

