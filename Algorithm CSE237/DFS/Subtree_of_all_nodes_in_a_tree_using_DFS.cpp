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
vector<int>ans;
vector<int> node[200003];
vector<int>current[200003];
int vis[200003];
int dis[200003];
int start[200003];
int End[200003];
int timer;
void dfs(int x,int p)
{
  vis[x]=1;
  timer++;
  start[x]=timer;
  ans.pb(x);
  
  for(auto child:node[x]){
     if(!vis[child]){
        dfs(child,x);  
     }
  }
   End[x]=timer;
  

}

   // memset(ans,0,sizeof(ans));
void solve(){ 
  ll n,e;
  cin>>n>>e;
  while(e--){
    ll x,y;
    cin>>x>>y;
    node[x].pb(y);
    node[y].pb(x);
  }

     
      dfs(0,-1);
      cout<<"Start time and end time : "<<endl;
      for(ll i=0;i<n;i++){
        cout<<"Node "<<i<<" starts at "<<start[i]<<" ends at "<<End[i]<<endl;
       
      } 
      cout<<endl;
        for(ll i=0;i<n;i++){
       // cout<<start[i]<<" "<<End[i]<<endl;
           if(start[i]!=End[i]){
            cout<<"subtree of node "<<i<<" is :";
            for(int j=start[i];j<End[i];j++)
            {
                cout<<ans[j]<<" ";
            }
            cout<<endl;
           }
      } 

}
int main(){
 // test{
    solve();
 // }
}
/*
10 9
7 9
1 7
2 8
0 1
1 2
0 3
3 4
2 5
4 6
*/