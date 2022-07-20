
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


ll graph[100][100];
ll vis[200200];
ll dis[200200];
ll par[200200];
ll n,e;


void warshall(ll n){
  for(ll k=1;k<=n;k++){
    for(ll i=1;i<=n;i++){
      for(ll j=1;j<=n;j++){
         if(graph[i][k]+graph[k][j]<graph[i][j]){
          graph[i][j] = graph[i][k] + graph[k][j];
         }
      }
    }
  }
}
void init(ll n){
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      if(graph[i][j]==0){
      graph[i][j] = inf;
     }
    }
  }
}
int main(){
    cin>>n>>e;
    for(ll i=1;i<=e;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        graph[x][y] = w;
        graph[y][x] = w; 
      
    }
    init(n);
   cout<<"Before warshall called\n";
   for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      cout<<graph[i][j]<<" ";
    }
    cout<<endl;
   }
   cout<<endl;
   warshall(n);
   cout<<"After warshall called\n";
   

     for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      cout<<graph[i][j]<<" ";
    }
    cout<<endl;
   }
   cout<<endl; 

   int x;  cin>>x;
   while(x--){
     int a,b;
     cin>>a>>b;
     cout<<graph[a][b]<<endl;
   }
}
/*
4 4
1 2 10
2 3 1
2 4 5
1 4 3
3
2 3
1 2
1 4
*/