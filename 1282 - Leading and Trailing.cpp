// leading and trailing....
#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
int big(ll b,ll p,ll m)
{
    if(p==0)
        return 1;
    else if(p%2==0)
    {
        ll x;
        x=big(b,p/2,m)%m;
        return (x%m*x%m)%m;
    }
    else
    {
        ll y,z;
        y=b%m;
        z=big(b,p-1,m);
        return (y%m*z%m)%m;
 
    }
}
int main()
{
    ll b,p,e,t,cs=1;
    double b1,p1,x;
    cin>>t;
    while(t--)
    {
        cin>>b>>p;
        b1=b;
        p1=p;
        printf("Case %lld: ",cs++);
        x=p1*log10(b1);
        x=x-int(x);
        x=pow(10,x)*100;
        cout<<int(x)<<" ";
        e= big(b,p,1000);
        if(e<10)
            cout<<"00"<<e;
        else if(e>9&&e<100)
            cout<<"0"<<e;
        else
            cout<<e;
        cout<<endl;
    }
}
 
