#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<map>
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
typedef long long li;
using namespace std;
vector<int>v;
int ar[35];
string st[1000];
int main()
{
    li i,j,v,mx,num,min,n,l,w,h,t,cs=1;
    string s,s1,name;
    sc("%lld",&t);
    while(t--)
    {
        sc("%lld",&n);
        mx=-1;
        min =100000000;
        for(i=0; i<n; i++)
        {
            cin>>name;
            sc("%lld%lld%lld",&l,&w,&h);
            v=l*w*h;
            if(v>mx)
            {
                mx=v;
                s=name;
            }
            if(min>v)
            {
                min=v;
                s1=name;
            }
        }
        pf("Case %lld: ",cs++);
        if(mx==min)
            pf("no thief\n");
        else
            cout<<s<<" took chocolate from "<<s1<<endl;
    }
}
 
 
