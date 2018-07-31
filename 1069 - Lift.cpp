#include<iostream>
using namespace std;
int main()
{
    int t,i,y,l,r;
    cin>>t;
    r=1;
    while(t--)
    {
        cin>>y>>l;
        if(y==0&&l==0)
            cout<<"Case "<<r++<<':'<<' '<<0<<'\n';
        else
        {
            if(l>y)
                cout<<"Case "<<r++<<':'<<' '<<l*4+19<<'\n';
            else
                cout<<"Case "<<r++<<':'<<' '<<y*4+(y-l)*4+19<<'\n';
        }
    }
    return 0;
}
