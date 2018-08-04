#include<stdio.h>
#include<string.h>
#define mx 203
int main()
{
    char s[mx];
    long long int n,i,k,t,len,r,re,j=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s%lld",s,&n);
        len=strlen(s);
        re=0;
        for(i=0; i<len; i++)
        {
            if(s[i]!='-')
            {
                re=s[i]-'0'+re*10;
                re=re%n;
            }
        }
        printf("Case %lld: ",j++);
        if(re==0)
            printf("divisible\n");
        else
            printf("not divisible\n");
    }
}
 
