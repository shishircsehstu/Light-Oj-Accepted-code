#include<stdio.h>
#include<algorithm>
#define mx 20000
long long  ar[mx];
using namespace std;
int main()
{
    long long int i,j,k,n,m,r,cn,sum,t,w;
    scanf("%lld",&t);
    for(w=1; w<=t; w++)
    {
        scanf("%lld",&n);
        for(i=0; i<n; i++)
            scanf("%lld",&ar[i]);
        sort(ar,ar+i);
        r=0;
        cn=0;
        for (int i = 0; i < n-2; ++i)
        {
            int k = i+2;
            for (int j = i+1; j < n; ++j)
            {
                while (k < n && ar[i] + ar[j] > ar[k])
                    ++k;
                cn += k - j - 1;
            }
        }
        printf("Case %lld: %lld\n",w,cn);
    }
    return 0;
 
}
 
