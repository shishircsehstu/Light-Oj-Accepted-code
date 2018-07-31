#include<iostream>
#include<cstdio>
using namespace std;
#define mx 1000005
#define mo 1000003
typedef long long int ll;
ll a[mx];
ll a1[mx];
int mod(ll a, ll m)
{
    if(m==1)
        return a;
    if(m%2==1)
        return(mod(a,m-1)*a)%mo;
    else
    {
        ll res=mod(a,m/2);
        return (res*res)%mo;
    }
}
int main()
{
    a[0]=1;
    ll i,j,k;
    for(i=1; i<=1000000; i++)
    {
        a[i]=(a[i-1]*i)%mo;
    }
    ll n,r,sum,sum1,hi,t,h=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        sum=a[n];
        sum1=((a[n-r]%mo)*(a[r]%mo))%mo;
        hi=mod(sum1,mo-2);
        cout<<"Case "<<h++<<": ";
        cout<<(sum*hi)%mo<<endl;
    }
    return 0;
}
 
