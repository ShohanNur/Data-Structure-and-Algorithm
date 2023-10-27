//https://codeforces.com/contest/1873/problem/H
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[200003];
int vis[200003];
int vis1[200003];
int vis2[200003];
int dis[200003];
int par[200003];
int cyc[200003];
int dis1[200003];
int dis2[200003];


void bfs1(int x){
      queue<int>q;

      q.push(x);

      while(!q.empty()){
          int u = q.front();
          q.pop();

          for(int i=0;i<graph[u].size();i++){
               int child = graph[u][i];
               if(!vis1[child]){
                   dis1[child] = dis1[u]+1;
                   q.push(child);
                   vis1[child]=1;
               }

          }
      }
}

void bfs2(int x){
      queue<int>q;

      q.push(x);

      while(!q.empty()){
          int u = q.front();
          q.pop();

          for(int i=0;i<graph[u].size();i++){
               int child = graph[u][i];
               if(!vis2[child]){
                   dis2[child] = dis2[u]+1;
                   q.push(child);
                   vis2[child]=1;
               }

          }
      }
}

// find nodes which are in a cycle 
void dfs(int node,int parent)
{
    vis[node]=1;
    for(int i=0;i<graph[node].size();i++)
    {
        int child=graph[node][i];
        
                
        if(vis[child]==1)
        {
            if(par[node]==child) continue;
            cyc[child] = 1;

            int cur = node;

            while(cur != child){
                 cyc[cur] = 1;
                 cur = par[cur];
            }
        }
        else{
            par[child] = node;
            dfs(child,node);
        }
    }
    vis[node] = 2;
}

void init(int n){
      for(int i=1;i<=n;i++){
           dis1[i] = dis2[i] = 0;
           par[i] = vis[i] = cyc[i] = vis1[i] = vis2[i] = 0;
           graph[i].clear();
      }
}
void solve()
{    
int n,a,b;
cin>>n>>a>>b;

init(n);
for(int i=0;i<n;i++)
{
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
}
  if(a==b){
      cout<<"NO\n"; return;
  }  
  // if(cyc[b]){
  //    cout<<"YES\n"; return;
  // }



  bfs1(a);
  bfs2(b);
  dis1[a] = 0;
  dis2[b] = 0;
  dfs(1,0);
  // cout<<dis1[1]<<" "<<dis2[1]<<endl;

  // for(int i=1;i<=n;i++){
  //     cout<<dis1[i]<<" "<<dis2[i]<<" "<<cyc[i]<<endl;
  // }
  // cout<<endl;
  for(int i=1;i<=n;i++){
       if(cyc[i]){
           if(dis1[i]>dis2[i]){
              cout<<"YES\n"; return;
           }
       }
  } 
  cout<<"NO\n";
  
}

int32_t main()
{
   int t = 1;


   cin>>t;
   while (t--) {
      solve();
   }
}
/*
5 4
1 2
2 3
2 4
2 5
2
*/