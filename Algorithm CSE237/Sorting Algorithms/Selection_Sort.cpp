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


ll findMinIndex(ll a[],ll start_index,ll end_index){
    ll mn = LLONG_MAX;
    ll min_index;
    for(ll i=start_index;i<end_index;i++){
        if(mn>a[i]){
            mn = a[i];
            min_index = i;
        }
    }
    return min_index;
}

void selection_sort(ll a[],ll start_index,ll end_index){
   if(start_index >= end_index){
     return;
   }

   ll min_index = findMinIndex(a,start_index,end_index);
   swap(a[start_index],a[min_index]);
   selection_sort(a,start_index+1,end_index);

}
int main()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll s=0;
    ll e=n-1;
    selection_sort(a,s,e);
    for(ll i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

/*
5
5 10 2 0 123
*/