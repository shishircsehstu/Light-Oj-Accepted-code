#include<bits/stdc++.h>
using namespace std;
#define sz 100005
int tree[sz*4],arr[sz];
void build(int root,int lo,int hi)
{
 
    if(lo==hi)
    {
        tree[root]=arr[lo];
        return;
    }
    int mid = (lo+hi)/2;
    build(root*2,lo,mid);
    build(root*2+1,mid+1,hi);
    tree[root] = min(tree[root*2],tree[root*2+1]);
}
int query(int root,int lo,int hi,int i,int j)
{
 
    if(i>hi || j<lo) return 10000000;   ///if(a > b || a > j || b < i) return 99999999;
    if(i<=lo && hi<=j) return tree[root];/// if (b >= i && e <= j) return tree[node];
 
    int mid = (lo+hi)/2;
    return min(query(root*2,lo,mid,i,j),query(root*2+1,mid+1,hi,i,j));
}
int main()
{
    int t,ti=1,x,y,n,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)scanf("%d",&arr[i]);
        build(1,1,n);
        printf("Case %d:\n",ti++);
        for(int i=1; i<=q; i++)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",query(1,1,n,x,y));
        }
    }
}
 
