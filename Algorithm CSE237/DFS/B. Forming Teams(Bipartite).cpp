// https://codeforces.com/contest/216/problem/B

//cycle detection by DFS

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> graph[100003];
ll vis[100003];
ll color[100003];
ll cnt;
void dfs(int node,int col)
{
    vis[node]=1;
    color[node] = col;
   // cout<<node<<"----"<<col<<endl;
    for(int i=0;i<graph[node].size();i++)
    {
        int child=graph[node][i];
        if(vis[child]==0)
        {
             dfs(child , col ^ 1);
            
        }
        else{
            if(color[node]==color[child])
            {
                cnt++;
            }
        }
    }
    //cout<<cnt<<"xxx"<<endl;
}

int main()
{

int n,e;
cin>>n;
cin>>e;

for(int i=1;i<=n;i++)
{
    graph[i].clear();
    vis[i]=0;
}
while(e--)
{
    int x,y;
    cin>>x>>y;
  //  x--,y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
}
bool ok = true;
for(ll i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i,0);
    }
}
ll rem = n-ceil(cnt/2.0);
if(rem%2){
     cnt+=2;
}
   if(n%2==0){


      ll x = ceil(cnt/2.0); 
      if(x==0){
        cout<<0<<endl;
      } 
      else{
      cout<<max(2LL,x)<<endl;
     }
   }
   else{
      cout<<max(1LL,cnt/2)<<endl;
   }
}

/*
6 6
1 2 
1 3
3 4
3 5
2 6
4 5
*/