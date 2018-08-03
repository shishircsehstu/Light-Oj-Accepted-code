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
int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
map<ll,bool>visi;
int ar[siz];
char str[205][205];
int Fire_dis[205][205],Je_dis[205][205];
int vis[205][205],vis2[205][205];
int INF,n,m;
struct graf
{
    int a,b;
} parent,child;
queue<graf>Q,Q2;
int Bfs_J()
{
    graf node;
    while(!Q2.empty())
    {
        node=Q2.front();
        Q2.pop();
        int aa=node.a;
        int bb=node.b;
        for(int i=0; i<4; i++)
        {
            int x=aa+dx[i];
            int y=bb+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0&&str[x][y]!='#')
            {
                Je_dis[x][y]=Je_dis[aa][bb]+1;
                vis[x][y]=1;
                parent.a=x;
                parent.b=y;
                Q2.push(parent);
            }
        }
    }
}
int Bfs_fire()
{
    graf node;
    while(!Q.empty())
    {
        node=Q.front();
        Q.pop();
        int aa=node.a;
        int bb=node.b;
        for(int i=0; i<4; i++)
        {
            int x=aa+dx[i];
            int y=bb+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0&&str[x][y]!='#')
            {
                Fire_dis[x][y]=Fire_dis[aa][bb]+1;
                vis[x][y]=1;
                parent.a=x;
                parent.b=y;
                Q.push(parent);
            }
        }
    }
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,a,c,b,d,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        si(n),si(m);
        memset(Fire_dis,63,sizeof Fire_dis), memset(Je_dis,63,sizeof Je_dis);
        mem(vis);
        INF=Fire_dis[0][0];
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                scanf(" %c",&str[i][j]);
                if(str[i][j]=='F')
                {
                    parent.a=i;
                    parent.b=j;
                    Q.push(parent);
                    Fire_dis[i][j]=0;
                   vis[i][j]=1;
                }
                if(str[i][j]=='J')
                {
                    parent.a=i;
                    parent.b=j;
                    Q2.push(parent);
                    Je_dis[i][j]=0;
                    vis[i][j]=1;
                }
            }
        Bfs_J();
        memset(vis,0,sizeof vis);
        Bfs_fire();
        ans=INF;
        for(i=0; i<m; i++)
        {
            if(Fire_dis[0][i]>Je_dis[0][i]) ans=min(ans,Je_dis[0][i]);
            if(Fire_dis[n-1][i]>Je_dis[n-1][i]) ans=min(ans,Je_dis[n-1][i]);
        }
        for(i=0; i<n; i++)
        {
            if(Fire_dis[i][0]>Je_dis[i][0]) ans=min(ans,Je_dis[i][0]);
            if(Fire_dis[i][m-1]>Je_dis[i][m-1]) ans=min(ans,Je_dis[i][m-1]);
        }
        printf("Case %d: ",cs++);
        if(ans==INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",ans+1);
    }
 
}
 
