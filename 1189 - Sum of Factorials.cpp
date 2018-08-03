#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int ar[100];
map<int,int>mp;
vector<int>vec;
vector<int>vec1;
long long fact[10001];
void fac()
{
    int i;
    long long sum=1;
    fact[0]=1;
    for(i=1; i<=20; i++)
    {
        sum*=i;
        fact[i]=sum;
    }
}
int main()
{
    fac();
    long long i,j,n,k,t,cs=1;
    long long sum,sum2;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        sum=sum2=0;
        for(i=0; i<=n; i++)
        {
            if(fact[i]<=n)
            {
                vec.push_back(i);
            }
            else
                break;
        }
        for(i=vec.size()-1; i>=0; i--)
        {
            sum+=fact[vec[i]];
            if(sum<=n)
            {
                sum2+=fact[vec[i]];
                vec1.push_back(vec[i]);
            }
            else
                sum-=fact[vec[i]];
        }
        printf("Case %lld: ",cs++);
        if(sum2==n)
        {
            for(i=vec1.size()-1; i>=0; i--)
            {
                printf("%lld!",vec1[i]);
                if(i>0)
                    printf("+");
            }
            printf("\n");
        }
        else
            printf("impossible\n");
        vec.clear();
        vec1.clear();
    }
 
}
 
