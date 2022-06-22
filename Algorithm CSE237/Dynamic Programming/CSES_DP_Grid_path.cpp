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
ll dp[1001][1001];

int main(){
  ll n; cin>>n;
  char ch[n+1][n+1];
  bool ok[n+1][n+1];
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
        cin>>ch[i][j];
    }
  }
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
        if(ch[i][j]=='.'){
            ok[i][j]=1;
        }
        else{
            ok[i][j]=0;
        }
    }
  }
  dp[1][1]=1; 
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){

       if(ok[i][j]==0){
        dp[i][j]=0;
       }
       else{
       ll op1 = (i==1)? 0 : (dp[i-1][j])%mod;
       ll op2 = (j==1)? 0:  (dp[i][j-1])%mod;    
       dp[i][j]+=op1;
       dp[i][j]%=mod;
       dp[i][j]+=op2;
       dp[i][j]%=mod;
      }
    }
  }

  
  cout<<dp[n][n];
}