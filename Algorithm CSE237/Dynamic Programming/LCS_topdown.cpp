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
#define NIL      -1
#define MAX      1000002

typedef long long ll;
using namespace std;

string s,ss;
int dp[101][101];

int lcs(int n, int m,string s,string ss){
    if(n==0 || m==0){
        return 0;
    }
    if(s[n-1] == ss[m-1]){
        return dp[n][m] = 1+lcs(n-1,m-1,s,ss);
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    else{
        return dp[n][m] =max(lcs(n,m-1,s,ss),lcs(n-1,m,s,ss));
    }
}
int main()
{
    cin>>s>>ss;
    int n = s.size();
    int m = ss.size();
    memset(dp,-1,sizeof dp);

    cout<<lcs(n,m,s,ss)<<endl;
}
/*
papapapap
papap
*/