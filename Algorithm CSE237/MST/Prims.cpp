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

#define sz 10000
using namespace std;

vector<int>adj[sz], cost[sz];

priority_queue <  pair<int, pair<int,int> >,
vector< pair<int, pair<int,int> > >,
greater< pair<int, pair<int,int> > >
> pq;

int par[sz];
bool col[sz];

int find_par(int n)
{
    if(par[n]==n)
        return n;
    return par[n]=find_par(par[n]);
}

int mst_prims(int st)
{
    int p, q, w,total=0,u,v;
    for (int i = 0; i < adj[st].size(); i++)
    {
        p = min(st,adj[st][i]);
        q = max(st,adj[st][i]);
        pq.push({cost[st][i], {p,q} });
    }
    col[st]=1;
    vector< pair<int, pair<int,int> > > ans;

    while(!pq.empty())
    {
        w = pq.top().first;
        p = pq.top().second.first;
        q = pq.top().second.second;
        pq.pop();

        u = find_par(p);
        v = find_par(q);
        if(u != v)
        {
            par[u] = v;
            ans.push_back({ w, {p,q} });
            total+=w;
            if(col[p]&&col[q]) continue;
            st = col[p]?q:p;
            col[st] = 1;
            for (int i = 0; i < adj[st].size(); i++)
            {
                p = min(st,adj[st][i]);
                q = max(st,adj[st][i]);
                pq.push({cost[st][i], {p,q} });
            }
        }

    }

   

    for (auto &x: ans )
    {
        w = x.first;
        p = x.second.first;
        q = x.second.second;
        cout << "(" << p << "," << q << ") -> " << w << endl;
    }

    return total;
}


void mst_init(int n)
{
    for (int i = 0; i<=n; i++)
        par[i]=i,col[i]=0;
}

int main()
{
    int n, m, x, y, z;

    cin >> n >> m;

    mst_init(n);

    for (int i = 0; i<m; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
    }
    z = mst_prims(1);
    cout << "Total Cost = " << z  << endl;

    return 0;
}
