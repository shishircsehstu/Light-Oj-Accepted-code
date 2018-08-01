#include<stdio.h>
int main()
{
    long int i,a,b,s,cn,to,h,t,j=1;
    scanf("%ld",&t);
    while(t)
    {
        scanf("%ld%ld",&a,&b);
        cn=0;
        for(i=1; i<=3; i++)
        {
            if(a%3==1)
            {
                s=a;
                break;
            }
            else
            {
                cn++;
                a++;
            }
        }
        to=b-s+1;
        h=((b-s)+3)/3;
        printf("Case %ld: %ld\n",j++,to-h+cn);
        t--;
    }
    return 0;
}
 
