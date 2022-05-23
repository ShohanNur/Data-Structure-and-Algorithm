//https://cses.fi/problemset/result/3977010/
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
 
ll n,m,a,b,w;
ll parent[200002],Rank[200002];
void init(ll n)
{
          for(int i=0 ;i<=n ;i++)
            Rank[i]=1,parent[i]=i;
}
 
ll find(ll v) {
    if (v == parent[v]) {
        return v;
        }
    return parent[v] = find(parent[v]);
}
 
void Union(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (Rank[a] > Rank[b]) {
            swap (a, b);
                }
        parent[a] = b;
        Rank[b] += Rank[a];
    }
}
 
vector<pair<ll,pair<ll,ll>>>v;
 set<ll>st;
 
int main(){
   cin>>n>>m;
  
  
  for(ll i=1;i<=m;i++){
    cin>>a>>b>>w;
    
    v.pb({w,{a,b}});
 
   }
   sort(v.begin(),v.end());
   init(n);
    ll ans=0;
    ll cnt=0;
   for(ll i=0;i<m;i++){
    
   
 
    a = find(v[i].s.f);
    b = find(v[i].s.s);
    ll cost = v[i].first;
    
       if(a!=b) {
        ll x = parent[a];
        ll y = parent[b];
        if(x!=y){
            Union(a,b);
            //cout<<a<<"------"<<b<<" cost = "<<cost<<endl;
            st.insert(a);
            st.insert(b);
            ans+=cost;
        }
    }
 
  } 
  // if(st.size()==n){
  //   for(ll i=1;i<n;i++){
  //       cout<<i<<" ";
  //   }
  //   cout<<endl;
  // }
  // else{
  //    for(auto i:st){
  //       cout<<i<<" ";
  //    }
  //    cout<<endl;
  // }
  for(ll i=1;i<=n;i++){
     if(find(i)==i){
        cnt++;
    }
  }
  if(cnt==1){
  cout<<ans<<endl;
 }
 else{
    cout<<"IMPOSSIBLE\n";
 }
}