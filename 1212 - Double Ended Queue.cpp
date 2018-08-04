#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<utility>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define ff first
#define ss second
#define sc scanf
#define pf printf
#define pi acos(-1.0)
#define siz 1000001
using namespace std;
int ar[1000],ar1[10000];
deque<int>dq;
int main()
{
    int i,j,n,m,num,k,r,r1,r2,t,cs=1;
    string a;
    sc("%d",&t);
    while(t--)
    {
        k=1;
        r=r1=r2=0;
        sc("%d%d",&n,&m);
        pf("Case %d:\n",cs++);
        for(i=1; i<=m; i++)
        {
            cin>>a;
            if(a=="pushLeft"||a=="pushRight")
            {
                cin>>num;
                if(dq.size()<=n-1)
                {
                    if(a=="pushLeft")
                    {
                        cout<<"Pushed in left: "<<num<<endl;
                        dq.push_back(num);
                    }
                    else
                    {
                        cout<<"Pushed in right: "<<num<<endl;
                        dq.push_front(num);
                    }
                    k++;
                }
                else
                    cout<<"The queue is full\n";
            }
            else
            {
                if(dq.size()>0)
                {
                    if(a=="popLeft")
                    {
                        cout<<"Popped from left: "<<dq.back()<<endl;
                        dq.pop_back();
                    }
                    else
                    {
                        cout<<"Popped from right: "<<dq.front()<<endl;
                        dq.pop_front();
                    }
                }
                else
                    cout<<"The queue is empty\n";
            }
        }
        dq.clear();
    }
    return 0;
}
 
