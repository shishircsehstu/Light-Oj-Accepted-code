#include<stdio.h>
int main()
{
    long int n,m,t,i=1;
    scanf("%ld",&t);
    while(t)
    {
        scanf("%ld%ld",&n,&m);
        printf("Case %ld: %ld\n",i++,n/2*m);
        t--;
    }
}
