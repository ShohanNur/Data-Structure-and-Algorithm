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

ll dp[1000005];

int main(){
  ll n,x;
  cin>>n>>x;
    vector<ll>a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }

  dp[0]=1; // base case if we want sum==0 then we have to do nothing hence 1
  for(ll i=0;i<n;i++){//take each one after another and do calculation
    for(ll j=0;j<=x;j++){ // here we have to fill the sum by those coins and build a dp array
      if(j-a[i]>=0){
      dp[j]+=dp[j-a[i]]; // recurrance relation : dp[j] = dp[j-a[0]]+ ....dp[j-a[n-1]] , here dp table works like cummulatively
      dp[j]%=mod;
      }
    }
  }

  cout<<dp[x];
}