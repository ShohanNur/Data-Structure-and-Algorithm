//DFS
//how many childs can a node have including itself?
 

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> node[200003];
int vis[200003];
int dis[200003];

void dfs(ll x){
   // finding all subtree size of each nodes
   vis[x]=1; 
   dis[x]=1;
   for(ll i=0;i<graph[x].size();i++){
      ll child = graph[x][i];
      if(!vis[child]){
         dfs(child);
         dis[x]+=dis[child];
      }
   }
}
int main()
{
int n,e;

cin>>n;
e = n-1;
while(e--)
{
    int x,y;
    cin>>x>>y;
    node[x].push_back(y);
    node[y].push_back(x);
}

dfs(1);

for(int i=1;i<=n;i++)
{
    cout<<dis[i]<<" ";
}
}
/*
6 5
1 2 
1 3
3 4
3 5
2 6
*/