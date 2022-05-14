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
#define inf      1e9
#define endl     '\n'
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       100003

typedef long long ll;

using namespace std;
using namespace std::chrono;

ll vis[200005];
vector<ll>order;
ll n,r;
ll mx_element;

void printOrder(){
    for(auto i:order){
        cout<<i<<" ";
    }
    cout<<endl;
}

void backtrack(){
   mx_element=1;
   if(!order.empty()){
    mx_element = order[order.size()-1];
   } 
   if(order.size()==r){
     printOrder();
     return;
   }
   

   for(ll i=mx_element;i<=n;i++){
     if(vis[i]==1) continue;
     order.pb(i);
     vis[i]=1; 
     backtrack();
    
     order.pop_back();
     vis[i]=0;
   }

}

int main()
{
    cin>>n>>r;
    backtrack();
}

