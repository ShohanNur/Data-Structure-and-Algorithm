//zero base indexing 
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
#define MX       200003
typedef long long ll;
using namespace std;
vector<ll>graph[MX];
ll vis[MX];
ll Table[MX][22];
ll par[MX];
ll dis[MX];
ll n,m,x,y;

void dfs(ll x,ll p,ll d){
	par[x]= p;
	dis[x]= d;

	for(ll i=0;i<graph[x].size();i++){
		ll child = graph[x][i];

		if(child==p) continue;

		dfs(child,x,d+1);
	}

}

ll lca_query(ll p,ll q){
	ll temp,log;

	if(dis[p]<dis[q]){
        swap(p,q);
    }

    log=1; 

    while(true){
    	ll next = log+1;

    	if((1<<next)>dis[p]) break;
    	log++;
    }
    
    // here log means minimum ceil value of log(dis(p))

     for (ll i = log; i >= 0; i--)
          if (dis[p] - (1 << i) >= dis[q])
              p = Table[p][i];

      if (p == q)
          return p;
      //p==q means here we find the lowest common ancester and return  
        for (ll i = log; i >= 0; i--)
          if (Table[p][i] != -1 && Table[p][i] != Table[q][i])
              p = Table[p][i], q = Table[q][i];
     

   
      return par[p]; 
      // if p==q not meets then return parent of p or q 

}
void lca_init(ll n){
	memset(Table,-1,sizeof Table);

	for(ll i=0;i<n;i++){
		Table[i][0] = par[i];
	}

	for(ll j=0; (1<<j)<n;j++){
		for(ll i=0;i<n;i++){
			if(Table[i][j-1]!=-1){
				Table[i][j] = Table[Table[i][j-1]][j-1];
			}
		}
	}
}

int main(){
 cin>>n;
 for(ll i=0;i<n-1;i++){
   cin>>x>>y;
  // x--,y--;
   graph[x].pb(y);
   graph[y].pb(x);
 }
 dfs(0,0,-1);
 lca_init(n);

 cin>>m;
 while(m--){
 cin>>x>>y;	
// x--,y--;
 //printf( "%d\n", lca_query(x,y)+1);
 printf( "%d\n", lca_query(x,y));

 }
}

/*
7
0 2
0 4
1 4
2 3
4 5
2 6
3
3 6
5 1
2 4
*/