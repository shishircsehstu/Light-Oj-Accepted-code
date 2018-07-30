#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#define sc scanf
#define pb push_back
#define pf printf
using namespace std;
int sum;
#define mx 1001
bool isprime[mx];
int ar[1001];
int ar1[1000];
int ar2[1000];
void sive()
{
    int  i,sqt,j,r=0;
    for(i=4; i<=mx; i+=2)
        isprime[i]=true;
    isprime[0]=isprime[1]=true;
    sqt=sqrt(mx);
    for(i=3; i<= sqt; i+=2)
    {
        for(j=2*i; j<=mx; j+=i)
            isprime[j]=true;
    }
    for(i=1; i<=1001; i++)
    {
        if(isprime[i]==0)
            ar[r++]=i;
    }
}
int fat(int sum1)
{
    int r=0;
    while(sum1>=ar[r])
    {
        if(sum1%ar[r]==0)
        {
            ar1[ar[r]]++;
            sum1/=ar[r];
        }
        else
            r++;
    }
    sum=sum1;
}
int main()
{
    sive();
    int n,i,j,sum1,r,t,cs=1;
    cin>>t;
    while(t--)
    {
        r=0;
        cin>>n;
        sum=1;
        for(i=2; i<=n; i++)
        {
            sum*=i;
            sum1=sum;
            fat(sum1);
        }
        cout<<"Case "<<cs++<<": "<<n<<" = ";
        for(i=1; i<=n; i++)
        {
            if(isprime[i]==0)
                ar2[r++]=i;
        }
        for(i=0; i<r; i++)
        {
            cout<<ar2[i];
            pf(" (%d)",ar1[ar2[i]]);
            if(i<r-1)
                pf(" * ");
        }
        pf("\n");
        memset(ar1,0,sizeof ar1);
    }
}
 
