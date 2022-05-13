#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
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
#define inf      1e9
#define endl     '\n'
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       100003
typedef long long ll;
using namespace std;
ll n,e,x,y;
vector<ll>graph[200005];
ll indeg[200005];
ll outdeg[200005];
ll vis[200005];
ll dis[200005];
ll ans,l;
bool ok=0,okk=0;
void dfs(ll x,ll p){
   vis[x] = 1;
   if(indeg[x]!=2){
      okk=1;
   }
   for(ll i=0;i<graph[x].size();i++){
      ll child =graph[x][i];
      if(!vis[child]){
         dfs(child,x);
      }
      else{
         
         if(child==p) continue;
         else{
           ok=1;
         }

      }  
   }
}
int main()
{
   cin>>n>>e;
   while(e--){
      cin>>x>>y;
      graph[x].pb(y);
      graph[y].pb(x);
  
      indeg[y]++;
      indeg[x]++;
   }
   
   for(ll i=1;i<=n;i++){
       if(!vis[i]){
          ok=0,okk=0;
          dfs(i,-1);
          if(ok && !okk){
           ans++;
          }
       }
   }
   cout<<ans<<endl;

}

/*
17 15
1 8
1 12
5 11
11 9
9 15
15 5
4 13
3 13
4 3
10 16
7 10
16 7
14 3
14 4
17 6
*/