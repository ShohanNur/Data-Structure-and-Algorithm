
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


ll a[101];
ll n;
ll dp[100][100];

ll matrixChain(ll i, ll j){
    if(i==j){
        return 0;
    }
    if(~dp[i][j]){
        return dp[i][j];
    }

    dp[i][j] = LLONG_MAX;

    for(ll k= i ; k < j; k++){
        dp[i][j] = min(dp[i][j],matrixChain(i,k)+matrixChain(k+1,j)+a[i-1]*a[j]*a[k]);
    }
    return dp[i][j];
}
int main(){
      cin>>n;
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      memset(dp, -1 , sizeof dp);

      cout<<matrixChain(1,n-1)<<endl;
}
/*
5
3 2 4 2 5

here 4 matrix : 3 x 2 , 2 x 4 , 4 x 2 , 2 x 5

*/