
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

#define sll(t) scanf("%lld",&t)

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
struct nod
{
    int zero,one,two,prop;
} tree[siz];
void mrg(int node,int L,int R)
{
    tree[node].zero=tree[L].zero+tree[R].zero;
    tree[node].one=tree[L].one+tree[R].one;
    tree[node].two=tree[L].two+tree[R].two;

}
void build(int node,int b, int e)
{
    if(b==e)
    {
        tree[node].zero=1;
        tree[node].one=0;
        tree[node].two=0;
        tree[node].prop=0;
        return;
    }
    int mid=(b+e)/2;
    int L=node*2;
    int R=L+1;
    build(L,b,mid);
    build(R,mid+1,e);
    mrg(node,L,R);

}
void update_node(int node)
{
    int tmp=tree[node].zero;
    tree[node].zero=tree[node].two;
    tree[node].two=tree[node].one;
    tree[node].one=tmp;

}
void update2(int node)
{
    tree[node*2].prop+=tree[node].prop;
    tree[node*2+1].prop+=tree[node].prop;
    int prp=tree[node].prop;
    prp=prp%3;
    while(prp--)
    {
        update_node(node*2);
        update_node(node*2+1);
    }
    tree[node].prop=0;
}
void update(int node,int b,int e,int i,int j)
{
    //cout<<"yy\n";
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].prop++;
        update_node(node);
        return;
    }
    if(tree[node].prop)
        update2(node);
    int L,R,mid=(b+e)/2;
    L=node*2;
    R=L+1;
    update(L,b,mid,i,j);
    update(R,mid+1,e,i,j);
    mrg(node,L,R);
}
int query(int node,int b,int e,int i,int j)
{
    if (i > e || j < b) return 0;
    if (b >= i && e <= j)
    {
        return tree[node].zero;
    }
    if(tree[node].prop)
        update2(node);
    int L,R,mid=(b+e)/2;
    L=node*2;
    R=L+1;
    int a=query(L,b,mid,i,j);
    int c=query(R,mid+1,e,i,j);
    return a+c;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,m,x,y,ck,t,r,n,ans,rem,cnt,sum,cs=1;
    si(t);
    while(t--)
    {
        si(n),si(m);
        for(i=1; i<=n*3; i++)
            tree[i].zero=tree[i].one=tree[i].two=tree[i].prop=0;
        build(1,1,n+1);
        printf("Case %d:\n",cs++);
        for(i=0; i<m; i++)
        {
            si(cnt);
            si(x),si(y);
            x++,y++;
            if(cnt==0)
                update(1,1,n+1,x,y);
            else
                printf("%d\n",query(1,1,n+1,x,y));
        }
    }

}
