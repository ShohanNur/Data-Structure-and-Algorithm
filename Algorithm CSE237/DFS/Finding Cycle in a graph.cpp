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
        cout<<child<<"'s father "<<node<<" and grandfather "<<parent<<endl;
         // node = parent 
         // parent = grandparent
        if(vis[child]==0)
        {
            if(dfs(child,node)==true){ //child == father?
                return true;
            }
        }
        else
            if(child!=parent) // child == grandfather?
              return true;
    }
    return false;
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
int sr;
cin>>sr;
if(dfs(sr,-1)) cout<<"Cycle Detected!"<<endl;
else cout<<"No cycle!"<<endl;


}
/*
5 4
1 2
2 3
2 4
2 5
2
*/
