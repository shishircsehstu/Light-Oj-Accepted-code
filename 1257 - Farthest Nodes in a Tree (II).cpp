/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
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
 
#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf
 
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pb push_back
#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
map<ll,bool>visi;
int ar[siz];
vector<int>vec[50001],cost[50001];
int d[siz],vis[siz],d2[siz],id;
int bfs(int src)
{
    mem(vis);
    vis[src]=1;
    d[src]=0;
    queue<int>qe;
    qe.push(src);
    int ans=-1;
    while(!qe.empty())
    {
        int u=qe.front();
        qe.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(vis[v]==0)
            {
                //cout<<cost[u][i]<<endl;
                d[v]=d[u]+cost[u][i];
                if(ans<d[v])
                {
                    ans=d[v];
                    id=v;
                }
                vis[v]=1;
                qe.push(v);
            }
        }
    }
}
int bfs2(int src)
{
    mem(vis);
    vis[src]=1;
    d2[src]=0;
    queue<int>qe;
    qe.push(src);
    int ans=-1;
    while(!qe.empty())
    {
        int u=qe.front();
        qe.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(vis[v]==0)
            {
                d2[v]=d2[u]+cost[u][i];
                vis[v]=1;
                qe.push(v);
            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int   i,j,n,m,a,c,b,ck,t,r,x,y,cst,ans,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        id=-1;
        si(n);
        for(i=1; i<n; i++)
        {
            si(x),si(y),si(cst);
            vec[x].pb(y);
            vec[y].pb(x);
            cost[x].pb(cst);
            cost[y].pb(cst);
        }
        bfs(0);
        bfs(id);
        bfs2(id);
        printf("Case %d:\n",cs++);
        for(i=0; i<n; i++)
        {
            printf("%d\n",max(d[i],d2[i]));
        }
        for(i=0; i<n; i++)
            vec[i].clear(),cost[i].clear();
        mem(d),mem(d2);
    }
}
 
