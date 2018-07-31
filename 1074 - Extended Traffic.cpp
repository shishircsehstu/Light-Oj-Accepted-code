//BISMILLAHIR RAHMANIR RAHIM
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
 
#define pii pair<int,int>
#define pi acos(-1.0)
#define PI 3.1415926535897932385
#define Sin(a) sin((pi*a)/180)
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
typedef long long ll;
using namespace std;
#define MAXN 100001
int ar[1000001];
int edge_u[MAXN],edge_v[MAXN],edge_cost[MAXN];
long long d[siz];
int main()
{
    int node,edge,x,y,cost,i,qe,num,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&node);
        for(i=1; i<=node; i++)
            scanf("%d",&ar[i]);
        for( i=1; i<=node; i++) d[i]=1000000000;
        d[1]=0;
        scanf("%d",&edge);
        for( i=1; i<=edge; i++)
        {
            scanf("%d%d",&x,&y);
            edge_u[i]=x;
            edge_v[i]=y;
            edge_cost[i]=(ar[y]-ar[x])*(ar[y]-ar[x])*(ar[y]-ar[x]);
        }
        int neg_cycle=false;
        for(int step=1; step<=node; step++)
        {
            int updated=false;
            for( i=1; i<=edge; i++)
            {
                int u=edge_u[i],v=edge_v[i];
                // cout<<"d ="<<d[u]<<endl;
                if(d[u]+edge_cost[i]<d[v])
                {
                    updated=true;
                    if(step==node)neg_cycle=true; //If we can update in n'th step, there is a negative cycle
                    d[v]=d[u]+edge_cost[i];
                    //cout<<"v="<<v<<' ';
                    //cout<<"d2="<<d[v]<<endl;
                }
            }
            if(updated==false)break; //If we can't update in a any step, no need to try anymore
        }
        scanf("%d",&qe);
        printf("Case %d:\n",cs++);
        for(i=1; i<=qe; i++)
        {
            scanf("%d",&num);
            if(d[num]>2&&num[d]<6860)
                printf("%lld\n",d[num]);
            else
                printf("?\n");
        }
        mem(d);
    }
    return 0;
}
 
 
