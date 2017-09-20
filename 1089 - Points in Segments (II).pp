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

#define sll(t) scanf("%lld",&t)

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
#define siz 500009
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
struct two
{
    int a,b;
} two[siz];
map<int,int>mp,mp2;
int ar[500007],indx[500007],quert[500001];

struct info
{
    int prop,sum;
} tree[siz*3];
void update(int node,int b,int e,int i,int j,int x)
{
    int Left,Right,mid;
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    Left=node*2;
    Right=(node*2)+1;
    mid=(b+e)/2;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e,int i,int j,int carry=0)
{
    int Left,Right,mid,p1,p2;
    if (i > e || j < b) return 0;
    if(b>=i && e<=j) return tree[node].sum+carry*(e-b+1);
    Left=node<<1;
    Right=(node<<1)+1;
    mid=(b+e)>>1;

    p1 = query(Left, b,mid, i, j, carry+tree[node].prop);
    p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int i,j,m,a,n,c,b,d,ck,t,r,ans,x,y,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        si(n),si(m);
        mem(tree);
        mp2.clear(),mp.clear();
        r=0;
        for(i=0; i<n; i++)
        {
            si(x),si(y);
            if(mp[x]==0)
            {
                ar[r++]=x;
                mp[x]=1;
            }
            if(mp[y]==0)
            {
                ar[r++]=y;
                mp[y]=1;
            }
            two[i].a=x;
            two[i].b=y;
        }
        for(i=0; i<m; i++)
        {
            si(x);
            quert[i]=x;
            if(mp[x]==0)
            {
                ar[r++]=x;
                mp[x]=1;
            }
        }

        sort(ar,ar+r);

        for(i=0; i<r; i++)
        {
            mp2[ar[i]]=i;
        }

        for(i=0; i<n; i++)
        {
            x=two[i].a;
            y=two[i].b;
            a=mp2[x];
            b=mp2[y];
            update(1,0,r,a,b,1);
        }
        printf("Case %d:\n",cs++);
        for(i=0; i<m; i++)
        {
            x=quert[i];
            x=mp2[x];
            printf("%d\n",query(1,0,r,x,x));
        }
    }
}
