#include<bits/stdc++.h>
 
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
 
#define take(args...) asdf,args
#define dump(x) cerr<<#x<<" = "<<x<<endl
#define debug(args...) cerr,args; cerr<<endl;
using namespace std;
#define MAXX 1000007
int pi[MAXX];
 
void computePrefixFunction(string P)
{
    int m = SZ(P);
 
    pi[0] = -1;
 
    int k = -1;
 
    for(int i=1; i<m; i++)
    {
        while(k>-1 && P[k+1] != P[i])
            k = pi[k];
        if(P[k+1] == P[i])
            k++;
        pi[i] = k;
    }
}
 
 
int KMP(string T, string P)
{
    int ret = -1;
    int n = SZ(T);
    int m = SZ(P);
    computePrefixFunction(P);
    int q = -1;
 
    for(int i=0; i<n; i++)
    {
        while(q >-1 && P[q+1] != T[i])
            q = pi[q];
        if(P[q+1] == T[i])
            q++;
        if(i == (n-1))
            ret = q+1;
 
        if(q == (m-1))
        {
            q = pi[q];
        }
 
    }
 
    return ret;
}
 
string str;
int solve()
{
    string rev = str;
    reverse(all(rev));
    int matched = KMP(str, rev);
    return 2*SZ(str) - matched;
}
int main()
{
    int kases, kaseno = 0;
    sf("%d", &kases);
    while(kases--)
    {
        cin>>str;
 
        pf("Case %d: %d\n", ++kaseno, solve());
    }
 
    return 0;
}
 
