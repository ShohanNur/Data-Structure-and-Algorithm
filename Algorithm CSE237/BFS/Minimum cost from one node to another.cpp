//BFS
#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
#define sz       430
typedef long long ll;
using namespace std;
vector<int>node[100003];
int vis[100003];
int dis[100003];
int p,q,m,n,w;

int bfs(int s,int d)
{
    queue<pair<int,int>>q;
    vis[s]=true;
    q.push({s,0});

    while(!q.empty())
    {
        int current = q.front().first;
        int cost = q.front().second;
        q.pop();
       if(current == d)
         return cost;
        for(int i=0;i<node[current].size();i++)
        {


             int x =node[current][i];

             if(vis[x]==0)
             {
                 vis[x]=1;
                 q.push({x,cost+1});

             }


        }


    }

   return -1;

}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    cin>>n>>m;
    for(int i=1;i<=n;i++)
        node[i].clear();
    //,dis[i]=0,vis[i]=0;
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));

    while(m--)
    {
         cin>>p>>q;
         node[p].push_back(q);
         node[q].push_back(p);

    }

    cin>>p>>q;
    w = bfs(p,q);

   if(~w) cout<<"Minimum cost using BFS = " << w <<endl;
   else cout<<"There is no path between " <<p<< "to" <<q<<endl;
   // cout<<endl;




   //return 0;

}
/*
10 9
1 4
1 2
4 3
3 10
3 9
2 5
2 8
2 7
5 6
0 0 1 2 1 2 3 2 2 3
*/
