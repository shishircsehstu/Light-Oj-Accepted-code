//BISMILLAHIR RAHMANIR RAHIM
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
 
//input
#define si(t) scanf("%d",&t)
#define sll(t) scanf("%I64d",&t)
#define sll2(a,b) scanf("%I64d %I64d",&a,&b)
#define sf(t) scanf("%f",&t)
#define sd(t) scanf("%lf",&t)
#define sc(c) scanf("%c",&c)
#define sii(a,b) scanf("%d%d",&a,&b)
 
//Output
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lldn",a)
#define PF(a) printf("%fn",a)
#define PDB(a) printf("%lfn",a)
#define PLL(a) printf("%I64d\n",a)
#define PP(a,b) printf("%d %dn",a,b)
#define PPN(a,b) printf("%d %d ",a,b)
#define PPL(a,b) printf("%lld %lldn",a,b)
#define PPLN(a,b) printf("%lld %lld ",a,b)
 
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
 
#define pf printf
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
#define mx 1000010
#define mod 1000000007
bool isprime[mx+5];
int ar[mx],cnt;
void sive()
{
    ll i,sqt,j;
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
    for(i=1; i<=mx; i++)
    {
        if(isprime[i]==false)
            ar[cnt++]=i;
    }
}
int main()
{
    sive();
    ll i,j,n,m,k,fact,f,sum;
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        sum=1;
        for(i=0; i<cnt&&(ar[i]*ar[i])<=n; i++)
        {
            fact=0;
            while(n%ar[i]==0)
            {
                fact++;
                n/=ar[i];
            }
            sum*=(fact+1);
        }
        if(n!=1)
        {
            sum*=2;
        }
        pf("Case %d: ",cs++);
        pf("%lld\n",sum-1);
    }
}
 
