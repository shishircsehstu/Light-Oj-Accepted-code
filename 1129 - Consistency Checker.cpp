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
 
#define sc scanf
#define pf printf
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
 
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
// scanf("%d",&n);
#define mxx 27
struct node
{
    int next[mxx],val;
} tree[100000];
int last;
int Insert(char *str)
{
    int curr=0;
    for(int i=0; str[i]; i++)
    {
        int k=str[i]-'0';
        if(tree[curr].next[k]==-1)
        {
            tree[curr].next[k]=++last;
            mem(tree[last].next,-1);
            tree[last].val=0;
        }
        curr=tree[curr].next[k];
        if(tree[curr].val==1)
            return true;
    }
    tree[curr].val++;
    for(int i=0; i<10; i++)
    {
        if(tree[curr].next[i]!=-1)
            return true;
    }
    return false;
}
void initial()
{
    last=0;
    mem(tree[0].next,-1);
    tree[0].val=0;
}
int main()
{
    int n,m,t,r,cs=1;
    char str[11];
    sc("%d",&t);
    while(t--)
    {
        initial();
        int num_word;
        cin>>num_word;
        m=0;
        for(int i=1; i<=num_word; i++)
        {
            if(m==0)
            {
                scanf("%s",str);
                r=Insert(str);
                if(r==1)
                    m=1;
            }
            else
                sc("%s",str);
        }
        pf("Case %d: ",cs++);
        if(m==1)
            pf("NO\n");
        else
            pf("YES\n");
    }
    return 0;
}
 
