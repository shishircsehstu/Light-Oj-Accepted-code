#include<stdio.h>
#include <string.h>
#include<iostream>
typedef long long LL;
LL lcm1(LL,LL);
LL gcd(LL,LL);
int main()
{
    LL i,j,n,lcm,hi,lo,a,b,c,t,lcm2;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        lcm=lcm1(a,b);
        if(lcm>c||c%lcm!=0)
            printf("Case %lld: impossible\n",i);
        else
        {
            hi = c/lcm;
            lo = gcd(hi,lcm);
            while(lo != 1)
            {
                hi = hi*lo, lcm = lcm/lo;
                lo = gcd(hi,lcm);
            }
            printf("Case %lld: %lld\n",i,hi);
        }
    }
    return 0;
}
LL lcm1(LL m,LL n)
{
    LL lcm=m*n/gcd(m,n);
    return lcm;
}
LL gcd(LL m,LL n)
{
    int re,h;
    while(1)
    {
        if(m<n)
        {
            h=n;
            n=m;
            m=h;
        }
        re=m%n;
        if(re==0)
            return n;
        else
        {
            m=n;
            n=re;
        }
    }
}
