#include<bits/stdc++.h>
int dx[]= {-1,1,0,0};/*4 side move*/
int dy[]= {0,0,-1,1};/*4 side move*/
using namespace std;
 
int main()
{
    int caseno, t;
    cin >> t;
 
    char c[502][502];
    int dist[502][502];
 
    int M, N, Q;
    int i, row, col;
 
    vector < pair <int,int> > st;
    int u,v,x,y;
 
    int j,k;
    queue < pair <int,int> > q;
    vector < pair <int,int> > adj;
    int count;
    for( caseno=1; caseno<=t; caseno++)
    {
        cin >> M >> N >> Q;
        memset(c,'#',sizeof( c));
        memset( dist, -1, sizeof( dist));
 
        for( row=1; row<=M; row++)
        {
            for( col=1; col<=N; col++)
            {
                scanf(" %c",&c[row][col]);
            }
        }
        printf("Case %d:\n",caseno);
        for( k=1; k<=Q; k++)
        {
            scanf("%d%d",&u,&v);
            if( dist[u][v]>=0)
            {
                printf("%d\n",dist[u][v]);
                continue;
            }
            q.push(make_pair(u,v));
            dist[u][v] = 1000;
            count = 0;
            while( !q.empty())
            {
                row = q.front().first;
                col = q.front().second;
                q.pop();
                /*
                adj.push_back( make_pair( row-1, col));
                adj.push_back( make_pair( row+1, col));
                adj.push_back( make_pair( row, col-1));
                adj.push_back( make_pair( row, col+1));
                */
                for(int k1=0; k1<4; k1++)
                {
                    int x =row+dx[k1],y=col+dy[k1];
                    if( c[x][y]!='#' && dist[x][y]<0)
                    {
                        if(c[x][y] == 'C') count++;
                        q.push( make_pair(x,y));
                        dist[x][y] = 1000;
                        //   cout<<"YES\n";
                    }
                }
            }
            for( row=1; row<=M; row++)
            {
                for( col=1; col<=N; col++)
                {
                    if( dist[row][col] == 1000) dist[row][col] = count;
                }
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
