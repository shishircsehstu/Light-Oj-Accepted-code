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
#define one(x) __builtin_popcount(x)
using namespace std;
string v[1000];
int r,r2,r3,y=1;
void back()
{
    if(r2<0)
    {
        pf("Ignored\n");
        r2=0;
    }
    else
    {
        cout<<v[r2]<<endl;
        r3++;
    }
    y=0;
}
void forward()
{
    r3--;
    if(r<=r2-1||r3<0)
    {
        cout<<"Ignored\n";
        r3=0;
    }
    else
    {
        ++r2;
        cout<<v[r2]<<endl;
    }
}
int main()
{
    int i,j,n,k,t,cs=1;
    string a,b,c;
    sc("%d",&t);
    while(t--)
    {
        pf("Case %d:\n",cs++);
        v[0]="http://www.lightoj.com/";
        cin>>a;
        while(a!="QUIT")
        {
            if(a=="VISIT")
            {
                r2++;
                r=r2;
                cin>>b;
                cout<<b<<endl;
                v[r]=b;
                r3=0;
            }
            else if(a=="BACK")
            {
                r2=r2-1;
                back();
            }
            else if(a=="FORWARD")
            {
                forward();
            }
            cin>>a;
        }
        r=r2=r3=0;
    }
}
 
