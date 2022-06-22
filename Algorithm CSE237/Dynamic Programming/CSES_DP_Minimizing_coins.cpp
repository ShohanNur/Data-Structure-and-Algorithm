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
	ll n,x;
	cin>>n>>x;
    vector<ll>a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
    ll dp[x+1];
    dp[0]=0;
    for(ll i=1;i<=x;i++){
    	dp[i]=inf;
    }
	//init();
	for(ll i=1;i<=x;i++){ 
		for(ll j=0;j<n;j++){
			if(i-a[j]>=0){
			dp[i]=min(dp[i],dp[i-a[j]]+1);
		  }
		}
	}
    if(dp[x]==inf){
    	cout<<-1<<endl;
    }
    else{

	cout<<dp[x];

    }
}