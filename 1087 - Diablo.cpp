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
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/
map<ll,bool>visi;
vector<int>vec;
int main ()
{
    int i,j,n,m,x,t,cs=1;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            vec.pb(x);
        }
        printf("Case %d:\n",cs++);
        for(i=0; i<m; i++)
        {
            scanf("%*c%c%d",&ch,&x);
            if(ch=='c')
            {
                if(x<=vec.size())
                {
                    printf("%d\n",vec[x-1]);
                    vec.erase(vec.begin()+x-1);
                }
                else
                    printf("none\n");
            }
            else
                vec.pb(x);
        }
        vec.clear();
    }
}
/*
1
5 5
7 9 30 5 2
c 3
c 9
a 900
c 4
c 4
*/
 
