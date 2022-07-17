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
    int x,y,aa,bb;
ll vis[1003][1003];
char a[1003][1003];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
ll dis[1001][1001];
//vector<pair<ll,ll>>parent;
char parent[1003][1003];
vector<char>path;
 
bool f;
bool isValid(ll x, ll y){
    if(x<1 || x>r || y<1 || y>c){
      return false;
    }
    if(vis[x][y]==true || a[x][y]=='#'){
      return false;
    }
 
    return true;
}
void dfs(ll x, ll y){
    queue<pair<ll,ll>>q;
    q.push({x,y});
    vis[x][y]=1;
    dis[x][y]=0;
    while(!q.empty()){
        int parentx = q.front().first;
        int parenty = q.front().second;
 
        q.pop();
 
        for(int i=0;i<4;i++){
           if(isValid(parentx+dx[i],parenty+dy[i])){
               int childx = parentx+dx[i];
               int childy = parenty+dy[i];
               if(i==0){
               parent[childx][childy]='U';
               }
               if(i==1){
                parent[childx][childy]='R';
               }
               if(i==2){
                parent[childx][childy]='D';
               }
               if(i==3){
                parent[childx][childy]='L';
               }
               vis[childx][childy] = 1;
               dis[childx][childy] = dis[parentx][parenty]+1;
               q.push({childx,childy});
              if(childx==aa && childy==bb){
                 while(1){
             path.push_back(parent[aa][bb]);
      
        if(path.back() == 'L') bb++;
        if(path.back() == 'R') bb--;
        if(path.back() == 'U') aa++;
        if(path.back() == 'D') aa--;
        
        if(aa == x && bb == y)
        break;
                 } 
                 f=1;
                 break;
               }
           }
           if(f) break;
        }
        if(f) break;
    }
 
    // for(int i=1;i<=r;i++){
    //   for(int j=1;j<=c;j++){
    //     cout<<dis[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
}
int main(){
    cin>>r>>c;
    
    for(ll i=1;i<=r;i++){
      for(ll j=1;j<=c;j++){
         cin>>a[i][j];
         if(a[i][j]=='A'){
           x = i;
           y = j;
         }
         if(a[i][j]=='B'){
           aa = i;
           bb = j;
         }
      }
    }
   
    cin>>x>>y;
    dfs(x,y); 
    if(f){
      cout<<"YES\n";
      cout<<path.size()<<endl;
      reverse(path.begin(),path.end());
      for(auto i:path){
        cout<<i;
      } 
      cout<<endl;
    }
    else{
      cout<<"NO\n";
    }
}