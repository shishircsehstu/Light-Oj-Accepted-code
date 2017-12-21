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
#define siz 2001
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
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//'A'=65,'Z'=90 'a'=97 'z'=122 '0'=48


//upper bound and lower bound

#define LB(a,value) (lower_bound(all(a),value)-a.begin())
#define UB(a,value) (upper_bound(all(a),value)-a.begin())
//S.insert(lower_bound(S.begin( ),S.end( ),x),x); //S is vector

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
int ar[100],ar2[100],ar3[100],ar4[100],vis[siz],vis2[siz];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  i,j,a,b,n,m,x,y,ck,t,r,ans,rem,cnt,lo,hi,sum,cs=1;
    si(t);
    while(t--)
    {
        si(n);

        for(i=0; i<n; i++) si(ar[i]);
        for(i=0; i<n; i++) si(ar2[i]);
        sort(ar,ar+n);
        sort(ar2,ar2+n);
        /*
        for(i=0;i<n;i++) cout<<ar[i]<<"  ";
        cout<<endl;
        for(i=0;i<n;i++) cout<<ar2[i]<<"  ";
            */

        ans=0;
        int indxi,indxj;
        for(i=0; i<n; i++)
        {
            ck=0;
            for(j=0; j<n; j++)
            {
                if(ar[i]>ar2[j])
                {
                    if(vis2[j]==0)
                    {
                        indxi=i;
                        indxj=j;
                        ck=1;

                    }
                }
                else
                {
                    if(ck==1)
                    {
                        ans+=2;
                        vis[indxi]=1;
                        vis2[indxj]=1;
                        ck=0;

                    }
                    break;
                }
            }
            if(ck==1)
            {
                ans+=2;
                ck=0;
            }
        }
        // cout<<ans<<"--"<<ck<<endl;
        if(ck==1)
            ans+=2;
//cout<<ans<<endl;
        int r2=0;
        for(i=0; i<n; i++)
            if(vis2[i]==0)
                ar4[r2++]=ar2[i];
        r=0;
        for(i=0; i<n; i++)
            if(vis[i]==0)
                ar3[r++]=ar[i];
        mem(vis);
        for(i=0; i<r; i++)
        {
            for(j=0; j<r2; j++)
            {
                if(ar3[i]==ar4[j]&&vis[j]==0)
                {
                    ans++;
                    vis[j]=1;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",cs++,ans);
        mem(vis),mem(vis2);
    }


}
/*
4
10 7 1 4
15 3 8 7
*/

