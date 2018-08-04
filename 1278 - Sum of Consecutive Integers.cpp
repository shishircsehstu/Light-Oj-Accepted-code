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
#define sc1(a) cin>>a
#define sc2(a,b) cin>>a>>b
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define Sin(a) sin((pi*a)/180);
#define siz 1001001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
#define mx1 20000100
typedef long long ll;
 
using namespace std;
bool isprime[mx1];
int prim[1500000];
ll r;
void sive()
{
    ll i,sqt,j;
    for(i=4; i<=mx1; i+=2)
        isprime[i]=true;
    isprime[0]=isprime[1]=true;
    sqt=sqrt(mx1);
    for(i=3; i<= sqt; i+=2)
    {
        if(isprime[i]==false)
        {
            for(j=2*i; j<=mx1; j+=i)
                isprime[j]=true;
        }
    }
    for(i=1; i<=mx1; i++)
    {
        if(isprime[i]==false)
            prim[r++]=i;
    }
 
}
ll num(ll n)
{
    ll k,ans =1;
    k=0;
    while(n!=1)
    {
        if(r==k||prim[k]>n)break;
        ll cnt=0;
        while(n%prim[k]==0)
        {
            cnt++;
            n/=prim[k];
        }
        if(k!=0)
        {
            ans*=cnt+1;
        }
        k++;
    }
    if(n!=1)
        ans*=2;
    ans--;
    return ans;
}
int main()
{
    sive();
    ll i,j,n,x,t,cs=1;
    sc1(t);
    while(t--)
    {
        sc1(n);
        pf("Case %lld: %lld\n",cs++,num(n));
    }
 
}
 
