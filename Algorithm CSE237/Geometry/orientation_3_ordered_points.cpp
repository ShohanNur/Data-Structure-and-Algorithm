//https://www.geeksforgeeks.org/orientation-3-ordered-points/
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


int main()
{
    vector<pair<ll,ll>>v;

    for(ll i=0;i<3;i++){
        ll x,y;
        cin>>x>>y;
        v.pb({x,y});
    }

    ll x = (((v[1].s - v[0].s) * (v[2].f-v[1].f)) - ((v[2].s - v[1].s) * (v[1].f - v[0].f)));
    if(x==0){
        cout<<"Collinear\n";
    }
    else if(x>0){
        cout<<"Clockwise\n";
    }
    else{
        cout<<"Counterclockwise\n";
    }
}


/*

Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)
Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)

If  σ > τ, the orientation is clockwise (right turn)

Using above values of σ and τ, we can conclude that, 
the orientation depends on sign of  below expression: 

(y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)

Above expression is negative when σ < τ, i.e.,  counterclockwise
*/