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
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       100003
typedef long long ll;
using namespace std;

vector<int> adj[sz], w[sz];

int par[sz], cost[sz];

int dijkstra(int st, int en)
{
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push({0,st});/// first -> cost of parent , second-> parent node
    cost[st] = 0;
    int u, c;
    while(!pq.empty())
    {
        c = pq.top().first;///cost of parent node
        u = pq.top().second;///parent node
        pq.pop();
        if(c<=cost[u]){
        for (int i = 0; i < adj[u].size(); i++)
        {
            if(c + w[u][i] < cost[ adj[u][i] ])
            {
                cost[ adj[u][i] ] = c + w[u][i];
                pq.push({cost[ adj[u][i] ], adj[u][i]});
                par[ adj[u][i] ] = u;
             }

        }
     }
    }
    return cost[en];
}

void init(int n)
{
    for (int i = 0; i<n; i++)
        par[i] = -1, cost[i] = inf;
}

int main()
{
    int x, y, z, n, m, st, en;
    cin >> n >> m;
    init(n);
    for (int i  = 0; i<m;i++ )
    {
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }

    cin >> st >> en;

    x = dijkstra(st-1,en-1);

    cout << "The minimum path cost from " << st << " to " << en <<" is = " << x << endl;

///path printing :
    x = en-1;
    vector<int>res;
   // cout<<x<<endl;

    while(~x)
    {
        res.push_back(x+1);
         //cout<<x<<"***"<<par[x]<<endl;
        x = par[x];
        //cout<<x<<"***"<<par[x]<<endl;
    }


    reverse(res.begin(),res.end());
    cout<< "The path: ";
    for (int i = 0; i<res.size(); i++)
        cout << res[i] << ",\n"[i==res.size()-1];

    return 0;
}
/**
7 10
1 3 1
1 4 6
2 6 1
4 2 2
2 7 5
3 6 8
3 4 2
5 4 9
5 6 2
7 5 1
1 7
*/
