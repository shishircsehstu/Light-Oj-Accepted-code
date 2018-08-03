#include<stdio.h>
int main()
{
    long int a,n,i,sum,t;
    scanf("%ld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%ld",&n);
        sum=0;
        while(n>0)
        {
            sum+=n%2;
            n=n/2;
        }
        if(sum%2==0)
            printf("Case %ld: even\n",i);
        else
            printf("Case %ld: odd\n",i);
    }
    return 0;
}
 
