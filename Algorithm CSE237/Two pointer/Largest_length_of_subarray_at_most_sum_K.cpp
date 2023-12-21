#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MAX
#define MXN      500001
#define endl     "\n"
#define eps      1e-6
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
   ll n,k;
   cin>>n>>k;

   ll a[n+1];

   for(ll i=1;i<=n;i++){
      cin>>a[i];
   } 

   ll mx=0;
   ll left=1,right=1;
   ll ans=0;
   
   while(left<=n and right<=n){

         ans+=a[right++];
         while(ans>k){
             ans-=a[left++];
         }
         mx = max(mx,right-left);  

   }

   cout<<mx<<endl;
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
