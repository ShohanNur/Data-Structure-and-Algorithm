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
 
 int dp[1001][100005];
 
int main(){
	int n,x;
	cin>>n>>x;
    vector<int>page(n+1),price(n+1);
	for(ll i=1;i<=n;i++){
		cin>>price[i];
	}
		for(ll i=1;i<=n;i++){
		cin>>page[i];
	}

	
	for(ll i=1;i<=n;i++){ 
		for(ll j=0;j<=x;j++){
	    dp[i][j] = dp[i-1][j];		
		if(j>=price[i]){
			dp[i][j]=max(dp[i][j],dp[i-1][j-price[i]]+page[i]);
		  }
		}
	}

	cout<<dp[n][x];
}