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
#define siz 10000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
#define mx 1001
bool isprime[mx+5];
int prim[1001],vis[1001],d[1001];
vector<int>vec[1001];
void sive()
{
    int i,sqt,j;
    for(i=4; i<=mx; i+=2)
        isprime[i]=true;
    isprime[0]=isprime[1]=true;
    sqt=sqrt(mx);
    for(i=3; i<= sqt; i+=2)
    {
        if(isprime[i]==false)
        {
            for(j=2*i; j<=mx; j+=i)
                isprime[j]=true;
        }
    }
    int r=0;
    for(i=2; i<=1000; i++)
    {
        if(isprime[i]==false)
            prim[r++]=i;
    }
    for(i=2; i<=1000; i++)
    {
        for(j=0; j<r; j++)
        {
            if(i%prim[j]==0&&i!=prim[j])
                vec[i].push_back(prim[j]);
            if(prim[j]>=i) break;
        }
    }
}
int bfs(int s,int t)
{
    mem(vis),mem(d);
    vis[s]=1;
    d[s]=0;
    queue<int>qe;
    qe.push(s);
    int i;
    while(!qe.empty())
    {
        int u=qe.front();
        // cout<<"u="<<u<<endl;
        qe.pop();
        if(u==t) return d[u];
        for(i=0; i<vec[u].size(); i++)
        {
            int v=u+vec[u][i];
            if(vis[v]==0&&v<=t)
            {
                vis[v]=1;
                d[v]=d[u]+1;
                qe.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    sive();
    int a1,a2,b1,b2,c1,c2,h1,h2,i,j,n,k,m,cnt,ans,sum,x,x1,x2,r,t,cs=1;
    si(t);
    while(t--)
    {
 
        si(a1),si(a2);
        ans=bfs(a1,a2);
        if(ans==-1) printf("Case %d: -1\n",cs++);
        else
            printf("Case %d: %d\n",cs++,ans);
    }
 
}
 
