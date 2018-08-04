//BISMILLAHIR RAHMANIR RAHIM
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<set>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
 
#define sc scanf
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%I64d",&t)
#define sii(a,b) scanf("%d%d",&a,&b)
 
#define P(a) printf("%d\n",a)
#define PLN(a) printf("%I64d ",a)
#define pf printf
 
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
 
#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,-1,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
int cval[1001];
int ncoin[10001];
int dp[51][1001];
int n;
int call(int i,int am)
{
    if(i>=n+1)
    {
        if(am==0)return 1;
        else return 0;
    }
    if(dp[i][am]!=-1) return dp[i][am];
    int ret1=0;
    for(int j=1; j<=ncoin[i]; j++)
    {
        if(am-cval[i]*j>=0)
        {
            ret1+=(call(i+1,am-cval[i]*j))%100000007;
            //cout<<"i="<<i<<"j="<<j<<" am="<<am<<endl;
        }
        else
            break;
    }
    // cout<<"ii="<<i<<endl<<endl;
    ret1+=(call(i+1,am))%100000007;
    // cout<<"age naki pore\n\n";
    return dp[i][am]=ret1%100000007;
}
int main()
{
    int i,j,ans,t,amount,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        mem(dp);
        scanf("%d%d",&n,&amount);
        for(i=1; i<=n; i++)
            scanf("%d",&cval[i]);
        for(i=1; i<=n; i++)
            scanf("%d",&ncoin[i]);
        ans=call(1,amount);
        printf("Case %d: %d\n",cs++,ans);
    }
}
/*
2
3 5
1 2 5 3 2 1
 
4 20
1 2 3 4 8 4 2 1
 
Case 1: 3
Case 2: 9
*/
 
