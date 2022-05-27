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

typedef long long ll;
using namespace std;

const long long MX = 100002;
const long long k =(ll)log2(MX)+1;

ll sparse[MX][k];
ll a[MX];  

void buildSparseTable(ll n){
      for (int i = 0; i < n; i++)
        sparse[i][0] = i;
    
    for(ll j=1;(1<<j)<=n;j++){
        for(ll i=0;(i+(1<<j)-1)<n ; i++){
            if(a[sparse[i][j-1]]<a[sparse[i+(1<<(j-1))][j-1]]){
             sparse[i][j]=sparse[i][j-1];
            }
            else
            sparse[i][j] = sparse[i+(1<<(j-1))][j-1];
        }
    }
}

ll query(ll l,ll r){
    ll j = (ll)log2(r-l+1); 
       if (a[sparse[l][j]] <= a[sparse[r - (1 << j) + 1][j]])
        return a[sparse[l][j]];

    else
        return a[sparse[r - (1 << j) + 1][j]];
    
}
int main(){
  fastio

  ll n; cin>>n;
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  buildSparseTable(n);

  ll q,l,r;

  cin>>q;

  while(q--){
    cin>>l>>r;
    if(l>r){
        swap(l,r);
    }
    cout<<query(l,r)<<endl;
  }
}
/*
7
1 6 -1 5 3 1 0
3
4 7
6 2
3 5
*/
