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
#define sz       200003

typedef long long ll;

using namespace std;
using namespace std::chrono;
ll n,e,x,y;
vector<ll>graph[sz],node[sz];
ll vis[sz];
ll out[sz];
ll timer;
vector<ll>res;
vector<vector<ll>>ans;
void dfs(ll x){
    vis[x]=1;
    timer++;
    for(ll i=0;i<graph[x].size();i++){
        ll child = graph[x][i];
        if(!vis[child]){
            dfs(child);
        }
    }
    out[x]=++timer;
    
}
void dfs2(ll x){
    vis[x]=1;
    res.pb(x); 
    for(ll i=0;i<node[x].size();i++){
        ll child = node[x][i];
        if(!vis[child]){
            dfs2(child);
        }
    }
}
void init(ll n){
    for(ll i=1;i<=n;i++){
        vis[i]=0;
    }
}
int main(){
    cin>>n>>e;
    while(e--){
     cin>>x>>y;
     graph[x].pb(y);
     node[y].pb(x);
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    vector<pair<ll,ll>>vc;

    for(ll i=1;i<=n;i++){
        vc.pb({out[i],i});
    }
    sort(vc.rbegin(),vc.rend());
    init(n);
    for(auto i:vc){
        if(!vis[i.s]){
            dfs2(i.s);
            ans.pb(res);
            res.clear();
        }
    }
    for(auto i:ans){
        cout<<"Size of the SSC is :"<<i.size()<<endl;
        cout<<"SSC :";
        for(auto j:i){
           cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
/*
process : 
---------
first of all find the out time of each node . then transpose the graph. then call dfs in decreasing order of the out time of the first graph and put the SCC in a vector and print.

9 12
1 2
8 2
2 7
7 8
7 1
1 5
7 5
7 6
6 4
4 5
5 3
3 4
*/
