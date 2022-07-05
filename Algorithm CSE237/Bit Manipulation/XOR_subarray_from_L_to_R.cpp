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

typedef unsigned long long ll;

using namespace std;
using namespace std::chrono;

int main(){
  ll n; cin>>n;
  ll a[n+1];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll ans=a[0];
  ll cum[n+1];
  cum[0]=a[0];
  for(ll i=1;i<n;i++){
     ans^=a[i];
    // cout<<ans<<" ";
     cum[i] = ans;
  }
  cout<<endl;
  ll q;
  cin>>q;
  while(q--){
    ll x,y;
    cin>>x>>y;
    if(x==0){
      cout<<cum[y]<<endl;
    }
    else{
    ll ans = cum[y]^cum[x-1];
    cout<<ans<<endl;
    }
  }



}