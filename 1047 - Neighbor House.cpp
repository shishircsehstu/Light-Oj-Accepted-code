/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
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
#define pb push_back
#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65, 'a'=97 '0'=48

vector<int>vec;
map<pii,int>mp;
int ar[101][101],n;
ll ans=99999999999;
ll dp[101][101];
ll cal(int row,int col)
{
    if(row==n)
    {
        return ar[row][col];
    }

    if(dp[row][col]!=0)
    {
        return dp[row][col];
    }
    ll sum1,sum2;
    sum1=sum2=0;
    if(col==1)
    {
        sum1=cal(row+1,col+1);
        sum2=cal(row+1,col+2);

    }
    else if(col==2)
    {
        sum1=cal(row+1,col-1);
        sum2=cal(row+1,col+1);
    }
    else if(col==3)
    {
        sum1=cal(row+1,col-2);
        sum2=cal(row+1,col-1);
    }
    ll sum=min(sum1,sum2);
    return dp[row][col]=(sum+ar[row][col]);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int  i,j,m,a,c,b,d,ck,t,r,rem,cnt,hi,sum,cs=1;
    ll x,y,lo;
    si(t);
    while(t--)
    {
        si(n);
        mem(dp);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=3; j++)
                si(ar[i][j]);

        }
        x=cal(1,1);
        y=cal(1,2);
        lo=cal(1,3);
        lo=min(lo,y);
        lo=min(lo,x);
        //cout<<x<<" "<<y<<" "<<lo<<endl;
        printf("Case %d: %lld\n",cs++,lo);
    }

}
/*
4
13 23 12
77 36 64
44 89 76
31 78 45
*/

