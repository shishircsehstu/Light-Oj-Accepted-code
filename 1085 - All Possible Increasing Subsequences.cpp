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
#define mod 1000000007
typedef long long ll;
using namespace std;
 
//ll dx[]= {-1,-1,0,0,1,1};
//ll dy[]= {-1,0,-1,1,0,1};
//ll dx[]= {0,0,1,-1};/*4 side move*/
//ll dy[]= {-1,1,0,0};/*4 side move*/
//ll dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//ll dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//ll dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//ll dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
map<ll,bool>visi;
ll ar[siz],ar2[siz];
map<ll,int>vis,indx;
ll tree[siz];
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e||j<b) return 0;
    if(b>=i&&e<=j)
    {
        return tree[node];
    }
    ll L=2*node;
    ll R=L+1;
    ll mid=(b+e)/2;
    ll a=query(L,b,mid,i,j);
    ll c=query(R,mid+1,e,i,j);
 
    return a+c;
}
void update(ll node,ll b,ll e,ll i,ll value)
{
    if(i>e||b>i) return;
    if(b>=i&&e<=i)
    {
        tree[node]+=value;
        return;
    }
    ll L=2*node;
    ll R=L+1;
    ll mid=(b+e)/2;
    update(L,b,mid,i,value);
    update(R,mid+1,e,i,value);
    tree[node]=tree[L]+tree[R];
}
int main()
{
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll  i,j,n,m,a,c,b,d,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0; i<n; i++)
        {
            scanf("%lld",&ar[i]);
            ar2[i]=ar[i];
        }
        sort(ar2,ar2+n);
        cnt=1;
        ans=0;
        for(i=0; i<n; i++)
        {
            if(vis[ar2[i]]==0)
            {
                indx[ar2[i]]=cnt++;
                vis[ar2[i]]=1;
            }
        }
        for(i=0; i<n; i++)
        {
            x=ar[i];
            lo=indx[x];
            // cout<<"x="<<x<<endl;
            // cout<<"lo="<<lo;
            sum=query(1,1,cnt,1,lo-1)+1;
            //  cout<<" "<<sum<<endl;
            ans+=sum;
            ans%=mod;
            sum%=mod;
            update(1,1,cnt,lo,sum);
        }
        printf("Case %lld: %lld\n",cs++,ans);
        vis.clear();
        indx.clear();
        mem(tree);
    }
}
