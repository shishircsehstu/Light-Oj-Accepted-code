#include<stdio.h>
#include<math.h>
#define pi acos(-1)
int main()
{
    int i,te;
    double r,are1,sq,are2;
    scanf("%d",&te);
    for(i=1; i<=te; i++)
    {
        scanf("%lf",&r);
        sq=2*r;
        are1=sq*sq;
        are2=pi*r*r;
        printf("Case %d: %.2lf\n",i,are1-are2);
    }
    return 0;
}
 
