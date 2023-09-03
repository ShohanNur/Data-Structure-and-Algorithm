#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MAX
#define MXN      100001
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;




void solve()
{
   ll n; cin>>n;
   ll a[n+1];
   ll mx=0; 
   map<ll,ll>mp;

   for(ll i=0;i<n;i++){
       cin>>a[i];
       mx = max(mx,a[i]);
       mp[a[i]]++;
   }
   

   for(ll i=1;i<=mx;i++){
       mp[i]+=mp[i-1];
   }

   vector<ll>v(n);

   for(int i=n-1;i>=0;i--){
        ll x = a[i];
        mp[x]--;
        v[mp[x]] = x;  
   }

   for(auto i:v){
      cout<<i<<" ";
   }
   cout<<endl;


}
int32_t main()
{
   fastio
   int t = 1;


    //cin>>t;
   while (t--) {
      solve();
   }
}
