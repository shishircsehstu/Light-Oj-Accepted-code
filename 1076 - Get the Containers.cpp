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
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector

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
int ar[siz],n;
int bi_nary(ll mid)
{
    ll sum,cnt;
    sum=0;
    cnt=1;
    int i;
    for(i=0; i<n; i++)
    {
        sum+=ar[i];
        if(sum>mid)
        {
            sum=ar[i];
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int   i,j,a,b,x,y,ck,t,m,r,ans,rem,cnt,cs=1;

    ll lo,hi,sum,mid;
    si(t);
    while(t--)
    {
        hi=0;
        lo=0;
        si(n),si(m);
        for(i=0; i<n; i++)
        {
            si(ar[i]);
            if(lo<ar[i])
                lo=ar[i];
            hi+=ar[i];
        }
        while(lo<hi)
        {
            mid=(lo+hi)/2;
            rem=bi_nary(mid);
            if(rem<=m)
            {
                hi=mid;
            }
            else
                lo=mid+1;
        }
        printf("Case %d: %lld\n",cs++,hi);
    }
}
