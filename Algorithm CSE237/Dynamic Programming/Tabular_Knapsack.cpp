// iterative knapsack ( Top Down Approach)
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


ll dp[202][2002];

void solve()
{
    ll n,W;
    cin>>n>>W;

    ll weight[n+1];
    ll price[n+1];

    for(ll i=0;i<n;i++){
         cin>>weight[i];
    }
    for(ll i=0;i<n;i++){
         cin>>price[i];
    }
    
    for(int i=0;i<=n;i++){
         for(int j=0;j<=W;j++){
              if(i==0 or j==0){
                 dp[i][j] = 0;
              }
         }
    }
    
    for(int i=1;i<=n;i++){
          for(int j=1;j<=W;j++){
              if(weight[i-1]<=j){
                dp[i][j] = max(dp[i-1][j] , price[i-1] + dp[i-1][j-weight[i-1]]);
              }
              else{
                dp[i][j] = dp[i-1][j]; 
              }
          }
    }

    cout<<dp[n][W]<<endl;
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

/*
3 50
10 20 30
60 100 120
*/