
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
ll par[200200][20]; // par[n+1][mxn]
ll dad[200200];
ll dis[200200];
ll n,e;
ll mxn;
void dfs(ll x, ll d, ll p){
    dis[x]=d;
    par[x][0]=p; 

    for(ll i=0;i<graph[x].size();i++){
       ll child = graph[x][i];
       if(child!=p){
         dfs(child,d+1,x);
       } 
    }
}

void init(){
    dfs(0,0,-1);

   // memset(par,-1,sizeof(par));

    for(int j=1;j<=mxn;j++){
        for(int i=1;i<=n;i++){
            if(par[i][j-1]!=-1){
                int parent = par[i][j-1];
                par[i][j] = par[parent][j-1];
            }
        }
    }
}

ll LCA(ll a, ll b){
    if(dis[a]>dis[b]){
        swap(a,b);
    }

    ll d = dis[b]-dis[a];

    while(d){
        ll i = log2(d);
        b = par[b][i];
        d-=(1<<i);
    }

    if(a==b) return a;
    
    for(ll i=mxn; i>=0;i--){
        if(par[a][i]!=-1 && (par[a][i]!=par[b][i])){
            a = par[a][i], b = par[b][i];
        }
    }
    return par[a][0];
    
}


int main()
{
    cin>>n;
    mxn = log2(n);
    
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=mxn;j++){
            par[i][j]=-1;
        }
    }
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        //x--,y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }    
    init();

    ll q; cin>>q;

    while(q--){
        ll xx,yy;
        cin>>xx>>yy;
        //xx--,yy--;
        cout<<LCA(xx,yy)<<endl;
    }
}
/*
7 
0 2
0 4
1 4
2 3
4 5
2 6
3
3 6
5 1
2 4
*/