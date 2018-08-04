#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
 
using  namespace  std;
 
#define pf printf
#define sc scanf
#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
 
typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;
/*
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction\
 
 scanf("%d",&n);
 */
int sum1,sum2;
#define mxx 4
struct node
{
    int next[mxx],val;
} tree[2500000];
int last;
void cal(int i,int n)
{
    sum1=i*n;
    if(sum1>sum2)
        sum2=sum1;
}
void Insert(string str)
{
    int curr=0;
    for(int i=0; str[i]; i++)
    {
        int k=str[i]-'A';
        if(str[i]=='A')
            k=0;
        if(str[i]=='C')
            k=1;
        if(str[i]=='G')
            k=2;
        if(str[i]=='T')
            k=3;
        if(tree[curr].next[k]==-1)
        {
            tree[curr].next[k]=++last;
            mem(tree[last].next,-1);
            tree[last].val=0;
        }
        curr=tree[curr].next[k];
        tree[curr].val++;
        cal(i+1,tree[curr].val);
    }
}
void initial()
{
    last=0;
    mem(tree[0].next,-1);
    tree[0].val=0;
}
int main()
{
    int T,n,r1,r,i,len,j,cs=1;
    string s,s1,s2;
    scanf("%d",&T);
    while(T--)
    {
        initial();
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            cin>>s;
            Insert(s);
        }
        pf("Case %d: %d\n",cs++,sum2);
        sum2=0;
    }
    return 0;
}
 
 
 
