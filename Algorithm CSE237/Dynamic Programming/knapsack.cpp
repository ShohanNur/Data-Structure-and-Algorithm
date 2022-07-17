
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

int main(){
  int n,m; cin>>n>>m;

  int p[n+2],w[n+2];
  p[0]=0;
  w[0]=0;
  for(int i=1;i<=n;i++){
     cin>>p[i];
  }
  for(int i=1;i<=n;i++){
    cin>>w[i];
  }
  int dp[n+2][m+2];

  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
        if(i==0 || j==0){
          dp[i][j]=0;
        }
        else if(w[i]<=j){
           dp[i][j] = max(dp[i-1][j], p[i]+dp[i-1][j-w[i]]);
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
    }
  }
  cout<<dp[n][m]<<endl;
}
/*
4 8
1 2 5 6
2 3 4 5 
*/