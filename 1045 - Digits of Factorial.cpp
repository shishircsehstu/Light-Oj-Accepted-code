 
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
#include<limits>
#include<limits.h>
 
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
#define mk make_pair
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
 
//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48
 
 
map<ll,bool>visi;
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
 
 
int C[1200];
bool P[1001][1001];
int minPalPartion(char *str)
{
    int n = strlen(str);
 
    int i, j, k, L;
 
    for (i=0; i<n; i++)
        P[i][i] = true;
 
    for (L=2; L<=n; L++)
    {
        for (i=0; i<n-L+1; i++)
        {
            j = i+L-1;
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
        }
    }
 
    for (i=0; i<n; i++)
    {
        if (P[0][i] == true)
            C[i] = 0;
        else
        {
            C[i] = INT_MAX;
            for(j=0; j<i; j++)
            {
                if(P[j+1][i] == true && 1+C[j]<C[i])
                    C[i]=1+C[j];
            }
        }
    }
    return C[n-1];
}
 
char str[1001];
int main()
{
    int i,j,n,k,t,cs=1;
    char ch[10];
    si(t);
    //  scanf("%s",ch);
    while(t--)
    {
        scanf("%s",str);
        printf("Case %d: %d\n",cs++,minPalPartion(str)+1);
    }
    return 0;
}
 
