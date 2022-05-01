//DFS
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> node[100003];
vector<int>v;
int vis[100003];
int dis[100003];
int b[100003];

int sr,d,n,e,x,y;

void bfs(int x)
{

   queue<int>q;
   q.push(x);
   vis[x] = 1;
   dis[x] = 0;


   while(!q.empty()){

       int parent = q.front();
       q.pop();
       for(ll i=0;i<node[parent].size();i++){
           int child = node[parent][i];
            if(!vis[child]){
                dis[child]=dis[parent]+1;
                q.push(child);
                vis[child] = 1;
                b[dis[child]]++;
            }
       }
   }
}
int main()
{

cin>>n>>e;
while(e--)
{
    
    cin>>x>>y;
    node[x].push_back(y);
    node[y].push_back(x);
}
cin>>x;

while(x--){
  cin>>sr>>d;
  memset(vis,0,sizeof(vis));
  memset(b,0,sizeof(b));
  memset(dis,0,sizeof(dis));

  bfs(sr);
  cout<<b[d]<<endl;
}

}
/*
9 10
1 2
2 3
1 7
2 4
3 4
4 7
7 8
9 7
7 6
5 6
3
4 2
5 3
2 1


*/
