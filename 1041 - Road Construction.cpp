/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
#include<bits/stdc++.h>
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
vector<int>G[101];
vector<int>vec,vec2;
map<string,int>mp;
int pr[101];
int vis[101];
struct edge
{
    int u,v,w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};
vector<edge>e;
int find(int  r)
{
    return (pr[r]==r) ? r:  find(pr[r]);
}
int dfs(int src)
{
    if(vis[src]==1)
        return 0;
    vis[src]=1;
    for(int i=0; i<G[src].size(); i++)
    {
        dfs(G[src][i]);
    }
}
int  mst(int  n)
{
    sort(e.begin(),e.end());
    for(int  i=1; i<=n; i++)
        pr[i]=i;
    int  count=0,s=0;
    for(int  i=0; i<e.size(); i++)
    {
        //cout<<"u="<<e[i].u<<endl;;
        // cout<<"v="<<e[i].v<<endl;;
        int x,y;
        x=e[i].u;
        y=e[i].v;
        int  u=find(e[i].u);
        int  v=find(e[i].v);
        if(u!=v)
        {
            //  cout<<"x="<<x<<" y="<<y<<endl;
            pr[u]=v;
            count++;
            s+=e[i].w;
            if(count==n-1) break;
        }
    }
    return s;
}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,b,ck,t,x,y,ans,rem,k,cnt,lo,hi,r,frind,sum,cst,cs=1;
 
    string s1,s2;
    si(t);
    while(t--)
    {
        si(n);
        cnt=0;
        for(i=0; i<n; i++)
        {
            cin>>s1>>s2>>cst;
            if(mp[s1]==0)
            {
                mp[s1]=++cnt;
            }
            if(mp[s2]==0)
                mp[s2]=++cnt;
            x=mp[s1];
            y=mp[s2];
 
            //  cout<<x<<"  "<<y<<endl;
            G[x].pb(y);
            G[y].pb(x);
            int u,v,w;
 
            edge get;
            get.u=x;
            get.v=y;
            get.w=cst;
            e.push_back(get);
        }
        //cout<<mp["Chandpur"];
        dfs(1);
        ck=0;
        printf("Case %d: ",cs++);
        for(i=1; i<=cnt; i++)
        {
            if(vis[i]==0)
            {
                printf("Impossible\n");
                ck=1;
                break;
            }
        }
        if(ck==0)
        {
            x=mst(cnt);
            printf("%d\n",x);
        }
        mp.clear();
        e.clear();
        mem(vis);
        for(i=1; i<=cnt; i++)
            G[i].clear();
    }
}
/*
6 7
1 2
2 3
1 3
2 4
4 5
4 6
5 6
*/
