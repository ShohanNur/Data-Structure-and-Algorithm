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
#define inf      1000000000000
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       200003
typedef long long ll;
using namespace std;
vector<ll>graph[22];
ll vis[22][22];
ll dis[22][22];
ll n,m;
ll ax,ay,bx,by,cx,cy,dx,dy;

char c[22][22];

vector<ll>vc;
bool is_valid(ll i,ll j){
    return (i>=1&&i<=n&&j>=1&&j<=m);
}
int row[] = {-1,0,0,1};
int col[] = {0,-1,1,0};

void bfs(ll i,ll j){
   bool ok=0; 
   vis[i][j]=1;
   queue<pair<pair<ll,ll>,ll>>q;
   q.push({{i,j},0});
   
   while(!q.empty()){
      int x=q.front().first.first;
      int y=q.front().first.second;
      
      int distance = q.front().second;
      //cout<<x<<" "<<y<<" "<<s<<endl;
      if(x==dx && y==dy){
         //cout<<distance<<"xxx"<<endl;
         vc.pb(distance); 
      }
 
      q.pop();
    
          for(ll k=0;k<4;k++){
          
            ll r = x+row[k];
            ll cc = y+col[k];
 
            if(is_valid(r,cc) && c[r][cc]=='.' && !vis[r][cc]){
                vis[r][cc]=1;
               // cout<<"x"<<distance<<endl;
                q.push({{r,cc},distance+1});
            }
       
         }
       
   }

   
}

void init(ll n,ll m){
   for(ll i=1;i<=n;i++){
      for(ll j=1;j<=m;j++){
         vis[i][j]=0,dis[i][j]=0;
      }
   }
}
void init2(ll n,ll m){
     for(ll i=1;i<=n;i++){
      for(ll j=1;j<=m;j++){
         vis[i][j]=0,dis[i][j]=0,c[i][j]=0;
      }
   }
   vc.clear();
}
int main()
{
    ll k=0;
    test{
      cout<<"Case "<<++k<<": "; 
      cin>>n>>m;
      init2(n,m);
      for(ll i=1;i<=n;i++){
         for(ll j=1;j<=m;j++){
            cin>>c[i][j];
         }
      }
      for(ll i=1;i<=n;i++){
         for(ll j=1;j<=m;j++){
            if(c[i][j]=='a'){
               ax = i;
               ay = j;
               c[i][j]='.';
            }
            if(c[i][j]=='b'){
               bx = i;
               by = j;
               c[i][j]='.';

            }
            if(c[i][j]=='c'){
               cx = i;
               cy = j;
               c[i][j]='.';

            }
            if(c[i][j]=='h'){
               dx = i;
               dy = j;
               c[i][j]='.';

            }
         }
      }
      bfs(ax,ay);
      init(n,m);
      bfs(bx,by);
      init(n,m);
      bfs(cx,cy);
      init(n,m);
      ll mx=-1;
      for(auto i:vc){
         mx = max(i,mx);
         //cout<<i<<endl;
      }
      cout<<mx<<endl;
   }  
} 
/**
6
20 20
####################
#..................#
#..................#
#..................#
#...a..............#
#..................#
#..................#
#..............c...#
#..................#
#..................#
#..................#
#..................#
#..................#
#.......h..........#
#..................#
#..................#
#....b.............#
#..................#
#..................#
####################
19 19
###################
#hbc..............#
#################.#
#.......#.......#.#
#.#.#.#.#.#.#.#.#.#
#...#.......#.....#
#.#################
#.#.......#.......#
#.#.#.#.#.#.#.#.#.#
#.....#.......#...#
#################.#
#.......#.......#.#
#.#.#.#.#.#.#.#.#.#
#...#.......#.....#
#.#################
#.#.......#.......#
#.#.#.#.#.#.#.#.#.#
#.....#.......#..a#
###################
18 20
####################
#....h........m....#
#..........#.......#
#.....m............#
#.......m......c...#
#.......#..........#
#..................#
#.......m........m##
#m....m...#........#
#.m................#
#..................#
#...............m..#
#.............m..m.#
#..m...............#
#...............#..#
#........m.....mab.#
#................m.#
####################
18 18
##################
#..b....m.....#..#
#..#..#.m...m.m..#
#......m.........#
#m..m..mm.#.....m#
#..#..mc........m#
#.mmm#mmm.m......#
#.............m..#
#.h.#m.##..##....#
#...m..#.#m..##m##
#.#...m#..#...#..#
##............m#.#
#..#.#..m#.m.amm.#
#.#..mm..........#
#.....#.#..m#m...#
#...m..m..#...m..#
#.#m.......#..#..#
##################
19 20
####################
#............m....##
#.#.#.....#........#
#..m....m.....m....#
#........c..b......#
#..........m......m#
#..m.....#...#.....#
#......m........m..#
#....m.......m.....#
#...#.........m..am#
#..................#
#.#.............m..#
#..................#
#..........#.......#
##..............#..#
#......m....#......#
#.m#..........h..#.#
#..................#
####################
19 17
#################
##......c.#.....#
#...m.....m#..mm#
#.......m.......#
#....#m.....m#.##
#...h......##...#
#..m..m..#......#
#..m...mm.......#
#....#...#m.....#
#..m.....m.b....#
#.......##.mmm..#
###............##
#mm.##m........m#
#..........m....#
#..m......#a....#
#.....m.........#
#.m.......m.....#
#.#..#..mm......#
#################
*/