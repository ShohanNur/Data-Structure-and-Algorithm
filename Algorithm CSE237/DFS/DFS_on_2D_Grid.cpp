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
ll r,c;
ll vis[1003][1003];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool isValid(ll x, ll y){
    if(x<1 || x>r || y<1 || y>c){
      return false;
    }
    if(vis[x][y]==true){
      return false;
    }

    return true;
}
void dfs(ll x, ll y){
    vis[x][y]=1;

    cout<<x<<" "<<y<<endl;

    for(int i=0;i<4;i++){
       if(isValid(x+dx[i],y+dy[i])){
          dfs(x+dx[i],y+dy[i]);
       }
    }
    /*
      if(isValid(x-1,y)){
        dfs(x-1,y);
      }
      if(isValid(x,y+1)){
        dfs(x,y+1);
      }
      if(isValid(x+1,y)){
        dfs(x+1,y);
      }
      if(isValid(x,y-1)){
       dfs(x,y-1);
      }
    */
}
int main(){
    cin>>r>>c;

    dfs(1,1); 
}