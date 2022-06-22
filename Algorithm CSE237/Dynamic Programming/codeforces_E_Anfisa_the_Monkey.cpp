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
   int k,x,y;
   cin>>k>>x>>y;
   string s;
   cin>>s;

   int dp[202][202]={0};

   dp[0][0]=1;

   int sz = s.size();

   for(int i=1;i<=k;i++){
    for(int j=1;j<=sz;j++){
        for(int len=x;len<=y;len++){
            if(j-len>=0 && dp[i-1][j-len]!=0){
                dp[i][j]=len;
            }
        }
      }
   }
   if(dp[k][sz]==0){
    cout<<"No solution\n";
   }
   else{
    //     for(int i=1;i<=k;i++){
    //     for(int j=1;j<=s.size();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    vector<int>v;
    while(k!=0){
        v.pb(dp[k][sz]);
        sz-=dp[k][sz];
        k--;
    }

    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int j=0;
    for(int i=0;i<v.size();i++){
        cout<<s.substr(j,v[i])<<"\n";
        j+=v[i];
    }
   }
}