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
using namespace std::chrono;

    
int n,e;

vector<pair<ll,ll>>graph[200200];
ll vis[200200];
ll dis[200200];
ll par[200200];
bool ok=0;
void ballman(ll x){
     
     dis[x]=0;

     for(int k=0;k<n-1;k++){
      for(int i=1;i<=n;i++){
         for(int j=0;j<graph[i].size();j++){
             int x = graph[i][j].s;
             int w = graph[i][j].f;
             if(dis[x]>dis[i]+w){
               dis[x] = dis[i]+w;
               par[x] = i; 
             }

         }
      }
   }
    for(int i=1;i<=n;i++){
      for(int j=0;j<graph[i].size();j++){
         int x = graph[i][j].s;
         int cost = graph[i][j].f;
         if(dis[x]>dis[i]+cost){
            ok = 1; break;
         }
      }
    }

}
void init(ll n){
  for(ll i=1;i<=n;i++){
    dis[i]=inf; par[i]=-1; 
  }
}

int main(){
     
    cin>>n>>e;
    
    init(n);

    for(int i=0;i<e;i++){
      int x,y,w;
      cin>>x>>y>>w;
      graph[x].pb({w,y});
      graph[y].pb({w,x});
    }
     
    ballman(1);

    if(ok){
      cout<<"Negative Cycle detected\n";
    } 
    else{
       for(ll i=1;i<=n;i++){
         cout<<dis[i]<<" ";
       }
       cout<<endl;
    }

}