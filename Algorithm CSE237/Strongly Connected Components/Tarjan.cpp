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
#define inf      100000000000000
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       100003
typedef long long ll;
using namespace std;

ll n,m,x,y;
vector<ll>graph[200003];
ll vis[200003];
ll timer,scc;
ll low[200003];
ll in[200003];
stack<ll>st;

bool onStack[200003];

void dfs(ll x){
  vis[x]=1;
  in[x]=timer;
  low[x]=timer;
  timer++;
  onStack[x]=1;
  st.push(x);

  for(ll i=0;i<graph[x].size();i++){
     ll child = graph[x][i];
     if((vis[child]==1) && onStack[child]==1){ //if visited and onstack  then update the low time of parent node with the intime of child node

      low[x] = min(low[x],in[child]);
     }
     else{
       if(vis[child]==0){ // if not visited then call dfs 
         dfs(child);

         if(onStack[child]==1){ // when backtrack if onstack update the low time of parent node with the low time of child node

            low[x]=min(low[x],low[child]);
         }
       }
     }
   }
     if(in[x]==low[x]){
      scc++;

      cout<<"SCC NO:"<<scc<<endl;

      ll node;
      while(1){
         node = st.top();
         st.pop();
         onStack[node]=0;
         cout<<node<<" "; 
         if(node == x) break;
      }
      cout<<endl;
     }
 
}

int main()
{
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
         cin>>x>>y;
         graph[x].pb(y);  
    }
    
    for(ll i=1;i<=n;i++){
      if(!vis[i]){
         dfs(i);
      }
    }

}