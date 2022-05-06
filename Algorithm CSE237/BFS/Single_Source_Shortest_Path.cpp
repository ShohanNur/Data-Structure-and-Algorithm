#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> graph[100003];
int vis[100003];
int dis[100003];

void bfs(int node, int d){
    vis[node] = 1;
    dis[node] = d;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            int child = graph[x][i];
            if(!vis[child]){
                vis[child]=1; 
                q.push(child);
                dis[child] = dis[x]+1;
            }
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

bfs(1,0);

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