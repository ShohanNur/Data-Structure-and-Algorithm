//https://cses.fi/problemset/task/1679
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

vector<int>adj[100001];
int indeg[100001];
vector<int>res;
void toposort(int n)
{
    queue<int>q;

    for (int i = 1; i<=n; i++)
        if(indeg[i]==0) q.push(i);
  
    int x;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        res.push_back(x);
        for (int i = 0; i<adj[x].size(); i++){
            int child = adj[x][i];

            if( --indeg[child]==0 ) q.push(adj[x][i]);
        }
    }
   
}

void init(int n)
{
    for (int i =1 ; i<=n; i++)
        indeg[i] = 0;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    init(n);
    while(m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
    }

    toposort(n);
    if(res.size()!=n){
      cout<<"IMPOSSIBLE\n";
    }
    else{
     for (int i = 0; i<res.size(); i++)
     {
        cout<<res[i]<<" ";
     }
     cout<<endl;
  }
}
/**
10 20
5 2
2 4
8 9
6 4
7 6
8 4
5 3
9 4
8 3
10 8
3 9
1 8
2 9
7 4
7 2
9 6
3 4
2 6
1 9
10 1
*/

