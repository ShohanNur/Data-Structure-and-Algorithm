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
int vis[200003];
int dis[200003];
int in[200003];
int low[200003];
int timer;
void dfs(int x,int p)
{
  vis[x] = 1;
  in[x]=timer;
  low[x]=timer;
  timer++;
  for(ll i=0;i<node[x].size();i++){
     int child = node[x][i];
     if(!vis[child]){
        // this is forward edge
         dfs(child,x);
         if(low[child]>in[x]){
            cout<<x<<" - "<<child<<" is a bridge\n";
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
  dfs(1,-1);
  
}
int main(){
 // test{
    solve();
  //}
}
/*
13 16
1 2
1 7
1 6
1 5
5 6
2 4
2 3
3 4
7 11 
7 10
7 9
7 8
8 9
11 10
10 12
11 13
*/