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

typedef unsigned long long ll;

using namespace std;
using namespace std::chrono;

int main(){
    ll a,b,c;
    cin>>a>>b>>c;
          //cout<<(c&(1<<0))<<" "<<(a&(1<<0))<<" "<<(b&(1<<0))<<endl;

    ll ans=0;
    for(ll i=0;i<=31;i++){

       ll x = c&(1<<i);
       ll y = a&(1<<i);
       ll z = b&(1<<i);
       if(x==0){
      // cout<<x<<" "<<y<<" "<<z<<" yyy "<<endl;
          if(y!=0){
            ans++;
          }
          if(z!=0){
            ans++;
          }
       }
       else {
       //cout<<x<<" "<<y<<" "<<z<<" xxx "<<endl;

       // cout<<x<<" "<<(a&(1<<i))<<" "<<(b&(1<<i))<<" xxx "<<endl;

           if(y==0 && z==0){
            ans++;
           }
       }
    }
    cout<<ans<<endl;
}