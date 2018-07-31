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
int vis[701][711];
map<char,int>mp;
char str[601][601];
int d[701][701],x,y;
vector<pii>vec;
int bfs(int sx,int sy,char ch ,int row,int col)
{
    vec.clear();
    pii pa;
    mem(vis);
    mem(d);
    int j,r,cnt;
    cnt=0;
    vis[sx][sy]=1;
    d[sx][sy]=0;
    queue<pii>q;
    while(!q.empty())
    {
        q.pop();
    }
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
            int ck=0;
            for(int k=0; k<25; k++)
            {
                if(isalpha(str[tx][ty]))
                {
                    if(str[tx][ty]!=ch)
                        ck=1;
                }
            }
            if(tx>=0&&tx<row &&ty>=0&&ty<col &&str[tx][ty]!='#'&&vis[tx][ty]==0&&ck==0)
            {
                // path[tx][ty]=top.ff
                vec.pb(make_pair(top.ff,top.ss));
                d[tx][ty]=d[top.ff][top.ss]+1;
                vis[tx][ty]=1;
                q.push(pii(tx,ty));
                if(str[tx][ty]==ch)
                {
                    for(int k=0; k<vec.size(); k++)
                    {
                        pa=vec[k];
                        vis[pa.ff][pa.ss]=0;
                        str[pa.ff][pa.ss]='.';
                    }
                    vec.clear();
                    cnt+=d[tx][ty];
                    x=tx,y=ty;
                    str[tx][ty]='.';
                    vis[tx][ty]=0;
                    break;
 
                }
            }
        }
        if(cnt) break;
    }
    return cnt;
}
int main()
{
    //freopen("input.txt","r",stdin);
//freopen("A.txt","w",stdout);
    int a1,a2,b1,b2,c1,c2,h1,h2,i,j,n,ck,m,cnt,ans,sum,x1,x2,r,t,lo,cs=1;
    si(t);
  //  printf("\n");
    lo=0;
    while(t--)
    {
      //  if(lo) printf("\n");
        //lo=1;
        mp.clear();
        si(n);
        string st;
        st="BCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf(" %c",&str[i][j]);
                if(str[i][j]=='A')
                    x=i,y=j;
                if(isalpha(str[i][j]))
                    mp[str[i][j]]=1;
 
            }
        }
        sum=ck=0;
        for(i=0; i<25; i++)
        {
            if(mp[st[i]]==1)
            {
                ans=bfs(x,y,st[i],n,n);
                if(ans==0)
                {
                    ck=1;
                    break;
                }
                else
                    sum+=ans;
            }
        }
        if(ck)
            printf("Case %d: Impossible\n",cs++);
        else
            printf("Case %d: %d\n",cs++,sum);
    }
}
 
