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
#define mx 1000007
int cnt;
int pi[mx];
void f(string P)
{
    int m = SZ(P);
    pi[0] = -1;
    int k = -1;
    for(int i=1; i<m; i++)
    {
        while(k > -1 && P[k+1] != P[i])
        {
            k = pi[k];
        }
        if(P[k+1] == P[i])
            k++;
        pi[i] = k;
    }
}
void KMP(string T, string P)
{
    cnt = 0;
    int n = SZ(T);
    int m = SZ(P);
    f(P);
    int q = -1;
    for(int i=0; i<n; i++)
    {
        while(q > -1 && P[q+1] != T[i])
        {
            q = pi[q];
        }
        if(P[q+1] == T[i])
            q++;
        if(q == m-1)
        {
            cnt++;
            q = pi[q];
        }
    }
}
int main()
{
    string A,B;
    int k,cs= 0;
    sf("%d", &k);
    while(k--)
    {
        cin>>A>>B;
        KMP(A,B);
        pf("Case %d: %d\n", ++cs,cnt);
        cnt=0;
    }
    return 0;
}
 
