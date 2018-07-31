#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
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
#define Sin(a) sin((pi*a)/180)
#define one(x) __builtin_popcount(x)
 
using namespace std;
int main()
{
    double b,r,a,n;
    int i,j,k,t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>r>>n;
        a=180/n;
        pf("Case %d: ",cs++);
 
        b=(Sin(a)*r)/(1+Sin(a));
        pf("%.10lf\n",b);
    }
 
}
 
 
 
