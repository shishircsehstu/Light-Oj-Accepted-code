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
map<ll,bool>visi;
int ar[siz];
bool L[siz],R[siz];
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int   i,j,n,m,a,c,b,d,ck,t,r,x,y,ans,rem,cnt,cnt2,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        memset(L,false,sizeof L);
        memset(R,false,sizeof R);
        cnt=cnt2=0;
        si(n);
        for(i=0; i<n; i++)
        {
            si(x),si(y),si(c);
            if(L[x]==false&&R[y]==false)
            {
                L[x]=R[y]=true;
                cnt+=c;
            }
            else
            {
                L[y]=R[x]=true;
                cnt2+=c;
            }
        }
        printf("Case %d: %d\n",cs++,min(cnt,cnt2));
    }
 
 
}
 
