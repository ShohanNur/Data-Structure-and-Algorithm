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

int main(){
   ll n; cin>>n;
   ll a[n+1];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   ll lis[n+1];

   lis[0]=1;

   for(int i=1;i<n;i++){
    lis[i]=1;
    for(int j=0;j<i;j++){
      if(a[i]>a[j]){
        lis[i] =max(lis[i],lis[j]+1);
      }
    }
   }
   for(int i=0;i<n;i++){
    cout<<lis[i]<<" ";
   }
   cout<<endl;

   cout<<*max_element(lis,lis+n)<<endl;
}

