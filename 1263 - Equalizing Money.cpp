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
#include<limits>
#include<limits.h>

#define all(v) v.begin(),v.end()

#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)

#define sll(t) scanf("%lld",&t)

#define sii(a,b) scanf("%d%d",&a,&b)

#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second

#define pb push_back
#define pii pair<int,int>
#define mk make_pair
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

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())

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
int money[siz],vis[siz];
vector<int>graph[siz];
double bfs(int src)
{
    int i,j,cnt,ans;
    double sum;
    queue<int>qe;
    qe.push(src);
    vis[src]=1;
    cnt=1;
    sum=money[src];
    while(!qe.empty())
    {
        int x=qe.front();
        qe.pop();
        for(i=0; i<graph[x].size(); i++)
        {
            int v=graph[x][i];
            if(vis[v]==0)
            {
                qe.push(v);
                vis[v]=1;
                cnt++;
                sum+=money[v];
            }
        }
    }
    return sum/(double)cnt;

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,m,a,n,c,b,d,ck,t,r,ans,rem,cnt,lo,hi,cs=1;
    double sum;
    si(t);
    while(t--)
    {
        mem(vis);
        si(n),si(m);
        for(i=1; i<=n; i++)
            si(money[i]);

        for(i=0; i<m; i++)
        {
            si(a),si(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        ck=0;
        sum=bfs(1);
        ans=sum;
        rem=sum;

        printf("Case %d: ",cs++);
        if(sum-ans!=0)
        {
            printf("No\n");
            ck=1;
        }
        else
        {
            for(i=2; i<=n; i++)
            {
                if(vis[i]==0)
                {
                    sum=bfs(i);
                    ans=sum;
                    if(sum-ans!=0||sum!=rem)
                    {
                        printf("No\n");
                        ck=1;
                        break;
                    }
                }
            }
            if(ck==0)
            {
                printf("Yes\n");
            }
        }
        for(i=1; i<=n; i++)
        {
            graph[i].clear();
        }
    }
}
/*
5 3
1 1 1 1 1
1 2

3 4
4 5
*/
