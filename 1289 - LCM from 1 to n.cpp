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
#define sd(t) scanf("%lf",&t)
 
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
map<ll,bool>visi;
#define size 100000100
map<ll,ll>mp;
unsigned prim[5761558],cnt;
unsigned  dp[5761558];
long long a[size / 64 + 100];
void sive()
{
    for (ll i = 3; i <= sqrt(size); i += 2)
    {
        if(!(a[i/64]&(1LL<<(i%64))))
        {
            for(ll j = i * i; j <= size; j += 2 * i)
            {
                a[j/64] |= (1LL<<(j%64));
            }
        }
    }
    prim[cnt++] = 2;
    for (ll i = 3; i <= size; i += 2)
    {
        if(!(a[i / 64] & (1LL << (i % 64))))
        {
            prim[cnt++] = i;
        }
    }
    // for(int i=0;i<20;i++) cout<<prim[i]<<" ";
    ll sqt=pow(2,32);
    dp[0]=2;
    for(int i=1; i<cnt; i++)
        dp[i]=(dp[i-1]*prim[i]);
 
}
ll cal(ll n)
{
    ll sqt=pow(2,32);
    ll i,tem,ans=1;
    for(i=0; prim[i]*prim[i]<=n; i++)
    {
        tem=n;
        tem=tem/prim[i];
        while(tem>=prim[i])
        {
            tem=tem/prim[i];
            ans=(ans*prim[i]);
        }
    }
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    sive();
    ll   i,j,n,m,ck,t,ans,rem,cs=1;
    unsigned sum;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        sum=cal(n);
        //cout<<"Yes\n";
        ans=upper_bound(prim,prim+cnt,n)-prim;
        ans--;
        sum*=dp[ans];
        printf("Case %lld: %u\n",cs++,sum);
        // cout<<sum%sqt<<endl;
    }
}
 
