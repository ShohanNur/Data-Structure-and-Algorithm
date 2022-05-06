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
vector<vector<int>>ans;
vector<int> node[200003];
vector<int>current;
int vis[200003];
int dis[200003];
ll c;
ll root;
void dfs(int x,int parent)
{
  // vis[x]=1;
   current.pb(x);
   c=0;
   for(ll i=0;i<node[x].size();i++){
      int child = node[x][i];
    //  if(!vis[child]){
         if(child!=parent){
            c=1;
            dfs(child,x);
         }
    // }
   }
   if(!c){
   ans.pb(current);
   current.clear();
  }
}

   // memset(ans,0,sizeof(ans));
  void solve(){ 
    ll n; cin>>n;
    for(int i=0; i<=n ; i++)
           vis[i]=0,node[i].clear();
    
    ans.clear();

    
    for(ll i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i==x){
            root = i;
        }
        else
           node[x].pb(i);
    }
    //cout<<root<<endl;
    dfs(root,-1);
    ll answer=0;
   // cout<<ans.size()<<"xx"<<endl;
    for(auto i:ans){
        if(i.size()>0){
         answer++;
       }
    }
    cout<<answer<<endl;
    for(auto i:ans){
        if(i.size()>0){
             cout<<i.size()<<endl;
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
        }
    ans.clear();
    cout<<endl;
    return;
  
}
int main(){
  test{
    solve();
  }
}
/*
6
5
3 1 3 3 1
4
1 1 4 1
7
1 1 2 3 4 5 6
1
1
6
4 4 4 4 1 2
4
2 2 2 2
*/