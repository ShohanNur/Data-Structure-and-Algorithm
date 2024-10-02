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

vector<ll> graph[MXN];
vector<vector<ll>>cycles;

void dfs(ll node,ll p , ll color[], ll par[], ll vis[])
{
    // mark the node as fully visited
    if(color[node]==2){
      return;
    }
    // cycle detected and backtracking to find the cycle
    if(color[node]==1){ 
        ll cur=p;
        vector<ll>cycle;
        cycle.pb(cur);
        while(cur!=node){
            cur= par[cur];
            cycle.pb(cur);
        }
        cycles.pb(cycle);
        return;
    }

    vis[node]=1;
    color[node]=1;

    for(auto child:graph[node]){
         if(child==p){
               continue;
         }
         par[child]=node;
         dfs(child,node,color,par,vis);
    }
    color[node]=2;
}
void init(ll n)
{
    for(ll i=0;i<=n;i++){
        graph[i].clear();
    }
    cycles.clear();
}
void solve()
{
    ll n,e;
    cin>>n>>e;
    ll vis[n+1];
    ll color[n+1];
    ll par[n+1]; 
    for(ll i=1;i<=n;i++){
        vis[i]=0;
        color[i]=0;
        par[i]=-1;
    }       
    init(n);
    for(ll i=1;i<=e;i++){
       ll u,v;
       cin>>u>>v;
       graph[u].pb(v);
       graph[v].pb(u);
    }

    for(ll i=1;i<=n;i++){
         if(!vis[i]){
             dfs(i,i, color, par , vis);
         }
    }
      for(auto cycle:cycles){
         for(auto node:cycle){
               cout<<node<<" ";
         }
         cout<<endl;
      }
      cout<<endl;
}
int32_t main()
{
   fastio
   int t = 1;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}