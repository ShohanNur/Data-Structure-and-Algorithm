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
int n; 
int a[MX];
int dp[101][101];

int lis(int idx, int prev_idx){
    if(idx == n) return 0;

    if(dp[idx][prev_idx+1]!=-1){
        return dp[idx][prev_idx+1];
    }

    int notTake = lis(idx+1,prev_idx);

    int take = INT_MIN; 

    if(a[idx]>a[prev_idx]|| prev_idx == -1){
        take = 1+lis(idx+1,idx);
    }

    return dp[idx][prev_idx+1] = max(take,notTake);
}
int main(){
   cin>>n;
   memset(dp,-1,sizeof dp);
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   cout<<lis(0,-1)<<endl;
    
}