
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
   int n; cin>>n;

   int a[n+1];

   int dp[n+1];

   for(int i=1;i<=n;i++){
      cin>>a[i];
      dp[i]=a[i];
   }

   for(int i=1;i<=n;i++){
      for(int j=1;j<i;j++){
          if(a[i]>a[j]){
              dp[i] = max(dp[i] , a[i]+dp[j]);
          }
      }
   }

   for(int i=1;i<=n;i++){
     cout<<dp[i]<<" ";
   }
   cout<<endl;
}   
int32_t main()
{
   fastio 
   int t=1;
  // cin>>t;
   while(t--){
      solve();
   }
   
} 
/*
7
3 4 -1 0 6 2 3
*/