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
vector<ll>graph[200003];
ll vis[200003];
ll dis[200003];
ll n,x,y;

void dfs(ll x){
   // finding all subtree size of each nodes
   vis[x]=1; 
   dis[x]=1;
   for(ll i=0;i<graph[x].size();i++){
      ll child = graph[x][i];
      if(!vis[child]){
         dfs(child);
         dis[x]+=dis[child];
      }
   }
}

int main()
{
   cin>>n;
   for(ll i=1;i<=n-1;i++){
      cin>>x>>y;
      graph[x].pb(y);
      graph[y].pb(x);
   }
   if(n%2!=0){
      cout<<-1<<endl;
   }
   else{
   dfs(1);
   bool ok=0,one=0;
   ll cnt=0;
   for(ll i=2;i<=n;i++){
      if(dis[i]%2==0){
         ok = 1;
         cnt++;
      }
      if(dis[i]!=1){
         one=1;
      }
   }

   if(ok){
      cout<<cnt<<endl;
   }
   else{
      if(!one && n%2==0){
         cout<<0<<endl;
      }
      else
      cout<<-1<<endl;
   }
  }
}
/**
7 10
1 3 1
1 4 6
2 6 1
4 2 2
2 7 5
3 6 8
3 4 2
5 4 9
5 6 2
7 5 1
1 7
*/