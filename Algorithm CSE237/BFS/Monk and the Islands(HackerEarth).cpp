//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

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
vector<int> graph[100003];
int vis[100003];
int dis[100003];

void bfs(int node, int d){
    vis[node] = 1;
    dis[node] = d;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            int child = graph[x][i];
            if(!vis[child]){
                vis[child]=1; 
                q.push(child);
                dis[child] = dis[x]+1;
            }
        }
    }
}

int main()
{
test{ 
memset(vis,0,sizeof(vis));  
memset(dis,0,sizeof(dis)); 
int n,e;

cin>>n>>e;
while(e--)
{
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
}

bfs(1,0);

// for(int i=1;i<=n;i++)
// {
//     cout<<dis[i]<<" ";
// }
cout<<dis[n]<<endl;
}
}
/*
6 5
1 2 
1 3
3 4
3 5
2 6
*/