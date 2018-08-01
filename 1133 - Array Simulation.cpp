#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int ar[109],ar2[109];
int ad(int,int);
int mul(int,int);
int div1(int,int);
void rev( int n)
{
    reverse(ar,ar+n);
}
int ad(int d,int n)
{
    for(int i=0; i<n; i++)
        ar2[i]=ar[i]+d;
    for(int i=0; i<n; i++)
        ar[i]=ar2[i];
}
int mul(int d,int n)
{
    for(int i=0; i<n; i++)
        ar2[i]=ar[i]*d;
    for(int i=0; i<n; i++)
        ar[i]=ar2[i];
}
int div1(int d,int n)
{
    for(int i=0; i<n; i++)
        ar2[i]=ar[i]/d;
    for(int i=0; i<n; i++)
        ar[i]=ar2[i];
}
int main()
{
    int i,n,k,m,d,t,r=1;
    cin>>t;
    while(t--)
    {
        char ch;
        cin>>n>>m;
        for(i=0; i<n; i++)
            cin>>ar[i];
        for(int j=1; j<=m; j++)
        {
            cin>>ch;
            if(ch=='S')
            {
                cin>>d;
                ad(d,n);
            }
            if(ch=='M')
            {
                cin>>d;
                mul(d,n);
            }
            if(ch=='D')
            {
                cin>>d;
                div1(d,n);
            }
            if(ch=='R')
            {
                rev(n);
            }
            int f;
            if(ch=='P')
            {
                cin>>d>>f;
                swap(ar[d],ar[f]);
            }
        }
        printf("Case %d:\n",r++);
        for(int i=0; i<n; i++)
        {
            cout<<ar[i];
            if(i<n-1)
                cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
 
 
