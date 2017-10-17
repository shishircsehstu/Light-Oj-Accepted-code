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


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
/*
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
*/
#define mx 1000001
#define MOD 1000000007

bool isprime[mx+5];
vector<int>prim;
long long  ar[1000],r;
#define ll long long
void bi_nary(long long  n)
{
    while(n>0)
    {
        ar[r++]=n%2;
        n/=2;
    }
}
ll big_mod(ll base,ll pow,ll mod)
{
    ll ans,p;
    bi_nary(pow);
    ans=1;
    p=base%mod;
    for(int  i=0; i<r; i++)
    {
        if(ar[i]==1)
            ans=(ans*p)%mod;
        p=(p*p)%mod;
    }
    r=0;
    return ans;
}
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
    prim.pb(2);
    for(i=3; i<mx; i+=2)
    {
        if(isprime[i]==false)
            prim.pb(i);
    }

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll  i,j,a,b,x,y,ck,t,r,n,m,ans,rem,cnt,lo,hi,sum,cs=1;
    sive();
    sll(t);
    while(t--)
    {
        sll(n),sll(m);
        lo=sqrt(n);
        ans=1;
        sum=1;
        for(i=0; prim[i]<=lo; i++)
        {
            if(n%prim[i]==0)
            {
                // cout<<lo<<endl;
                cnt=0;
                while(n%prim[i]==0)
                {
                    n/=prim[i];
                    cnt++;
                }
                sum*=prim[i]-1;
                sum%=MOD;
                hi=big_mod(prim[i],(cnt*m)+1,MOD);
                hi-=1;
                if(hi<0) hi+=MOD;
                ans*=hi;
                ans%=MOD;
                lo=sqrt(n);
            }
        }
        if(n>1)
        {
            sum*=n-1;
            sum%=MOD;
            hi=big_mod(n,m+1,MOD);
            hi-=1;
            if(hi<0) hi+=MOD;
            ans*=hi;
            ans%=MOD;
        }
        sum=big_mod(sum,MOD-2,MOD);// mod inverse
        ans*=sum;
        ans%=MOD;
        printf("Case %lld: %lld\n",cs++,ans);
    }
}
