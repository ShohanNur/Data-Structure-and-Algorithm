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
#define inf      1000000000000
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       30003
typedef long long ll;
using namespace std;

vector<ll>graph[sz];
ll vis[sz]; 
vector<ll>weight[sz];
ll dis[sz];
ll n,x,y,w;
void dfs(ll x,ll d){
  vis[x]=1;
  dis[x]=d;
  for(ll i=0;i<graph[x].size();i++){
    ll child = graph[x][i];
    if(!vis[child]){
        dfs(child,weight[x][i]+d);
    }
  }
}
void init1(ll n){
    for(ll i=0;i<n;i++){
        vis[i]=0,dis[i]=0,graph[i].clear(),weight[i].clear();
    }
}
void init2(ll n){
    for(ll i=0;i<n;i++){
        vis[i]=0,dis[i]=0;
    }
} 

void solve(){
  cin>>n;
  init1(n);
  for(ll i=0;i<n-1;i++){
    cin>>x>>y>>w;
    graph[x].pb(y);
    graph[y].pb(x);
    weight[x].pb(w);
    weight[y].pb(w);
  }
  dfs(0,0);
  ll mx=-1; 
  ll mxin;
  for(ll i=0;i<n;i++){
    if(mx<dis[i]){
        mx = dis[i];
        mxin = i;
    }
  }
  // mxin is one end of the the diamater path 

  init2(n);
  dfs(mxin,0);  // calling dfs from one end of the diameter node 
  ll mx2=-1;
  ll mxin2;
    for(ll i=0;i<n;i++){
      
       if(mx2<dis[i]){
          mx2 = dis[i];
          mxin2 = i;
       } 
      
  }
  //mxin2 is another end of the diameter path 


  ll temp1[sz];
  for(ll i=0;i<n;i++){
     temp1[i]=dis[i];
  }
  //storing the distance of all nodes from mxin node

  init2(n);
  dfs(mxin2,0); // calling dfs from another end of the diameter node 
 ll temp2[sz];
 for(ll i=0;i<n;i++){
     temp2[i]=dis[i];
  }
 // storing all distance of all nodes from mxin2 node
   ll ans;
  for(ll i=0;i<n;i++){
     ans = max(temp1[i],temp2[i]);
     cout<<ans<<endl; 
  }

  
} 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k=0;
    test{
        cout<<"Case "<<++k<<":"<<"\n"; 
        solve();
    }
}