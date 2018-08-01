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
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
using namespace std;
typedef unsigned long long li;
int zerocount(li n)
{
    li sum=0;
    while(n>=5)
    {
        sum+=n/5;
        n/=5;
    }
    return sum;
}
int main()
{
    li i,j,n,k,num,num1,ck,t,lo,hi,mid,cs=1;
    sc("%llu",&t);
    while(t--)
    {
        sc("%llu",&n);
        ck=0;
        lo=0;
        hi=100000000000;
        while(lo<hi)
        {
            mid=(lo+hi)/2;
            if(zerocount(mid)==n)
            {
                while(mid)
                {
                    if(zerocount(mid)==n)
                    {
                        mid--;
                        ck=1;
                    }
                    else
                    {
                        pf("Case %llu: %llu\n",cs++,mid+1);
                        break;
                    }
                }
                ck=1;
                break;
            }
            if(lo==mid)
                break;
            else if(zerocount(mid)<n)
                lo=mid;
            else if(zerocount(mid)>n)
                hi=mid;
        }
        if(ck==0)
            pf("Case %llu: impossible\n",cs++);
    }
}
 
 
