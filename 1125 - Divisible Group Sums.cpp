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
 
//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
 
 
map<ll,bool>visi;
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
ll ar[1001],x,y,n;
ll dp[308][20][50];
ll cal(int i,int f,int s)
{
    if(i>=n&&f!=y) return 0;
    if(dp[i][f][s]) return dp[i][f][s];
    if(f==y)
    {
        if(s==0)
        {
            return 1;
        }
        return 0;
    }
    ll ret,ret2;
    ret=ret2=0;
    ret=cal(i+1,f+1,(s+ar[i])%x);
    ret2=cal(i+1,f,s);
    return dp[i][f][s]=ret+ret2;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,m,a,c,b,d,ck,t,r,ans,rem,cnt,lo,hi,sum,cs=1;
    // printf("%\n",pow(2,32));
    si(t);
    while(t--)
    {
        si(n);
        si(m);
        for(i=0; i<n; i++)
            scanf("%lld",&ar[i]);
 
        printf("Case %d:\n",cs++);
        for(i=1; i<=m; i++)
        {
            mem(dp);
            scanf("%lld %lld",&x,&y);
            if(x==0||y==0)
                printf("0\n");
            else
                printf("%lld\n",cal(0,0,0));
 
        }
    }
 
}
/*
5
1 2 3 5 7
4 2
*/
 
