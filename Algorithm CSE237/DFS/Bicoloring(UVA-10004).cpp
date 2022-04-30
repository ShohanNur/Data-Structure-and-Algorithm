//cycle detection by DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[203];
int vis[203];
int color[203];
bool dfs(int node,int col)
{
    vis[node]=1;
    color[node] = col;
    for(int i=0;i<graph[node].size();i++)
    {
        int child=graph[node][i];
        if(vis[child]==0)
        {
            bool res = dfs(child , col ^ 1);
            if(res == false) return 0;
        }
        else
            if(color[node]==color[child])
              return 0;
    }
    return 1;
}

int main()
{


int n,e;
while(cin>>n && n){
    cin>>e;
for(int i=0;i<n;i++)
{
    graph[i].clear();
    vis[i]=0;
}
while(e--)
{
    int x,y;
    cin>>x>>y;
  //  x--,y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
}


if(!dfs(0,0))
    cout<<"NOT BICOLORABLE."<<endl;
else
     cout<<"BICOLORABLE."<<endl;
}
}
/*
6 6
1 2 
1 3
3 4
3 5
2 6
4 5
*/
