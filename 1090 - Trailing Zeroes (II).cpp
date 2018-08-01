#include<stdio.h>
typedef long int Ld;
Ld div(Ld,Ld);
Ld di(Ld n,Ld r)
{
    Ld cnt=0;
    while(n>0)
    {
        cnt+=n/r;
        n/=r;
    }
    return cnt;
}
Ld div(Ld m,Ld r)
{
    Ld d,cnt=0;
    while(m>0)
    {
        if(m%r==0)
            cnt++;
        if(m%r!=0)
            break;
        m/=r;
    }
    return cnt;
}
int main()
{
    Ld n,r,p,q,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,cnt,t,j=1;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld%ld%ld",&n,&r,&p,&q);
        cnt=0;
        s1=di(n,5);
        s2=di(n,2);
        s3=di(r,5);
        s4=di(r,2);
        s5=di(n-r,5);
        s6=di(n-r,2);
        s7=s3+s5;
        s8=s4+s6;
        s9=div(p,5)*q;
        s11=s1+s9;
        s10=div(p,2)*q;
        s12=s10+s2;
        s13=s12-s8;
        s14=s11-s7;
        printf("Case %ld: ",j++);
        if(s13>s14)
            printf("%ld\n",s14);
        else
            printf("%ld\n",s13);
    }
}
 
