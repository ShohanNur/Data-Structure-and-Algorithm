//cycle detection by DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[100003];
int vis[100003];
int dis[100003];
bool dfs(int node,int parent)
{
    vis[node]=1;
    for(int i=0;i<graph[node].size();i++)
    {
        int child=graph[node][i];
        if(vis[child]==0)
        {
            if(dfs(child,node)==true){
                return true;
            }
        }
        else
            if(child!=parent)
              return true;
    }
    return false;
}
void dfss(int source)
{
    vis[source]=1;
    for(int i=0;i<graph[source].size();i++)
    {
        int next=graph[source][i];
        if(vis[next]==0)
        {
            dfss(next);
        }
    }
}
int main()
{
int n,e;
cin>>n>>e;
while(e--)
{
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
}
int ok = 0,c=0;
if(dfs(1,-1))
{
    ok = 1;
}
for(int i=0;i<n;i++)
{
    if(vis[i]==0)
    {
        c++;
        dfss(i);
    }
}
if(ok || c>1)
{
    cout<<"NO"<<endl;
}
else
    cout<<"YES"<<endl;
}
/*
5 6
3
0 1
2 0
2 1
1 3
3 4
1 4*/
