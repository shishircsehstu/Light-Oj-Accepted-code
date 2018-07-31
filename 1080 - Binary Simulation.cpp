#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
 
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define endl '\n'
#define pii pair(int,int)
#define pi acos(-1.0)
#define Sin(a) sin((pi*a)/180);
#define siz 1000001
#define mem(ar) memset(ar,0,sizeof ar)
#define one(x) __builtin_popcount(x)
/*
Saddam Hossain Shishir
shishir.cse.hstu@gmail.com
*/
typedef long long ll;
int tree[siz];
using namespace std;
ll len;
char s1[siz],ch[10];
bool s2[siz];
int update(ll x,ll value)
{
    while(x<=len)
    {
        tree[x]+=value;
        x+=x&-x;
    }
}
int query(ll x)
{
    ll sum=0;
    while(x>0)
    {
        sum+=tree[x];
        x-=x&-x;
    }
    return sum;
}
int main()
{
 
    ll i,j,k,n,m,qu,x,y,t,cs=1;
    sc("%lld",&t);
    while(t--)
    {
        pf("Case %lld:\n",cs++);
        sc("%s",s1);
        mem(tree);
        len=strlen(s1);
        for(i=0; i<len; i++)
            s2[i]=s1[i]-'0';
        sc("%lld",&qu);
        for(i=1; i<=qu; i++)
        {
            sc("%s",ch);
            if(!strcmp(ch,"I"))
            {
                sc("%lld %lld",&x,&y);
                update(x,1);
                update(y+1,-1);
            }
            else
            {
                sc("%lld",&x);
                int x1=s2[x-1];
                int x2=(query(x))%2;
                int x3=x1^x2;
                pf("%d\n",x3);
            }
        }
    }
}
 
