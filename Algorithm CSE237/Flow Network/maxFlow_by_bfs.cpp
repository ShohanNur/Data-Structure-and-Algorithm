#include<bits/stdc++.h>
using namespace std;
const int MXN = 1010;
const int inf = 1e9 + 7;

int capacity[MXN][MXN];
int N, E;

int vis[MXN], parent[MXN];

vector<int>path;


void bfs(int src){
    vis[src] = 1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<N;i++){
            if(capacity[x][i] && !vis[i]){
                parent[i]=x;
                vis[i]=1;
                q.push(i);
            }
        }
    }
}

void findPath(int src, int sink)
{
        memset(vis, 0 , sizeof(vis));
         memset(parent, -1, sizeof(parent));

         bfs(src);
         path.clear();

         if(!vis[sink])
            return;

         int cur_node=sink;

         while(cur_node!=-1)
         {
             path.push_back(cur_node);
             cur_node=parent[cur_node];
         }

         return;
}

int findFlow(int srce, int sink)
{
     int flow=0;

     while(1){
          path.clear();
          findPath(srce,sink);

          if(path.size()==0){
            break;
          }

          reverse(path.begin(), path.end());
             
              int mnFlow=INT_MAX;

              for(int i=0 ; i<path.size()-1 ; i++)
              {
                     int u=path[i];
                     int v=path[i+1];
                     mnFlow=min(mnFlow, capacity[u][v]);
              }

              flow+=mnFlow;
            
              for(int i=0 ; i<path.size()-1 ; i++)
              {
                   int u=path[i];
                   int v=path[i+1];
                   capacity[u][v]-=mnFlow;
                   capacity[v][u]+=mnFlow;
              }
         }
         return flow;
     
}


int main()
{
    //freopen("00_input.txt", "r", stdin);
    while(scanf("%d%d", &N,&E) == 2){
        memset(capacity, 0, sizeof(capacity));
        int a, b, w;
        while(E--){
            scanf("%d%d%d", &a, &b, &w);
            capacity[a][b] += w;
        }
        int srce, sink;

        scanf("%d%d", &srce, &sink);

        int flow = findFlow(srce, sink);

        cout<<flow<<endl;
    }
    return 0;
}
/*
6 8
0 1 11
0 2 12
2 1 1
1 3 12
2 4 11
4 3 7
4 5 4
3 5 19
0 5

4 5
0 1 6
0 2 4
1 2 10
1 3 2
2 3 5
0 3

*/