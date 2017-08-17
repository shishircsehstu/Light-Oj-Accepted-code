
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
int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65, 'a'=97 '0'=48
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
map<string,int>dis;
string vec,vec2,vec3,vec4,vec5,vec6,indicate,indicate2;
int answer=0;
int merge_(string st,string st2,string st3)
{
    indicate.clear();
    indicate+=st[0];
    indicate+=st[1];
    indicate+=st[2];

    indicate+=st2[0];
    indicate+=st2[1];
    indicate+=st2[2];

    indicate+=st3[0];
    indicate+=st3[1];
    indicate+=st3[2];

}
int bfs()
{
    queue<string>qe;
    //vect.vec=vec,vect.vec2=vec2,vect.vec3=vec3;
    qe.push(vec);
    qe.push(vec2);
    qe.push(vec3);

    merge_(vec,vec2,vec3);
    dis[indicate]=1;
    int row,col,x,y,z,a,b,c;
    while(!qe.empty())
    {
        vec=qe.front();
        qe.pop();
        vec2=qe.front();
        qe.pop();
        vec3=qe.front();
        qe.pop();
        merge_(vec,vec2,vec3);
        indicate2=indicate;
        for(int i=0; i<3; i++)
        {
            if(vec[i]=='0')
            {
                row=0;
                col=i;
                break;
            }
        }
        for(int i=0; i<3; i++)
        {
            if(vec2[i]=='0')
            {
                row=1;
                col=i;
                break;
            }
        }
        for(int i=0; i<3; i++)
        {
            if(vec3[i]=='0')
            {
                row=2;
                col=i;
                break;
            }
        }
        for(int i=0; i<4; i++)
        {
            int row1=row+dx[i];
            int col1=col+dy[i];
            if(row1>=0&&row1<=2&&col1>=0&&col1<=2)
            {
                vec4=vec;
                vec5=vec2;
                vec6=vec3;
                if(row==0)
                {
                    if(i==0)
                    {
                        // vec4.clear();
                        if(col==2)
                        {
                            swap(vec4[1],vec4[2]);
                        }
                        else if(col==1)
                        {
                            swap(vec4[0],vec4[1]);
                        }
                    }
                    else if(i==1)
                    {
                        // vec4.clear();
                        if(col==0)
                        {
                            swap(vec4[0],vec4[1]);
                        }
                        else if(col==1)
                        {
                            swap(vec4[1],vec4[2]);
                        }
                    }
                    else if(i==2)
                    {
                        if(col==0)
                        {
                            swap(vec4[0],vec5[0]);
                        }
                        else if(col==1)
                        {
                            swap(vec4[1],vec5[1]);
                        }
                        else if(col==2)
                        {
                            swap(vec4[2],vec5[2]);
                        }
                    }
                }
                else if(row==1)
                {
                    if(i==0)
                    {
                        if(col==2)
                        {
                            swap(vec5[1],vec5[2]);

                        }
                        else if(col==1)
                        {
                            swap(vec5[0],vec5[1]);
                        }
                    }
                    else if(i==1)
                    {
                        if(col==0)
                        {
                            swap(vec5[0],vec5[1]);
                        }
                        else if(col==1)
                        {
                            swap(vec5[1],vec5[2]);
                        }
                    }
                    else if(i==2)
                    {
                        if(col==0)
                        {
                            swap(vec5[0],vec6[0]);
                        }
                        else if(col==1)
                        {
                            swap(vec5[1],vec6[1]);

                        }
                        else if(col==2)
                        {
                            swap(vec5[2],vec6[2]);

                        }
                    }
                    else if(i==3)
                    {
                        if(col==0)
                        {
                            swap(vec4[0],vec5[0]);
                        }
                        else if(col==1)
                        {
                            swap(vec4[1],vec5[1]);
                        }
                        else if(col==2)
                        {
                            swap(vec4[2],vec5[2]);
                        }
                    }
                }
                else if(row==2)
                {
                    if(i==0)
                    {
                        if(col==2)
                        {
                            swap(vec6[1],vec6[2]);

                        }
                        else if(col==1)
                        {
                            swap(vec6[0],vec6[1]);
                        }
                    }
                    else if(i==1)
                    {
                        if(col==0)
                        {
                            swap(vec6[0],vec6[1]);
                        }
                        else if(col==1)
                        {
                            swap(vec6[1],vec6[2]);
                        }
                    }
                    else if(i==3)
                    {
                        if(col==0)
                        {
                            swap(vec5[0],vec6[0]);
                        }
                        else if(col==1)
                        {
                            swap(vec5[1],vec6[1]);
                        }
                        else if(col==2)
                        {
                            swap(vec5[2],vec6[2]);
                        }
                    }
                }
                indicate.clear();
                merge_(vec4,vec5,vec6);
                if(dis[indicate]==0)
                {
                    // answer++;
                    // cout<<"i=="<<i<<endl;
                    // prinn(vec4,vec5,vec6);
                    qe.push(vec4),qe.push(vec5),qe.push(vec6);
                    // vis[indicate]=1;
                    dis[indicate]=dis[indicate2]+1;
                }
            }
        }
    }
}

void set_value()
{
    vec="123";
    vec2="456";
    vec3="780";
}
int main()
{
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int  i,j,n,m,a,c,b,d,ck,t,r,x,y,ans,rem,cnt,lo,hi,sum,row,col,cs=1;
    string result,tst;
    set_value();
    bfs();
    tst="123456780";
    // cout<<answer;
    si(t);
    while(t--)
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                si(x);
                result+=x+48;
            }
        }
        if(dis[result]==0&&result!=tst)
            printf("Case %d: impossible\n",cs++);
        else
            printf("Case %d: %d\n",cs++,dis[result]-1);
        result.clear();
    }

}
/*
goal:
1 2 3
4 5 6
7 8 0

input:
1 3 2
4 6 5
7 8 0

output: minimum moves to solve: 18

input:
1 2 3
4 5 6
7 0 8
output: minimum moves to solve: 1

input:
1 2 3
4 5 6
8 7 0
output: Impossible to solve\n

*/
