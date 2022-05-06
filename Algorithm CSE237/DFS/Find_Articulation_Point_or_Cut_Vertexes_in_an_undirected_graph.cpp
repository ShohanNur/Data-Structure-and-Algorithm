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
vector<int>cut_vertexs;
vector<int> node[200003];
vector<int>current;
int vis[200003];

int dis[200003];
int in[200003];
int low[200003];
int timer;
bool ok=0; 
void dfs(int x,int p)
{
  
  vis[x] = 1;
  in[x]=timer;
  low[x]=timer;
  timer++;
  int c=0;
  for(ll i=0;i<node[x].size();i++){
     int child = node[x][i];
     if(!vis[child]){
        // this is forward edge
         dfs(child,x);
         

         if(low[child]>=in[x] && p!=-1){
           // cout<<x<<" - "<<child<<" is a bridge\n";
            cut_vertexs.pb(x);
         }
         else{
            low[x] = min(low[x],low[child]);
         }
         c++;
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
  if(p==-1 && c>1)
  {
   cut_vertexs.pb(x);
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

 for(auto i:cut_vertexs){
   cout<<i<<" ";
 }
 cout<<endl;
}
int main(){
 // test{
    solve();
  //}
}
/*
5 6
1 2
2 3
3 5
2 5
4 2
1 4
*/