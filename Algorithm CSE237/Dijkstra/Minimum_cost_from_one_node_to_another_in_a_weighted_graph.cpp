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

vector<ll> adj[sz], w[sz];

ll par[sz], cost[sz];
map<ll,ll>mp;
ll dijkstra(ll st, ll en)
{
    priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > > pq;
    
    pq.push({0,st});/// first -> cost of parent , second-> parent node
    cost[st] = 0;
    ll u, c;
    while(!pq.empty())
    {
        c = pq.top().first;///cost of parent node
        u = pq.top().second;///parent node
        pq.pop();
        if(c<=cost[u]){
        for (ll i = 0; i < adj[u].size(); i++)
        {
            ll child = adj[u][i];
            // c = cost of parent , w[u][i] = cost from parent to child , 
            if(c + w[u][i] < cost[child])
            {
                cost[child] = c + w[u][i];
                pq.push({cost[child], child});
                par[child] = u;
                mp[child]=u;
             }

        }
     }
    }
    return cost[en];
}

void init(ll n)
{
    for (ll i =1; i<=n; i++)
        par[i] = -1, cost[i] = inf;
}

int main()
{
    ll x, y, z, n, m, st, en;
    cin >> n >> m;
    init(n);
    for (ll i  = 1; i<=m;i++ )
    {
        cin >> x >> y >> z;
        //x--;
        //y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }

    //cin >> st >> en;
    st=1;
    en=n;
    x = dijkstra(st,en);
    
   

///path printing :
    if(x==inf){
        cout<<"No path exist"<<endl;
    }
    else{
    cout << "The minimum path cost from " << st << " to " << en <<" is = " << x << endl;
    x = en;
    vector<ll>res;
 

    while(~x)
    {
        res.push_back(x);
        x = par[x];
    }


    reverse(res.begin(),res.end());
    //cout<< "The path: ";
    for (ll i = 0; i<res.size(); i++)
        cout << res[i] << " \n"[i==res.size()];
    
     
    return 0;
}
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
