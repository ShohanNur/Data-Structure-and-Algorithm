https://www.spoj.com/problems/TRAFFICN/


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
#define inf      1e18 
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

vector<pair<ll,ll>>graph2[sz];
ll vis2[sz];
ll dis2[sz];
ll par2[sz];
ll n,m,x,y,w,k,a,b;
 
 
 
void dijkstra(ll x, ll d){
 
   vis[x]=1;
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
 
   q.push({x,0});
   dis[x]=0;
 
   while(!q.empty()){
      ll par = q.top().first;
      ll parcost = q.top().second;
      
      q.pop(); 
      // if(!vis[par]){
      //  vis[par]=1;  
      if(parcost<=dis[par]){
      for(ll i=0;i<graph[par].size();i++){
          ll child = graph[par][i].f;
           //if(!vis[child]){
            vis[child]=1;
            if(parcost+graph[par][i].s<dis[child]){
               dis[child] = parcost+graph[par][i].s;
               q.push({child,dis[child]});
             }
          //}
         }
      }
   }
}
void rev_dijkstra(ll x, ll d){
 
   vis2[x]=1;
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
 
   q.push({x,0});
   dis2[x]=0;
 
   while(!q.empty()){
      ll par = q.top().first;
      ll parcost = q.top().second;
      
      q.pop(); 
      // if(!vis[par]){
      //  vis[par]=1;  

      if(parcost<=dis2[par]){
      for(ll i=0;i<graph2[par].size();i++){
          ll child = graph2[par][i].f;
           //if(!vis[child]){
            vis2[child]=1;
            if(parcost+graph2[par][i].s<dis2[child]){
               dis2[child] = parcost+graph2[par][i].s;
               q.push({child,dis2[child]});
             }
          //}
         }
      }
   }
} 
 
void init(ll n){
   for(ll i=1;i<=n;i++){
        dis[i]=inf,par[i]=-1,vis[i]=0;
        graph[i].clear();
     }

}
void init2(ll n){
     for(ll i=1;i<=n;i++){
        dis2[i]=inf,par2[i]=-1,vis2[i]=0;
        graph2[i].clear();
     }   
} 
int main()
{
   test{ 
   cin>>n>>m>>k>>a>>b;
   init(n);
   init2(n);

   for(ll i=1;i<=m;i++){
      cin>>x>>y>>w;
      graph[x].pb({y,w});
      graph2[y].pb({x,w});
   }
   
   dijkstra(a,0);
   rev_dijkstra(b,0);

   ll mn = dis[b];
    
   // for(ll i=1;i<=n;i++){
   //      cout<<dis[i]<<" "<<dis2[i]<<endl;
   // } 
   // cout<<endl;
   for(ll i=1;i<=k;i++){

        ll x,y,w;
        cin>>x>>y>>w;
        
        if(dis[x]!=inf and dis2[y]!=inf){
         mn = min(dis[x] + w + dis2[y] , mn);
        }
        if(dis[y]!=inf and dis2[x]!=inf){
                 mn = min(dis[y] + w + dis2[x] , mn);
        }
   }




   if(mn==inf){
        cout<<-1<<endl;
   }
   else
   cout<<mn<<endl;
   // dijkstra(1,0);

   
   }
 
}  
 