#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define siz 1000001
#define one(x) __builtin_popcount(x)
typedef long long li;
using namespace std;
int main()
{
    int ar[101],ar2[101],i,n,x,j,t,cnt,y,cs=1;
    sc("%d",&t);
    while(t--)
    {
        sc("%d",&n);
        cnt=0;
        for(i=1; i<=n; i++)
        {
            sc("%d",&ar[i]);
        }
 
        for(i=1; i<=n; i++)
        {
            if(ar[i]!=i)
            {
                cnt++;
                for(j=1; j<=n; j++)
                {
                    if(ar[j]==i)
                    {
                        y=ar[i];
                        ar[i]=ar[j];
                        ar[j]=y;
                        break;
                    }
                }
            }
        }
        pf("Case %d: %d\n",cs++,cnt);
    }
}
 
