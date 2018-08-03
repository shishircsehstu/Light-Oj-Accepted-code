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
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
 
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
#define DIFF_SIZE 1000001
bool prime[DIFF_SIZE];
ll myPrimes[DIFF_SIZE];
bool Final_prime[DIFF_SIZE];
ll cnt=1;
void sive()
{
    ll sq,i,j,m;
    for(i=4; i<=DIFF_SIZE; i+=2)
        prime[i]=true;
    prime[1]=true;
    sq=sqrt(DIFF_SIZE);
    for(i=3; i<=sq; i+=2)
    {
        if(prime[i]==false)
        {
            for(j=2*i; j<=DIFF_SIZE; j+=i)
                prime[j]=true;
        }
    }
    myPrimes[0]=2;
    for(i=3; i<=DIFF_SIZE; i+=2)
    {
        if(prime[i]==false)
            myPrimes[cnt++]=i;
    }
}
int main()
{
    sive();
    ll i,j,lo,hi,sum,a,b,x,t,t1,cn,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        cn=0;
        sc("%lld%lld",&lo,&hi);
        for(i=0; i<cnt; i++)
        {
            a=myPrimes[i];
            b=lo/a;
            x=a*b;
            for(j=x; j<=hi; j+=a)
            {
                if(j-lo<0)continue;
                Final_prime[j-lo]=true;
            }
        }
        for(i=0; i<=cnt; i++)
        {
            if(myPrimes[i]>=lo && myPrimes[i]<=hi)
                //  cout<<myPrimes[i]<<endl;
                cn++;
        }
        for(i=0; i<hi-lo+1; i++)
        {
            if(Final_prime[i]==false&&(i+lo)!=1)
                // cout<<i+lo<<endl;
                cn++;
        }
        pf("Case %lld: %lld\n",cs++,cn);
        mem(Final_prime);
    }
}
 
 
