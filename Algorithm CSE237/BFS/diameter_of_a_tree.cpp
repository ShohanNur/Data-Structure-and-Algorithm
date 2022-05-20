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
vector<int> graph[100003];
int vis[100003];
int dis[100003];
int n,m,x,y;

void bfs(ll x,ll d){
    vis[x]=1;
    dis[x]=d;
    queue<ll>q;
    q.push(x);

    while(!q.empty()){
        ll xx = q.front();
        q.pop();
        for(ll i=0;i<graph[xx].size();i++){
             ll child = graph[xx][i];
             if(!vis[child]){
                vis[child]=1;
                dis[child]=dis[xx]+1;
                q.push(child);
             }
        }
    }
}
void init(ll n){
    for(ll i=1;i<=n;i++){
        vis[i]=0,dis[i]=0;
    }
}
void solve(){
   cin>>n;
   for(ll i=0;i<n-1;i++){
      cin>>x>>y;
      graph[x].pb(y);
      graph[y].pb(x);
   }
   bfs(1,0); 
   ll mx=-1;
   ll mxin; 
   for(ll i=1;i<=n;i++){
     if(mx<dis[i]){
        mx = dis[i];
        mxin = i;
     }
    //cout<<dis[i]<<" ";
   }
   //cout<<mxin<<endl;
   init(n);
   bfs(mxin,0);
   int ans=0;
    for(ll i=1;i<=n;i++){
     ans = max(ans,dis[i]);
     //cout<<dis[i]<<" ";
   }
   cout<<"Diameter of the tree is : "<<ans<<endl;
} 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ll k=0;
    //test{
     //   cout<<"Case "<<++k<<":"<<"\n"; 
        solve();
   // }

}
/*
6 
1 2 
1 3
3 4
3 5
2 6
*/