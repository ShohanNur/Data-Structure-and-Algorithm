//DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[100003];
int vis[100003];
int dis[100003];
void dfs(int x,int d)
{
    vis[x]=1;
    dis[x]=d;
    for(int i=0;i<graph[x].size();i++)
    {
        int next=graph[x][i];
        if(!vis[next])
        {
            dfs(next,dis[x]+1);
        }
    }
}
int main()
{
int n,e;
cin>>n;
e=n-1;
while(e--)
{
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
}
    dfs(1,0);
    // for(ll i=1;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }
    // cout<<endl;

    // int next=0;
    // int mx=INT_MIN;
    // for(int i=1;i<=n;i++)
    // {
    //     if(dis[i]>=mx)
    //     {
    //         next=i;
    //         mx=dis[i];
    //     }
    // }
    vector<pair<int,int>>v; 
    for(ll i=1;i<=n;i++){
        v.push_back({dis[i],i});
    }
    sort(v.begin(),v.end());

    int next = v[v.size()-1].second; // find the maximum distant node from root

    cout<<"Maximum distant node from root after dfs1 :"<<next<<endl;
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    dfs(next,0);
    int mx=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,dis[i]);
    }
    cout<<"Diameter of the tree :"<<mx<<endl;
}
/*
6 
1 2 
1 3
3 4
3 5
2 6
*/