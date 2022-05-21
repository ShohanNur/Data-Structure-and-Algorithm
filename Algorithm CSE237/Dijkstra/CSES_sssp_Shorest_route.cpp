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
#define inf      100000000000000000 
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       200003
typedef long long ll;
using namespace std;
vector<ll>weight[sz];
vector<pair<ll,ll>>graph[sz];
ll vis[sz];
ll dis[sz];
ll par[sz];
ll n,m,x,y,w;



void dijkstra(ll x, ll d){

   vis[x]=1;
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;

   q.push({x,0});
   dis[x]=0;

   while(!q.empty()){
      ll par = q.top().first;
      ll parcost = q.top().second;
      
      q.pop(); 
   
      if(parcost<=dis[par]){
      for(ll i=0;i<graph[par].size();i++){
          ll child = graph[par][i].f;
        
            vis[child]=1;
            if(parcost+graph[par][i].s<dis[child]){
               dis[child] = parcost+graph[par][i].s;
               q.push({child,dis[child]});
             }
         }
      }
   }
}
 

void init(ll n){
   for(ll i=1;i<=n;i++){
        dis[i]=inf,par[i]=-1,vis[i]=0;
     }
}

int main()
{
   cin>>n>>m;
   init(n);
   for(ll i=1;i<=m;i++){
      cin>>x>>y>>w;
      graph[x].pb({y,w});
      //graph[y].pb({x,w});
   }
   dijkstra(1,0);
   for(ll i=1;i<=n;i++){
      cout<<dis[i]<<" ";
   }

} 

/**
10 20
8 5 1
9 10 2
7 9 8
9 8 8
10 9 9
7 8 10
8 9 2
7 10 10
4 5 8
5 6 1
4 2 1
5 3 6
10 7 3
3 5 2
5 4 7
1 2 9
2 3 2
6 7 5
3 4 10
3 2 10
*/