#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <chrono>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>


#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1e18
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;

using namespace std;
using namespace std::chrono;
vector<vector<int>>ans;
vector<int> node[200003];
vector<int>current;
int vis1[200003];
int vis2[200003];
int dis[200003];
int in[200003];
int low[200003];
int timer;
bool ok=0; 
bool dfs1(int x,int p)
{
  
  vis1[x] = 1;
  in[x]=timer;
  low[x]=timer;
  timer++;
  for(ll i=0;i<node[x].size();i++){
     int child = node[x][i];
     if(!vis1[child]){
        // this is forward edge
         dfs1(child,x);
         if(low[child]>in[x]){
            ok=1;
            break;
           // cout<<x<<" - "<<child<<" is a bridge\n";
         }
         else{
             low[x] = min(low[x],low[child]);
         }
     }
     else{
         // this is back edge 
        if(child!=p){
           low[x]=min(low[x],in[child]);
        }
        else{
         continue;
        }
     }
  }
  if(ok){
   return true;
  }
  else{
   return false;
  }

}

map<pair<int, int>, int> vis;

void dfs2(int x,int p)
{
   vis2[x]=1;
   for(ll i=0;i<node[x].size();i++){
      int child = node[x][i];
      if(!vis2[child]){
      cout<<x<<" "<<child<<endl;
   
      dfs2(child,x);
     }
     else{
        if(child!=p && vis[{child,x}]==0){
         vis[{x,child}]=1;
        cout<<x<<" "<<child<<endl;
        }
     }
   }
}
   // memset(ans,0,sizeof(ans));
void solve(){ 
  int n,e;
  cin>>n>>e;
  while(e--){
   int x,y;
   cin>>x>>y;
   node[x].pb(y);
   node[y].pb(x);
  }
  if(dfs1(1,-1)==true){
     cout<<0<<endl;
  }
  else{
     dfs2(1,-1);
  }
  
}
int main(){
 // test{
    solve();
  //}
}
/*
6 8
1 2
2 3
1 3
4 5
4 6
5 6
2 4
3 5

*/