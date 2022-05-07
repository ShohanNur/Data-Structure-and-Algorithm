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

int bellmanford(int st, int en, int n)
{
    cost[st] = 0;
    for (int k = 0; k<n-1; k++) // relaxation n-1 times here
    {
        for (int i = 0; i<n; i++){
            for (int j = 0; j<adj[i].size(); j++){
                int child = adj[i][j];

                if(cost[i] + w[i][j] < cost[child])
                {
                    cost[child] = cost[i] + w[i][j];
                    par[child] = i;///path tracking
                }
        }
    }
   }
 
    for (int i = 0; i<n; i++){
        for (int j = 0; j<adj[i].size(); j++){
             int child = adj[i][j];
            if(cost[i] + w[i][j] < cost[child])
            {
                cout << "Shortest Path could not be determined." << endl;
                cout << "Negative Cycle Detected!" << endl;
                return -inf;
            }
    }
 } 
    return cost[en];
}
void init(int n)
{
    for (int i = 0; i<n; i++)
        par[i]=-1, cost[i]=inf;
}

int main()
{
    int x, y, z, n, m, st, en;
    cin >> n >> m;
    init(n);
    for (int i  = 0; i<m;i++ )
    {
        cin >> x >> y >> z;
        adj[x].push_back(y);
        w[x].push_back(z);
    }

    cin >> st >> en;

    x = bellmanford(st,en, n);
    if(x==-inf) return 0;
    cout << "The minimum path cost from " << st << " to " << en <<" is " << x << endl;

    x = en;
    vector<int>res;

    while(~x)
    {
        res.push_back(x);
        x = par[x];
    }
    reverse(res.begin(),res.end());
    cout<< "The path: ";
    for (int i = 0; i<res.size(); i++)
        cout << res[i] << ",\n"[i==res.size()-1];

    return 0;
}
/**
6 10
0 1 3
0 2 -2
0 4 8
2 3 6
1 2 1
1 5 4
1 4 6
4 5 -5
3 5 -5
3 1 9
0 5

6 10
0 1 3
0 2 -2
0 4 8
2 3 6
1 2 1
1 5 4
1 4 6
4 5 -5
3 5 -5
3 1 -9
0 5
*/
