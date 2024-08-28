#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1000000000000000LL
#define MXN      500001
#define endl     "\n"
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
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
   ll n; cin>>n;

   ll a[n+1];
   for(ll i=1;i<=n;i++){
      cin>>a[i];
   } 

   ll cum[n+1]={};

   ll q; cin>>q;


   for(ll i=1;i<=q;i++){
        ll l,r;
        cin>>l>>r;
        
        cum[l]++;
        cum[r+1]--;  
   }

   for(ll i=1;i<=n;i++){
       cum[i]+=cum[i-1];
   }

   for(ll i=1;i<=n;i++){
       cout<<cum[i]<<" ";
   }
   cout<<endl;
}
int32_t main()
{
   fastio
   int t = 1;


   cin>>t;
   while (t--) {
      solve();
   }
}

/*
1
5 
1 2 3 4 5
3
1 3
2 4
1 5
*/