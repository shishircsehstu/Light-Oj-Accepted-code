#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,d,are,k,s,h,t,i=1;
    scanf("%lf",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(a>c)
            k=a-c;
        else
            k=c-a;
        s=(d+b+k)/2;
        are=sqrt((s*(s-d)*(s-k)*(s-b)));
        h=(are*2)/k;
        printf("Case %.0lf: %lf\n",i++,.5*(a+c)*h);
    }
}
 
