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
#define    sz     15000005 
 
typedef long long ll;


using namespace std;


void solve(){
   ll n,m; cin>>n>>m;
   ll a[n+1];

   for(int i=1;i<=n;i++){
       cin>>a[i];
   }
   ll dp[m+1]; 
   for(int i=1;i<=m;i++){
      dp[i] = INT_MAX;
   }
   
   dp[0] = 0;

   for(int i=1;i<=m;i++){
      
      for(int j=1;j<=n;j++){
        if(i>=a[j] && dp[i-a[j]]!=INT_MAX){
        dp[i] = min(dp[i],dp[i-a[j]]+1);
       }
     }
   }
   if(dp[m]==INT_MAX){
     cout<<-1<<endl;
   }
   else{
     cout<<dp[m]<<endl;
   }
}
int main(){
     fastio
     int t=1; 
     //cin>>t;
     while(t--){
         solve();
     }
}