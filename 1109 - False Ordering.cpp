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
#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sf(t) scanf("%f",&t)
#define sd(t) scanf("%lf",&t)
#define sii(a,b) scanf("%d%d",&a,&b)
#define sll(a,b) scanf("%I64d%I64d",&a,&b)
 
//Output
#define P(a) printf("%dn",a)
#define PL(a) printf("%lldn",a)
#define PF(a) printf("%fn",a)
#define PDB(a) printf("%lfn",a)
#define PN(a) printf("%d ",a)
#define PLN(a) printf("%I64d ",a)
#define PDBN(a) printf("%lf ",a)
#define pf printf
 
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
 
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
int divisor[mx];
int ar2[1001];
int r;
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
ll divisor_count(ll n)
{
    int n1,fact,i,sum=1;
    n1=n;
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
    divisor[n1]=sum; //sum is total number of divisor n
}
void read()
{
    int i,j;
    for(i=1; i<=1000; i++)
    {
        ar2[i]=i;
        divisor_count(i);
    }
}
void sor_t()
{
    int i,j,n,m;
    for(i=1; i<1000; i++)
    {
        for(j=1+i; j<=1000; j++)
        {
            if(divisor[i]>divisor[j])
            {
                n=divisor[i];
                divisor[i]=divisor[j];
                divisor[j]=n;
 
                m=ar2[i];
                ar2[i]=ar2[j];
                ar2[j]=m;
            }
            else if(divisor[i]==divisor[j])
            {
                if(ar2[i]<ar2[j])
                {
                    m=ar2[i];
                    ar2[i]=ar2[j];
                    ar2[j]=m;
                }
            }
        }
    }
}
int main()
{
    sive();
    read();
    sor_t();
    int n,t,cs=1;
    sc("%d",&t);
    while(t--)
    {
        sc("%d",&n);
        pf("Case %d: %d\n",cs++,ar2[n]);
    }
}
 
