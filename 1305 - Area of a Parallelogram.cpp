#include<stdio.h>
#include<math.h>
int main()
{
    double x,y,x1,x2,y1,y2,x3,y3,x4,y4,a,b;
    int t,i;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        x=(x1+x3)/2;
        y=(y1+y3)/2;
        x4=2*x-x2;
        y4=2*y-y2;
        a=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
        if(a<0)
            a=a*-1;
        printf("Case %d: ",i);
        printf("%.0lf %.0lf %.0lf\n",x4,y4,a);
    }
    return 0;
}
 
