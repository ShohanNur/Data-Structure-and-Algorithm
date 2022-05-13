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
ll n,m,e,x,y;
vector<ll>graph[200005];
ll color[200005];
ll col[200005];
ll vis[200005];
ll dis[200005];
ll indeg[200005];
ll red,ans=0;

void dfs(ll x){
    int cnt;
    vis[x]=1;
    if(color[x]==1){
        red++;
    }
    else{
        red=0;
    }
    cnt = red;
    if(red>m){ return; }

    if(graph[x].size()==1 && x!=1){
        ans++;
    }
    for(ll i=0;i<graph[x].size();i++){
        red = cnt;  //------------
        ll child = graph[x][i];
        if(!vis[child]){
           dfs(child);
           
        } 
    }
    red = cnt;//------------
    if(color[x]==1){
       red--;
    }
}
int main()
{
 cin>>n>>m;
   for(ll i=1;i<=n;i++){
      cin>>x;
      color[i]=x;
   }
   e = n-1;

   for(ll i=1;i<=e;i++){
     cin>>x>>y;
     graph[x].pb(y);
     graph[y].pb(x);
   }
   dfs(1);
   cout<<ans<<endl;
}
/**

*/
