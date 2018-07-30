/******************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                   *
 *                     Saddam Hossain shishir                     *
 *       Hajee Mohammad Danesh Science & Technology University    *
 *                                                                *
 ***************************************************************** */
#include<bits/stdc++.h>
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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
int pr[siz];
struct edge
{
    ll  u,v,w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};
struct edge2
{
    ll  u2,v2,w2;
    bool operator < ( const edge2& p ) const
    {
        return w2 > p.w2;
    }
};
vector<edge>e;
vector<edge2>e2;
ll find(ll  r)
{
    return (pr[r]==r) ? r:  find(pr[r]);
}
ll  mst(ll  n)
{
    sort(e.begin(),e.end());
    for(ll  i=0; i<=n; i++)
        pr[i]=i;
    ll  count=0,s=0;
    /*
    for(int i=0; i<e.size(); i++)
    {
        cout<<e[i].u<<' '<<e[i].v<<" "<<e[i].w<<endl;
    }
    cout<<endl;
    */
    for(ll  i=0; i<e.size(); i++)
    {
        //cout<<"u="<<e[i].u<<endl;;
        // cout<<"v="<<e[i].v<<endl;;
        int x,y;
        x=e[i].u;
        y=e[i].v;
        ll  u=find(e[i].u);
        ll  v=find(e[i].v);
        if(u!=v)
        {
            // cout<<"x="<<x<<" y="<<y<<endl;
            pr[u]=v;
            count++;
            s+=e[i].w;
            if(count==n) break;
        }
    }
    return s;
}
ll  mst2(ll  n)
{
    sort(e2.begin(),e2.end());
    // reverse(e2.begin(),e2.end());
    for(ll  i=0; i<=n; i++)
        pr[i]=i;
    ll  count=0,s=0;
    /*
    for(int i=0; i<e2.size(); i++)
    {
        cout<<e2[i].u2<<' '<<e2[i].v2<<" "<<e2[i].w2<<endl;
    }
    cout<<endl;
    */
    for(ll  i=0; i<e2.size(); i++)
    {
        //cout<<"u="<<e[i].u<<endl;;
        // cout<<"v="<<e[i].v<<endl;;
        int x,y;
        x=e2[i].u2;
        y=e2[i].v2;
        ll  u=find(e2[i].u2);
        ll  v=find(e2[i].v2);
        if(u!=v)
        {
            // cout<<"x="<<x<<" y="<<y<<endl;
            pr[u]=v;
            count++;
            s+=e2[i].w2;
            if(count==n) break;
        }
    }
    return s;
}
int  main()
{
    ll  n,m,ans,t,cs=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        while(1)
        {
            ll  u,v,w;
            cin>>u>>v>>w;
            if(u==0&&v==0&&w==0)
                break;
            edge get;
            edge2 get2;
            get.u=u;
            get.v=v;
            get.w=w;
            get2.u2=u;
            get2.v2=v;
            get2.w2=w;
            e.push_back(get);
            e2.push_back(get2);
        }
        ll minvalue,maxvalue;
        // cout<<endl;
        minvalue=mst(n);
        // cout<<minvalue<<endl;
        maxvalue=mst2(n);
        // cout<<maxvalue<<endl;
 
        // e.clear();
        printf("Case %lld: ",cs++);
        ans=minvalue+maxvalue;
        if(ans%2==0)
            printf("%lld\n",ans/2);
        else
            printf("%lld/2\n",ans);
        e.clear();
        e2.clear();
    }
    return 0;
}
 
