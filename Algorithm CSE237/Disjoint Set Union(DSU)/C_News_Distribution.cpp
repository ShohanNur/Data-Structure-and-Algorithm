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

ll n,m,k,x;
ll parent[500002],Rank[500002];
 vector<int>v;
void init(ll n)
{
          for(int i=1 ;i<=n ;i++)
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



int main(){
    
   
   cin>>n;
   init(n);
   cin>>m;
   while(m--){
     cin>>k;
     v.clear();
     for(ll i=0;i<k;i++){
       
        cin>>x;
        v.pb(x);
     }

     if(v.size()<=1){
      continue;
     }
     else{
       for(ll i=0;i<v.size()-1;i++){
          int p = v[i];
          int q = v[i+1];
          int pp = find(p);
          int qq = find(q);
        
       
          
          if(pp!=qq){
            Union(p,q);
          }
       }
     }
     v.clear();
   }


   map<int,int>mp;

   for(ll i=1;i<=n;i++){
      int par = find(i);
      mp[par]++;
   }

   for(ll i=1;i<=n;i++){
      int x = find(i);
      cout<<mp[x]<<" ";
   } 
   cout<<endl;
   
}