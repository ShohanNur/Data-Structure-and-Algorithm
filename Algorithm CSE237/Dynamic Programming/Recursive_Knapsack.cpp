// Recursive knapsack with memoization 
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

ll knapsack(ll weight[], ll price[] , ll n , ll W){

   if(n==0 or W==0){
       return 0ll;
   }
   if(~dp[n][W]){
       return dp[n][W];
   }
   if(weight[n-1]<=W){
       return dp[n][W] = max((price[n-1]+ knapsack(weight,price,n-1,W-weight[n-1])),knapsack(weight,price,n-1,W));
   }
   else{
       return dp[n][W] = knapsack(weight,price,n-1,W); 
   }

}
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
    memset(dp,-1,sizeof dp);
    cout<<knapsack(weight,price,n,W)<<endl;


}
int32_t main()
{
   fastio
   int t = 1;


  // cin>>t;
   while (t--) {
      solve();
   }
}

/*
3 50
10 20 30
60 100 120
*/