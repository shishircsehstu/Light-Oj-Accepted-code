#include<bits/stdc++.h>
using namespace std;
long long ar[100001];
int main()
{
    long long i,j,n,x,y,sum,mx,t,cnt,cs=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        cnt=0;
        mx=0;
        y=0;
        for(i=0; i<n; i++)
        {
            scanf("%lld",&ar[i]);
            if(ar[i]-y>mx)
                mx=ar[i]-y;
            y=ar[i];
        }
        sum=mx;
        // cout<<"mx="<<mx<<endl;
        y=0;
        for(i=0; i<n; i++)
        {
            ///cout<<"mx="<<mx<<endl;
            if(ar[i]-y==mx)
                mx--;
            else if(ar[i]-y>mx)
                cnt=1;
            //cout<<"mx="<<mx<<endl;
            y=ar[i];
        }
        printf("Case %lld: %lld\n",cs++,sum+cnt);
    }
    return 0;
}
 
