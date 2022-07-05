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

  ll setbit[32];
  ll notsetbit[32];
int main(){

   ll n; cin>>n;
   ll a[n+1];
   for(ll i=0;i<n;i++){
    cin>>a[i];
   }
  ll ans=0;
  for(ll i=0;i<=31;i++){
    ll set=0,unset=0;
    for(ll j=0;j<n;j++){
        if(a[j]&(1<<i)){
            set++;
        }
        else{
            unset++;
        }


    }
        ll x = set*unset;
        ans+=(1<<i)*x;
  }
  cout<<ans<<endl;

}
/*

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

  ll setbit[32];
  ll notsetbit[32];
int main(){

   ll n; cin>>n;
   ll a[n+1];
   for(ll i=0;i<n;i++){
    cin>>a[i];
   }
  
  for(ll i=0;i<=31;i++){
    for(ll j=0;j<n;j++){
        if(a[j]&(1<<i)){  // check if the ith bit is set or not
            setbit[i]++;
        }
        else{
            notsetbit[i]++;
        }
    }
  }
  ll ans=0;
  vector<ll>v;

  for(ll i=0;i<32;i++){
      ll x = setbit[i]*notsetbit[i];
      v.pb(x);
  }

  for(ll i=0;i<v.size();i++){
      //cout<<v[i]<<" ";
      ans+=(v[i]*1<<i);
  }
  cout<<ans<<endl;


}
*/