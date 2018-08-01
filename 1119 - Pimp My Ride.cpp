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
int ar[20][20],n;
ll dp[1<<15+1];
ll bit_mask(int mask)
{
 
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]) return dp[mask];
    ll i,j,x,sum;
    ll mn=9999999999;
    for(i=0; i<n; i++)
    {
        if(check(mask,i)==0)
        {
            sum=ar[i][i];
            //cout<<"sum="<<sum<<endl;
            for(j=0; j<n; j++)
            {
                if(check(mask,j)&&i!=j)
                {
                    // cout<<"ar="<<ar[i][j]<<endl;
                    sum+=ar[i][j];
                }
            }
            sum+=bit_mask(Set(mask,i));
            // cout<<sum<<endl;
            mn=min(mn,sum);
        }
    }
    //sum=0;
    return dp[mask]=mn;
 
}
int main()
{
    int i,j,node,k,x,child,m,t,parnt,cs=1;
    si(t);
    while(t--)
    {
        mem(dp);
        si(n);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                si(ar[i][j]);
        printf("Case %d: %lld\n",cs++,bit_mask(0));
    }
 
 
}
