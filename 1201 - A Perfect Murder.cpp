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
#define siz 1001
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
bool ar[siz];
vector<int>vec[siz];
int vis[siz],ind[siz],ans;
map<int,int>mp;
void dfs(int x,int p=0)
{
    //if(vec[x].size()==0) ans=1;
    int v;
    if(vis[x]==1) return ;
    vis[x]=1;
    for(int i=0; i<vec[x].size(); i++)
    {
        v=vec[x][i];
        if(vis[v]==0)
            dfs(v,x);
    }
    if(ind[x]==0)
    {
        ans++;
        ind[p]=ind[x]=1;
    }
    //cout<<p<<" "<<x<<endl;
}
int main()
{
 
    int  i,j,n,m,a,c,b,d,ck,t,r,x,y,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        si(n),si(m);
        sum=0;
        for(i=0; i<m; i++)
        {
            si(x),si(y);
            vec[x].pb(y);
            vec[y].pb(x);
        }
        for(i=1; i<=n; i++)
        {
            if(vis[i]==0)
                dfs(i);
            sum+=ans;
            ans=0;
        }
        printf("Case %d: %d\n",cs++,sum);
        for(i=1; i<=n; i++)
            vec[i].clear();
        mem(vis);
        mem(ind);
    }
}
/*
4 3
1 2
2 3
2 4
 
*/
 
