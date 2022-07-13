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
#define inf      1e12
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;

ll big_mod(ll base, ll power, ll x)
{
    if(power == 0)return 1;
    ll h = big_mod(base, power / 2 , x);
    h = (h * h) % x;
    if(power % 2 )h = (h * base) % x;
    return h;
 
}

int main(){
    
   ll n; cin>>n;
   
   // fermat's little theorem : a^m-1 congruent to 1 under a prime m , where a and m are coprime with each other 
   // a^m-2 mod m = modulo inverse of a 
   cout<<big_mod(n,5LL,7LL)<<endl;
}