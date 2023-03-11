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
#define sz       100003

typedef long long ll;

using namespace std;
using namespace std::chrono;


ll parent[500002],Rank[500002];
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
    ll n,e;
    cin>>n>>e;
    vector<pair<ll,ll>>v;
    for(int i=0;i<e;i++){
       ll x,y;
       char a,b;
       cin>>x>>a>>y>>b;
       v.pb({x,y});
    }
    init(n);
    
    ll cycle = 0;

    for(int i=0;i<v.size();i++){
        int x = find(v[i].f);
        int y = find(v[i].s);

        if(x==y){
          cycle++; 
        }
        else{
          Union(v[i].f,v[i].s);
        }
    }

    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            cnt++;
        }
    }
    cout<<cycle<<" "<<cnt-cycle<<endl;

}