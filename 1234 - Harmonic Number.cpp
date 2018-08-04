#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define mx 1000010
typedef long long int LL;
double ar[mx];
void sive()
{
    LL i,k=1;
    for(i=1; i<=mx; i++)
    {
        ar[i]=1.0/i+ar[i-1];
    }
}
int main()
{
    sive();
    LL n,t,i=1;
    cin>>t;
    while(t--)
    {
        double x;
        cin>>n;
        if(n<=1000000)
            x=ar[n];
        else
            x=log(n+.5)+ 0.5772156649;
        cout<<"Case "<<i++<<": ";
        printf("%.10lf\n",x);
    }
}
