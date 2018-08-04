#include<bits/stdc++.h>
 
using namespace std;
typedef long long i64;
vector< i64 > Lt, Rt;
i64 a[20];
void generate(i64 sum, int st, int en, vector< i64 > &v)
{
    int i;
    if(st == en)
    {
        v.push_back(sum);
        return;
    }
    for(i = 0; i < 3; i++) generate(sum + a[st] * i, st + 1, en, v);
}
 
int main()
{
    int test,m, n, i, mid, sz,sz2,lo,hi,ck,t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++) scanf("%lld", &a[i]);
        Lt.clear();
        Rt.clear();
        mid = n >> 1;
        generate(0, 0, mid, Lt);
        generate(0, mid, n, Rt);
        sz=Lt.size();
        sz2=Rt.size();
        sort(Lt.begin(),Lt.end());
        //sort(Rt.begin(),Rt.end());
        ///for(i=0;i<sz;i++) cout<<Lt[i]<<" "; cout<<endl;
///for(i=0;i<sz2;i++) cout<<Rt[i]<<" "; cout<<endl;
        /*
                lo=0;
                hi=sz2-1;
                ck=0;
                while(lo<=hi)
                {
                    if(Lt[lo]+Rt[hi]==m)
                    {
                        ck=1;
                        break;
                    }
                    else if(Lt[lo]+Rt[hi]>m) hi--;
                    else
                        lo++;
                }
                printf("Case %d: ",cs++);
                if(ck==1)
                    printf("Yes\n");
                else
                    printf("No\n");
                /*
                sort(Lt.begin(), Lt.end());
                sz = Rt.size();
                */
        for(i = 0; i < sz2; i++)
        {
            // cout<<"rt="<<Rt[i]<<endl;
            //  cout<<"i=="<<i<<endl;
            if(m >= Rt[i])
            {
                //cout<<*lower_bound(Lt.begin(), Lt.end(),  Rt[i])<<endl;
                // cout<<lower_bound(Lt.begin(), Lt.end(),  Rt[i])-Lt.begin()<<endl;
                if(*lower_bound(Lt.begin(), Lt.end(), m- Rt[i]) == m - Rt[i]) break;
            }
        }
        if(i == sz2) printf("Case %d: No\n", cs++);
        else printf("Case %d: Yes\n", cs++);
 
    }
    return 0;
}
 
