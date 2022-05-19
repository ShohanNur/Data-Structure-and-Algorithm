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
#define sz       200003
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

  init2(n);
  dfs(mxin,0);
  ll mx2=-1;
    for(ll i=0;i<n;i++){  
      mx2 = max(mx2,dis[i]);  
  }
  cout<<mx2<<endl; 
} 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k=0;
    test{
        cout<<"Case "<<++k<<": "; 
        solve();
    }
}
/*
2
4
0 1 20
1 2 30
2 3 50
5
0 2 20
2 1 10
0 3 29
0 4 50
*/