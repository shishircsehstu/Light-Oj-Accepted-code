/******************************************************************
 *                   BISMIintAHIR RAHMANIR RAHIM                   *
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
#define siz 1000001
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
int  vis1[siz],vis2[siz];
int vis[siz],cnt1,cnt2;
struct edge
{
    int  u,v,w;
} graph[300];
bool cmp(edge x,edge y)
{
    return x.w<y.w;
}
int find(int x )
{
    if ( pr[x] == x ) return x ;
    else return pr[x] = find(pr[x]);
}
int  krus(int  n,int  m)
{
    sort(graph,graph+m,cmp);
    /*
    cout<<"----------\n";
    for(int i=0; i<m; i++)
        cout<<graph[i].u<<"  "<<graph[i].v<<" "<<graph[i].w<<endl<<endl;
        */
    int  i,x,y,u,v,indx,d=-1;
    for(i=1; i<=n; i++)
        pr[i]=i;
    int  count=0,s=0;
 
    for(i=0; i<m; i++)
    {
        x=graph[i].u;
        y=graph[i].v;
        u=find(graph[i].u);
        v=find(graph[i].v);
        if(v==u)
        {
            d=i;
            continue;
        }
        pr[u]=v;
        count++;
        s+=graph[i].w;
    }
    if(d!=-1)
    {
        graph[d]=graph[--cnt1];
    }
    if(count==n-1) return s;
    else
        return -1;
}
int  main()
{
    int  i,j,n,k,r,m,cnt,u,v,cost,t,ck,cs=1;
    int ans,res,res2;
    si(t);
    while(t--)
    {
        cnt1=0;
        mem(vis);
        mem(pr);
        si(n),si(m);
        printf("Case %d:\n",cs++);
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            graph[cnt1].u=u;
            graph[cnt1].v=v;
            graph[cnt1].w=cost;
            cnt1++;
            printf("%d\n",krus(n,cnt1));
        }
    }
}
/*
 
7 10
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
 
*/
 
 
