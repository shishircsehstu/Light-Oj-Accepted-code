#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
 
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define Sin(a) sin((pi*a)/180);
#define siz 10000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
using namespace std;
typedef long long ll;
bool isprime[siz];
int myPrimes[700000];
ll cnt=1;
void sive()
{
    ll i,sqt,j;
    for(i=4; i<=siz; i+=2)
        isprime[i]=true;
    isprime[1]=true;
    sqt=sqrt(siz);
    for(i=3; i<= sqt; i+=2)
    {
        if(isprime[i]==false)
        {
            for(j=2*i; j<=siz; j+=i)
                isprime[j]=true;
        }
    }
    myPrimes[0]=2;
    for(i=3; i<=siz; i+=2)
    {
        if(isprime[i]==false)
        {
            myPrimes[cnt++]=i;
        }
    }
}
int main()
{
    sive();
    ll n,i,j,hi,cn,r,lo,t,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        sc("%lld",&hi);
        cn=0;
        for(i=0; myPrimes[i]<=hi/2; i++)
        {
            lo=hi-myPrimes[i];
            if(isprime[lo]==false)
                cn++;
        }
        pf("Case %lld: %lld\n",cs++,cn);
    }
    return 0;
}
 
