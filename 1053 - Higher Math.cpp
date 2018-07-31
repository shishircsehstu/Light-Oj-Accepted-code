#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    long  ar[4],i,n,j;
    scanf("%ld",&n);
    for(j=1; j<=n; j++)
    {
        for(i=0; i<3; i++)
            scanf("%ld",&ar[i]);
        sort(ar,ar+3);
        if(ar[2]*ar[2]==ar[0]*ar[0]+ar[1]*ar[1])
            printf("Case %ld: yes\n",j);
        else
            printf("Case %ld: no\n",j);
    }
}
 
