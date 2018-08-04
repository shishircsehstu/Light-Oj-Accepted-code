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
 
#define pf printf
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define sc scanf
#define sc1(a) cin>>a
#define sc2(a,b) cin>>a>>b
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define endl '\n'
#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180);
#define siz 10006
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
#define mx 10002
vector<pii>g[mx];
vector<int>cost[mx];
int cnt[mx];
int d[mx][12];
struct node
{
    int  u,w,ex;
    node(int   a,int  b,int c)
    {
        u=a;
        w=b;
        ex=c;
    }
    bool operator < (const node& p) const
    {
        return p.w < w;
    }
};
int take,ans,value;
ll  dijkstra(int src,int n)
{
    ans=999999999;
    int tmp,x;
    memset(d,63,sizeof(d));
    priority_queue<node>q;
    q.push(node(src,0,0));
    string st,st2;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        int  u=top.u;
        int cn=top.ex;
        int cos=top.w;
        //  cout<<u<<" s "<<cn<<"--"<<cos<<endl;
        for(int  i=0; i<g[u].size(); i++)
        {
            int x;
            int  v=g[u][i].first;
            x=g[u][i].second;
            if(x+cn>take) continue;
            value=cos+cost[u][i];
            if(d[v][x+cn]>value)
            {
                q.push(node(v,value,cn+x));
                d[v][cn+x]=value;
            }
        }
    }
    for(int i=0; i<12; i++) ans=min(ans,d[n][i]);
    //  return ans;
}
int  main()
{
    //memset(d,63,sizeof(d));
    //cout<<d[0]<<endl;
    int  n,e,i,ret,k,t,u,v,w,x,tmp,cs=1;
    scanf("%d",&t);
    string st,st2;
    while(t--)
    {
        sc("%d %d %d %d",&n,&e,&k,&take);
        for( i=0; i<e; i++)
        {
            sc("%d%d%d",&u,&v,&w);
            u++;
            v++;
            g[u].push_back(make_pair(v,0));
            cost[u].push_back(w);
        }
        for(i=0; i<k; i++)
        {
            sc("%d%d%d",&u,&v,&w);
            u++;
            v++;
            g[u].push_back(make_pair(v,1));
            cost[u].push_back(w);
        }
        dijkstra(1,n);
        printf("Case %d: ",cs++);
        if(ans==999999999)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
        for(i=0; i<=n; i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }
 
}
/*
7 5 4 1
0 1 10
1 2 5
3 4 12
4 5 14
4 6 2
... ...
0 6 100
0 2 5
2 3 7
5 6 9
*/
 
