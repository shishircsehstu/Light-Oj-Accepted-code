#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<utility>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define sc scanf
#define pf printf
#define pi acos(-1.0)
#define size 1000001
using namespace std;
int ar[100];
int main()
{
    int i,j,n,cnt,t,n1,n2,cs=1;
    sc("%d",&t);
    while(t--)
    {
        sc("%d",&n);
        cnt=0;
        for(i=0; i<n; i++)
            sc("%d",&ar[i]);
        n1=ar[0];
        while(2<n1)
        {
            cnt++;
            n1-=5;
        }
 
        for(i=0; i<n-1; i++)
        {
            n1=ar[i];
            n2=ar[i+1];
            while(n2>n1)
            {
                cnt++;
                n1+=5;
            }
        }
        pf("Case %d: %d\n",cs++,cnt);
    }
}
 
