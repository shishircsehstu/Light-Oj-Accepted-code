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

#define all(v) v.begin(),v.end()

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


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector

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
int ar[siz];

struct node
{
    int valu,indx;
} tree[siz],ar2[siz];
void initia(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].valu=ar2[b].valu;
        tree[node].indx=ar2[b].indx;
        return;
    }
    int L=2*node;
    int R=L+1;
    int mid=(b+e)/2;
    initia(L,b,mid);
    initia(R,mid+1,e);
    if(tree[L].valu<=tree[R].valu)
    {
        tree[node].valu=tree[R].valu;
        tree[node].indx=tree[R].indx;
    }
    else
    {
        tree[node].valu=tree[L].valu;
        tree[node].indx=tree[L].indx;
    }
}
pii query(int node,int b,int e,int i,int j)
{
    pii xx,yy;
    if(i>e||j<b) return make_pair(-1,-1);
    if(b>=i&&e<=j)
    {
        return make_pair(tree[node].valu,tree[node].indx);
    }
    int L=2*node;
    int R=L+1;
    int mid=(b+e)/2;
    xx=query(L,b,mid,i,j);
    yy=query(R,mid+1,e,i,j);
    if(xx.first<=yy.first)
    {
        return yy;
    }
    else
        return xx;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  n,i,j,a,b,x,y,ck,t,r,ans,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        mem(ar);
        si(n),si(a),si(b);
        pii xx;
        for(i=0; i<=3*n; i++)
            ar2[i].indx=ar2[i].valu=tree[i].indx=tree[i].indx=0;
        for(i=1; i<=n; i++)
        {
            si(x);
            ar[x]++;
            ar2[i].valu=ar[x];
            ar2[i].indx=i;
        }
        ans=-1;
        initia(1,1,n);
        printf("Case %d:\n",cs++);
        for(i=0; i<b; i++)
        {
            ans=-1;
            si(x),si(y);
            xx=query(1,1,n,x,y);
            // cout<<xx.first<<"  "<<xx.second<<endl;
            ans=min(xx.second-x+1,xx.first);
            xx=query(1,1,n,xx.second+1,y);
            ans=max(ans,xx.first);
            printf("%d\n",ans);
        }
    }

}
