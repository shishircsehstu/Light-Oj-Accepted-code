#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<limits>
#include<climits>
#include<cmath>
#include<functional>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<typeinfo>
using namespace std;
 
typedef long long ll ;
 
const ll N = 5001;
 
struct edge
{
    ll to,w;
    edge() {}
    edge(ll a, ll b)
    {
        to=a;
        w=b;
    }
};
 
struct el
{
    ll vertex,cost;
    el() {}
    el(ll a, ll b)
    {
        vertex=a;
        cost=b;
    }
    bool operator<(const el &a) const
    {
        return cost>a.cost;
    }
};
 
priority_queue <el> pq;
vector <edge> v[N];
vector <ll> dist[N];
ll n,m,q;
 
void Dijkstra(ll starting_node, ll ending_node)
{
    ll i,current_distance;
    el curr;
    for(i=0; i<= 5000; i++)
        dist[i].clear();
    pq.push(el(starting_node,0));
    while(!pq.empty())
    {
        curr=pq.top();
        pq.pop();
        if(dist[curr.vertex].size()==0)
        {
            dist[curr.vertex].push_back(curr.cost);
            // cout<<curr.vertex<<"  "<<curr.cost<<endl;
        }
        else if(dist[curr.vertex].back()!=curr.cost)
        {
            dist[curr.vertex].push_back(curr.cost);
            // cout<<curr.vertex<<" kotha na "<<curr.cost<<endl;
        }
        if(dist[curr.vertex].size()>2)
            continue;
        for(i=0; i<v[curr.vertex].size(); i++)
        {
            // cout<<"--> "<<v[curr.vertex][i].to;
 
            if(dist[v[curr.vertex][i].to].size()==2)
                continue;
            current_distance=v[curr.vertex][i].w+curr.cost;
            //  cout<<" cost "<<current_distance<<endl;
            pq.push(el(v[curr.vertex][i].to,current_distance));
        }
    }
    //if(dist[ending_node].size()<2)
    //  printf("?\n");
    //else
    printf("%lld\n", dist[ending_node][1]);
}
 
 
int  main()
{
    ll i,a,b,c,t,cs=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0; i<=5000; i++)
            v[i].clear();
        //  cout<<"tt";
        for(i=1; i<=m; i++)
        {
            scanf("%lld %lld %lld", &a, &b, &c);
            v[a].push_back(edge(b,c));
            v[b].push_back(edge(a,c));
        }
        printf("Case %lld: ",cs++);
        Dijkstra(1,n);
    }
}
/*
3 3
1 2 100
1 3 50
2 3 200
 
4 4
1 2 5
1 3 1
2 3 7
3 4 1
 
*/
 
 
