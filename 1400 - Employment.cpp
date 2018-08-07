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
#define siz 1001
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
map<ll,bool>visi;
int ar[siz],wife[siz],hus[siz],pow2[1001][1001],men[1001][1001],woman[1001][1001],cnt[siz];
int stable(int n)
{
    int i,j;
    for(i=1; i<=n; i++) cnt[i]=1;
    for(i=n+1; i<=2*n; i++)
    {
        for(j=1; j<=n; j++)
            pow2[i][woman[i][j]]=j;
 
    }
    queue<int>Q;
    for(i=1; i<=n; i++) Q.push(i);
    while(!Q.empty())
    {
        int m=Q.front();
        int w=men[m][cnt[m]];
        if(hus[w]==0)
        {
            wife[m]=w;
            hus[w]=m;
            Q.pop();
            //  cout<<m<<"-->"<<w<<endl;
        }
        else if(pow2[w][m]<pow2[w][hus[w]])
        {
            Q.pop();
            // cout<<m<<"--."<<w<<"  "<<hus[w]<<endl;
            wife[m]=w;
            Q.push(hus[w]);
            hus[hus[w]]=0;
            hus[w]=m;
        }
        cnt[m]++;
    }
 
}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,b,d,ck,t,r,x,y,ans,rem,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        si(n);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                si(men[i][j]);
        for(i=n+1; i<=2*n; i++)
            for(j=1; j<=n; j++)
                si(woman[i][j]);
        stable(n);
        printf("Case %d: ",cs++);
        for(i=1; i<=n; i++)
        {
            printf("(");
            printf("%d %d",i,wife[i]);
            printf(")");
            if(i<n) printf(" ");
        }
        printf("\n");
        mem(hus),mem(cnt),mem(wife);
    }
}
/*
4
6 8 7 5
8 6 5 7
6 7 8 5
7 5 8 6
1 3 4 2
2 4 1 3
4 2 1 3
2 1 4 3
 
output: (3 5) (1 6) (4 7) (2 8)
*/
 
