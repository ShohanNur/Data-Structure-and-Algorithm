//cycle detection by DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[100003];
int vis[100003];
int color[100003];
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
            if(res == false) return false;
        }
        else
            if(color[node]==color[child])
              return false;
    }
    return true;
}

int main()
{

int n,e;
cin>>n;
cin>>e;

for(int i=1;i<=n;i++)
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
bool ok = true;
for(ll i=1;i<=n;i++){
    if(!vis[i]){
        if(dfs(i,0)==false){
            ok = false;
        }
    }
}
if(ok==false)
    cout<<"Tree is not Bipartite"<<endl;
else
     cout<<"Tree is Bipartite"<<endl;


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
