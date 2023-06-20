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

vector<int> node[200103];
// vector<int>current[200003];
int vis[200103];
ll dis[200103];
vector<int>ans;
void dfs(int x)
{
    
    vis[x]=1;
    bool f=0;
    for(int i=0;i<node[x].size();i++)
    {
        int tmp=node[x][i];

        if(!vis[tmp])
        {    
            f=1;
            dfs(tmp);
            dis[x]+=dis[tmp];
        }
    }
    if(f==0){
        dis[x] = 1;
    }
}


void init(int n){
     for(int i=1;i<=n+100;i++){
        node[i].clear();
        vis[i]=0;
        dis[i]=0;
     }
     ans.clear();
}
void solve(){ 
  ll n,e;
  cin>>n;
  e = n - 1;

  init(n);
  while(e--){
    ll x,y;
    cin>>x>>y;
    node[x].pb(y);
    node[y].pb(x);
  }

  dfs(1);
   
  for(int i=1;i<=n;i++){
   cout<<dis[i]<<" ";
  }
}
int main(){
   fastio
   int t = 1;
   //cin>>t;
   while (t--) {
      solve();
   }
}
/*

*/