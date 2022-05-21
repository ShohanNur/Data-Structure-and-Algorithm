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
#define inf      10000000000000000
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       503
typedef long long ll;
using namespace std;

ll adj[sz][sz], Next[sz][sz];
ll n,m,k;
void printMatrix(ll n)
{
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            cout << adj[i][j] << " \n"[j==n-1];
}

void warshall(ll n)
{
    for(int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if(adj[i][j] > adj[i][k]+adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    Next[i][j] = Next[i][k];///tracking path
                }
}
void init(ll n)
{
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            if(adj[i][j]==0)
            {
                adj[i][j] = inf;
                Next[i][j] = -1;
            }
            else
                Next[i][j] = j;///tracking path
}
int main()
{
    ll n, m, x, y, w;
    cin >> n >> m >> k;
      init(n);
    for (int i = 1; i<=m; i++)
    {
        cin >> x >> y >> w;
        adj[x][x]=0,adj[y][y]=0;
        adj[x][y] = min(w,adj[x][y]);
        adj[y][x] = min(w,adj[y][x]);
    }

    warshall(n);


    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        if(adj[x][y]==inf){
          cout<<-1<<endl;
        }
        else{
             cout << adj[x][y] << endl;
        }
  
    }
    return 0;
}
/**
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

*/






