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
int dx[]= {1,1,2,2,-1,-1,-2,-2}; /*knight move*/
int dy[]= {2,-2,1,-1,2,-2,1,-1}; /*knight move*/

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
int arr[20][20],dis[20][20],dis2[20][20],dis3[20][20],reslt[20][20];
vector<pii>vec;
int vis[20][20],n,m,kngt;
void bfs(int x,int y,int freq)
{
    mem(vis),mem(dis3),mem(dis2);
    //cout<<"Yes "<<freq<<endl;;
    queue<pii>qe;
    pii ppa;
    qe.push(make_pair(x,y));
    dis[x][y]++;
    dis3[x][y]=0;
    vis[x][y]=1;
    int xx,yy;
    while(!qe.empty())
    {
        ppa=qe.front();
        qe.pop();
        x=ppa.first, y=ppa.second;
        for(int i=0; i<8; i++)
        {
            xx=x+dx[i];
            yy=y+dy[i];
            if(xx>=1&&xx<=n && yy>=1&&yy<=m && vis[xx][yy]==0)
            {
                //cout<<xx<<" "<<yy<<"-->"<<dis3[xx][yy]<<endl;
                dis[xx][yy]++;
                dis2[xx][yy]+=(dis3[x][y]+1);
                dis3[xx][yy]=dis3[x][y]+1;
                qe.push(make_pair(xx,yy));
                vis[xx][yy]=1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int k=ceil(double(dis2[i][j])/(double)freq);
            reslt[i][j]+=k;
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,a,b,ck,t,r,ans,rem,cnt,lo,hi,x,y,sum,cs=1;
    char ch;
    si(t);
    while(t--)
    {
        si(n),si(m);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf(" %c",&ch);
                if(ch!='.')
                {
                    vec.pb(make_pair(i,j));
                    arr[i][j]=ch-'0';
                }
            }
        }
        kngt=vec.size();
        for(i=0; i<vec.size(); i++)
        {
            x=vec[i].first,y=vec[i].second;
            bfs(x,y,arr[x][y]);
        }
        ans=9999999;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(reslt[i][j]&&dis[i][j]==kngt)
                    ans=min(ans,reslt[i][j]);
            }
            // cout<<endl;
        }
        if(kngt==1||kngt==0)
            printf("Case %d: 0\n",cs++);
        else if(kngt>1&&ans==9999999)
            printf("Case %d: -1\n",cs++);
        else
            printf("Case %d: %d\n",cs++,ans);
        mem(reslt),mem(dis);
        vec.clear();
    }


}
/*
10 10
..........
.2....2...
......2...
1.........
...2.1....
...1......
..........
.......21.
..........
..........


6 5
.....
.....
9...5
.....
2....
...9.


*/
