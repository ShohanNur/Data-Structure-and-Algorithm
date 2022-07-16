
#include <bits/stdc++.h>
using namespace std;
 
 
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MIN
#define MXN      100001
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define os tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

vector<ll>graph[200200];
ll vis[200200];
ll par[200200];
ll dis[200200];

void dfs(ll x, ll d, ll p){
    vis[x]=1;
    dis[x]=d;
    par[x]=p;

    for(ll i=0;i<graph[x].size();i++){
         ll child = graph[x][i];

         if(!vis[child]){
            vis[child]=1;
            dis[child]=dis[x]+1;
            dfs(child,d+1,x);
         }
    }
}

ll LCA(ll a, ll b){
    if(dis[a]>dis[b]){
        swap(a,b);
    }

    ll d = dis[b]-dis[a];

    while(d>0){
        b = par[b];
        d--;
    }

    if(a==b) return a;

    while(par[a]!=par[b] && par[a]!=-1 && par[b]!=-1){
        a = par[a], b = par[b];
    }
    return par[a];
}

int main()
{
    ll n,e;
    cin>>n>>e;

    for(ll i=0;i<e;i++){
        ll x,y;
        cin>>x>>y;
       // x--,y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }    
    dfs(0,0,-1); 

    ll q; cin>>q;

    while(q--){
        ll xx,yy;
        cin>>xx>>yy;
        //xx--,yy--;
        cout<<LCA(xx,yy)<<endl;
    }
}
/*
8 7
1 2
1 3
2 4
2 5
3 6
3 7
4 8
3
2 4
4 7
8 5
*/