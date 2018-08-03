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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
vector<int>vec[10001];
int ar[siz],ar2[siz];
int vis[siz];
int Bfs(int src,int *p)
{
    queue<int>qe;
    p[src]=0;
    vis[src]=1;
    qe.push(src);
    while(!qe.empty())
    {
        int u=qe.front();
        qe.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(vis[v]==0)
            {
                p[v]=p[u]+1;
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
    int  i,j,n,m,a,c,b,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        mem(ar),mem(ar2),mem(vis);
        si(n),si(m);
        for(i=0; i<m; i++) si(x),si(y),vec[x].pb(y),vec[y].pb(x);
        si(x),si(y);
        Bfs(x,ar);
        mem(vis);
        Bfs(y,ar2);
        ans=0;
        for(i=0; i<n; i++) ans=max(ans,ar[i]+ar2[i]);
        printf("Case %d: %d\n",cs++,ans);
        for(i=0; i<=n; i++) vec[i].clear();
    }
}
/*
6 6
0 1
1 2
1 3
2 3
3 4
4 5
 
 
0 5
 
*/
