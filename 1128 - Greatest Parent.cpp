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
#define mk make_pair
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

//'A'=65, 'a'=97 '0'=48


map<ll,bool>visi;
int ar[siz];
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
#define mx 100002
int L[mx];
int sparse_t[mx][22];
int T[mx];
vector<int>g[mx];
int weight[mx];
void dfs(int from,int u,int dep)
{
    T[u]=from;   ///T store parent of child
    L[u]=dep;    /// L store level of node
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q)
{
    int child,pp,r,n=log2(N);
    r=n;
    pp=p;
    while(r!=-1)
    {
        child=sparse_t[p][r];
        if(weight[child]<q)
            r--;
        if(weight[child]>q)
        {
            p=child;
            r=n;
        }
        if(weight[child]==q)
            return child;
    }

    return p;
}

void lca_init(int N)
{
    memset (sparse_t,-1,sizeof(sparse_t));
    int i, j;
    for (i = 0; i < N; i++)
        sparse_t[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
    {
        for (i = 0; i < N; i++)
        {
            if (sparse_t[i][j - 1] != -1)
            {
                sparse_t[i][j] = sparse_t[sparse_t[i][j - 1]][j - 1];
            }
        }
        // cout<<endl;
    }

    // print sparse table
    /*
    for(i=0; i<N; i++)
    {
        for(j=0; pow(2,j)<N; j++)
            cout<<sparse_t[i][j]<<" ";
        cout<<endl;
    }
    */
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,n,m,x,y,t,cs=1;
    si(t);
    while(t--)
    {
        si(n),si(m);
        weight[0]=1;
        for(i=1; i<n; i++)
        {
            si(x),si(y);
            g[x].pb(i);
            weight[i]=y;
        }
        dfs(0, 0, 0);
        lca_init(n);
        printf("Case %d:\n",cs++);
        for(i=0; i<m; i++)
        {
            si(x),si(y);
            printf("%d\n", lca_query(n,x,y) );
        }
        for(i=0; i<=n; i++)
            g[i].clear();
    }
    return 0;
}

