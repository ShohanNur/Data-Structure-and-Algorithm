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
vector<int> node[200003];
vector<int>current[200003];
int vis[200003];
int dis[200003];

void dfs(int x,int p){
   
   
   vis[x] = 1;
   bool flag=0;
   for(auto child:node[x]){
      if(!vis[child]){
         flag=1;
         dfs(child,x);
      }
   }
   if(!flag){
      cout<<x<<" ";
   }
}

void solve(){ 
  ll n,e;
  cin>>n>>e;
  while(e--){
    ll x,y;
    cin>>x>>y;
    node[x].pb(y);
    node[y].pb(x);
  }
  dfs(1,-1);

}
int main(){
  //test{
    solve();
  //}
}
/*
8 7
1 2
1 3
2 4
3 5
3 6
3 7
6 8
*/