#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define pi 2*acos(0.0)
#define f first
#define s second
#define inf INT_MAX
#define MXN 500001
#define endl "\n"
#define eps 1e-6
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define spc(x) cout << fixed << setprecision(x)
#define fastio {ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define test ll t; cin >> t; while (t--)

typedef long long ll;
using namespace std;

set<ll> graph[MXN];
ll vis[MXN];
ll SubTree[MXN];
ll par[MXN];

void dfs(ll node, ll p){
      SubTree[node] = 1;
      for(auto child: graph[node]){
         if(child!=p){
               dfs(child,node);
               SubTree[node] += SubTree[child];
         }
      }
}
ll dfs_for_centroid(ll node, ll p, ll n){
      for(auto child: graph[node]){
            if(child!=p && SubTree[child]>n/2){
                  return dfs_for_centroid(child,node,n);
            }
      }
      return node;
}

void decompose(ll node, ll p){
      dfs(node,p);
      ll centroid = dfs_for_centroid(node,p,SubTree[node]);

      cout<<"Tree rooted at "<<node<<" with size "<<SubTree[node]<<" has the centroid " << centroid <<endl;
      par[centroid] = p;
      for(auto child: graph[centroid]){
            graph[child].erase(centroid);
            decompose(child,centroid);
      }
}
void solve()
{
   ll n; cin>>n;

   for(ll i=1;i<n;i++){
         ll u,v; cin>>u>>v;
         graph[u].insert(v);
         graph[v].insert(u);
   }
   
   decompose(1,-1);  
}
int32_t main()
{
   fastio
   int t = 1;
   //cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}