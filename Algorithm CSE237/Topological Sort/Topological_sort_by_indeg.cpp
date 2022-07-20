
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


vector<ll>graph[200200];
ll vis[200200];
ll dis[200200];
ll par[200200];
ll indeg[200200];
ll n,e;

void toposort(){
   vector<ll>res;
   for(ll i=1;i<=n;i++){
       if(!vis[i] && !indeg[i]){
            vis[i]=1;
            res.pb(i);
            for(ll j=0;j<graph[i].size();j++){
                int child = graph[i][j];
                indeg[child]--;
            }
       }
   }

   if(res.size()==n){
    for(auto i:res){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  else{
    cout<<"Toposort doesn't exist!\n";
  }

}

int main(){
   cin>>n>>e;
   for(ll i=1;i<=e;i++){
      ll x,y;
      cin>>x>>y;
      graph[x].pb(y);
      indeg[y]++;
   }

   toposort();   
}
