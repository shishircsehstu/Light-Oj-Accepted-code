#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
 
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define endl '\n'
#define pii pair(li ,li )
#define pi acos(-1.0)
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define one(x) __builtin_popcount(x)
//#define mem(ar) memset(ar,0,sizeof ar)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long li;
 
using namespace std;
#define mx 100001
li  n;
struct info
{
    li  prop,sum;
} tree[mx*3+1];
li  query(li  node,li  b,li  e,li  i,li  j,li  carry=0)
{
    li  Left,Right,mid,p1,p2;
    if (i > e || j < b) return 0;
 
    if(b>=i and e<=j) return tree[node].sum+carry*(e-b+1);
 
    Left=node<<1;
    Right=(node<<1)+1;
    mid=(b+e)>>1;
    p1= query(Left, b,mid, i, j, carry+tree[node].prop);
    p2= query(Right, mid+1, e, i, j,carry+tree[node].prop);
    return p1+p2;
}
void update(li  node,li  b,li  e,li  i,li  j,li  x)
{
    li  Left,Right,mid;
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
/*
void initial()
{
    for(li  i=0; i<=400000; i++)
    {
        tree[i].prop=0;
        tree[i].sum=0;
    }
}
*/
int  main()
{
    li  i,x,hi,lo,m,v,t,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        //initial();
        sc("%lld %lld",&n,&m);
        for(i=0; i<=3*n; i++)
            tree[i].sum=tree[i].prop=0;
        pf("Case %lld:\n",cs++);
        for(i=1; i<=m; i++)
        {
            sc("%lld",&x);
            if(x==0)
            {
                sc("%lld%lld%lld",&lo,&hi,&v);
                update(1,1,n,lo+1,hi+1,v);
            }
            else
            {
                sc("%lld%lld",&lo,&hi);
                pf("%lld\n",query(1,1,n,lo+1,hi+1));
            }
        }
    }
    return 0;
}
 
