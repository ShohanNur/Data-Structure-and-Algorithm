//DFS traversal visualization
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[100003];
int vis[100003];
int dis[100003];
vector<int>v,vv,vvv;
void dfs(int source)
{
    vis[source]=1;
    vv.push_back(source);
    for(int i=0;i<graph[source].size();i++)
    {
        int next=graph[source][i];
        cout<<next<<" "<<source<<"xxx"<<endl;
        if(vis[next]==0)
        {
            dfs(next);
        }
    }
     v.push_back(source);
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
dfs(sr);

// for(int i=1;i<=n;i++){
//     cout<<vis[i]<<" ";
// }
// cout<<endl;

// for(auto i:v){
//     cout<<i<<" ";
// }
// cout<<endl;

// for(auto i:vv){
//     cout<<i<<" ";
// }
// cout<<endl;
}
/*
7 6
1 5
1 3
3 5
1 2
2 4
6 7
1
*/
