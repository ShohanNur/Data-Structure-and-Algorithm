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

vector<ll>graph[200005];
ll vis[1005][1005];
char c[1005][1005];
ll n,m;
void dfs(ll i,ll j){
    vis[i][j]=1;

           
            if(j<m && c[i][j+1]=='.' && !vis[i][j+1]){
                dfs(i,j+1);
            }
            if(i>0&&c[i-1][j]=='.'&&!vis[i-1][j]){
                dfs(i-1,j);
            }
            if(j>0&&c[i][j-1]=='.'&&!vis[i][j-1]){
                dfs(i,j-1);
            }
            if(i<n&&c[i+1][j]=='.'&&!vis[i+1][j]){
                dfs(i+1,j);
            }
            
    
}
int main()
{

   cin>>n>>m;

   for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
        cin>>c[i][j];
    }
   }
   ll ans=0;
   for(ll i=1;i<=n;i++){
    for(ll j=m;j>=1;j--){
        if(c[i][j]=='.' && !vis[i][j]){

            dfs(i,j);
            ans++;
  
        }
    }
   }

   cout<<ans<<endl;
}
