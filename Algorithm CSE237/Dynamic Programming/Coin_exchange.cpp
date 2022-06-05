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
#define MX       2000000
typedef long long ll;
using namespace std;




void solve(){
   ll n,k;
   cin>>n>>k;
   ll coins[n+1];
   for(int i=0;i<n;i++){
    cin>>coins[i];
   }
   ll dp[k+1];
   dp[0]=0;
   for(int i=1;i<=k;i++){
     dp[i]=inf;
   }
   for(int i=1;i<=k;i++){
     ll ans = inf;
     for(int j=0;j<n;j++){
     if(coins[j]<=i)
        ans = min(ans,dp[i-coins[j]]);
     }
     if(ans == inf)
        dp[i] = inf;
     else
        dp[i] = ans+1;
   }
  if(dp[k]==inf){
    cout<<"???"<<endl;
  } 
  else{
    cout<<dp[k]<<endl;
  }
  for(ll i=0;i<=k;i++){
    cout<<dp[i]<<" ";
  }
  cout<<endl;
}
int main(){
  fastio
  test{
     solve();
  }
}

