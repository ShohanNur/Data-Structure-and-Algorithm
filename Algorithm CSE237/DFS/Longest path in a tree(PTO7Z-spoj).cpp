//https://www.spoj.com/problems/PT07Z/
#include<bits/stdc++.h>
using namespace std;
#define sz       200000
#define ll       long long
#define pb       push_back
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define mod      1000000007
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
vector<int>graph[100003];
int vis[100003];
int dis[100003];
int mx, mxnode;
 
void dfs(int node, int distance)
{
    vis[node] = 1;
    if(distance>mx) mx = distance, mxnode = node;
    for(int i=0;i<graph[node].size();i++)
    {
        int nxt = graph[node][i];
        if(vis[nxt]==0)
        {
            dfs(nxt,distance+1);
        }
    }
 
}
 
 
 
 
int main()
{
    int n;
    cin>>n;
    int e = n-1;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    mx = -1;
    dfs(1,0);
    for(int i=0;i<n;i++){
        vis[i] = 0;
    }
    mx = -1;
    dfs(mxnode,0);
  cout<<mx<<endl;
 
}