#include<stdio.h>
int main()
{
    long long int n,i,r,j,t,s;
    scanf("%lld",&t);
    for(j=1; j<=t; j++)
    {
        scanf("%lld",&n);
        if(n%2==1)
            printf("Case %lld: Impossible\n",j);
        else
        {
            r=1;
            while(n>0)
            {
                n=n/2;
                r*=2;
                if(n%2==1)
                    break;
            }
            if(n==1)
                printf("Case %lld: Impossible\n",j);
            else
                printf("Case %lld: %lld %lld\n",j,n,r);
        }
    }
    return 0;
}
