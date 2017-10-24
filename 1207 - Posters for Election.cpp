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

#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define sc1(a) cin>>a
#define sc2(a,b) cin>>a>>b
#define pr1(a) cout<<a<<endl
#define pr2(a,b) cout<<a<<" "<<b<<endl
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long li;

using namespace std;
#define mx 100001
li  n;
struct info
{
    li  prop,sum;
} tree[mx*7+1];
int vis[1000001];
void pushDown(int p, int beg, int end)
{
    if(tree[p].prop ==-1)return;
    int mid = (beg + end) >> 1;
    tree[2*p].sum = (mid-beg+1)*tree[p].prop;
    tree[2*p+1].sum = (end-mid)*tree[p].prop;
    tree[2*p].prop = tree[2*p+1].prop = tree[p].prop;
    tree[p].prop =-1;
}
li  query(li  node,li  b,li  e,li  i,li  j)
{
    li  Left,Right,mid,p1,p2;
    if (i > e || j < b) return 0;
    if(b>=i and e<=j)
        return tree[node].sum;
    pushDown(node,b,e);
    Left=node<<1;
    Right=(node<<1)+1;
    mid=(b+e)>>1;
    p1= query(Left, b,mid, i, j);
    p2= query(Right, mid+1, e, i, j);
    return p1+p2;
}
void update(li  node,li  b,li  e,li  i,li  j,li  x)
{
    li  Left,Right,mid;
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].sum=((e-b+1)*x);
        tree[node].prop=x;
        return;
    }
    pushDown(node,b,e);
    Left=node*2;
    Right=(node*2)+1;
    mid=(b+e)/2;
    update(Left,b,mid,i,j,x);

    update(Right,mid+1,e,i,j,x);
    tree[node].sum=tree[Left].sum+tree[Right].sum;  //e-b+1)*tree[node].prop;
}
int  main()
{
    li  i,x,hi,lo,m,v,t,sum,ans,num,cg,cs=1;
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    sc("%lld",&t);
    while(t--)
    {
        sc("%lld",&n);
        for(i=0; i<=6*n; i++)
        {
            tree[i].sum=0;
            tree[i].prop=-1;
        }
        // pf("Case %lld:\n",cs++);
        for(i=1; i<=n; i++)
        {
            sc("%lld%lld",&lo,&hi);
            //update(1,1,2*n,lo,hi,0);
            update(1,1,2*n,lo,hi,i);
            // cout<<sum<<endl;
        }
        ans=0;
        for(i=1; i<=2*n; i++)
        {
            int xx=query(1,1,2*n,i,i);
            if(vis[xx]==0&&xx!=0) ans++;
            vis[xx]=1;
        }
        printf("Case %lld: %lld\n",cs++,ans);
        mem(vis);
    }
    return 0;
}
