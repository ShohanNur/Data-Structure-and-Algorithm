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
vector<ll>node[200003];
bool vis[200003];
vector<ll>res;
ll inDeg[200003];
ll n, m,u,v;
void printAllPossibleTopoSort(ll n)
{
   bool flag=0;
   for(int i=1;i<=n;i++)
   {
      if(!vis[i] && !inDeg[i])
      {
         flag=1;
         res.pb(i);
            vis[i]=1;
            for(auto u: node[i]) inDeg[u]--; 
            printAllPossibleTopoSort(n);
            res.pop_back();
            vis[i]=0;
            for(auto u: node[i]) inDeg[u]++; 
      }
   }
   if(!flag)
   {
         for(int i=0;i<res.size();i++) cout<<res[i]<<(i==n-1? "\n": " ");
   }
   
}
void init(){
   for(ll i=1;i<=n;i++)
       {
         vis[i]=0,node[i].clear(),inDeg[i]=0;
       }
       res.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
       
       cin>>n>>m;
       
       init();

       for(int i=1;i<=m;i++)
      {
            cin>>u>>v;
            // u--;v--;
            inDeg[v]++;
            node[u].push_back(v);
            // adj[v].push_back(u);
      }
      printAllPossibleTopoSort(n);
      cout<<endl;
   }
}
/*
2
7 6
1 2
2 3
2 4
1 5
5 6
5 7
6 6
6 3
6 1
5 1
5 2
3 4
4 2
*/