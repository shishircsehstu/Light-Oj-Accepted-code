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
#define siz 10000001
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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
int vis[200][201];
char str[21][21];
int d[1001][1001];
void bfs(int sx,int sy,int row,int col)
{
    mem(d);
    mem(vis);
    int j,r;
    memset(vis,0,sizeof vis);
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        j=r=0;
        for(int k=0; k<4; k++)
        {
            int tx=top.ff+dx[k];
            int ty=top.ss+dy[k];
            if(tx>=0&&tx<row &&ty>=0&&ty<col &&str[tx][ty]!='#'&&str[tx][ty]!='m'&&vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                d[tx][ty]=d[top.ff][top.ss]+1;
                q.push(pii(tx,ty));
            }
        }
    }
}
int main()
{
    int a1,a2,b1,b2,c1,c2,h1,h2,i,j,n,k,m,cnt,ans,sum,x,x1,x2,r,t,cs=1;
    si(t);
    while(t--)
    {
        si(m),si(n);
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                cin>>str[i][j];
                if(str[i][j]=='a')
                {
                    a1=i,a2=j;
                }
                else if(str[i][j]=='b')
                {
                    b1=i;
                    b2=j;
                }
                else if(str[i][j]=='c')
                {
                    c1=i;
                    c2=j;
                }
                else if(str[i][j]=='h')
                {
                    h1=i;
                    h2=j;
                }
            }
        }
        bfs(a1,a2,m,n);
        x=d[h1][h2];
        mem(d);
        bfs(b1,b2,m,n);
        x1=d[h1][h2];
        mem(d);
        bfs(c1,c2,m,n);
        x2=d[h1][h2];
        x=max(x,x1);
        x=max(x,x2);
        printf("Case %d: %d\n",cs++,x);
    }
 
    // cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<" "<<c1<<"  "<<c2<<" "<<h1<<" "<<h2<<endl;
}
 
