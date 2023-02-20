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

void solve(){
  int n,m; cin>>n>>m;
  int a[n+1];

  for(int i=1;i<=n;i++){
     cin>>a[i];
  }

  bool dp[m+1]={0};

  dp[0]=1; 

  for(int i=1;i<=n;i++){
      int cur = a[i];

      for(int j=m;j>=1;j--){
          if(dp[j] || dp[j-cur]==0){
            continue;
          }
          else{
            dp[j]=1;
          }
      }
  }

  for(int i=0;i<=m;i++){
     cout<<dp[i]<<" ";
  }
  cout<<endl;
}
int main(){
     fastio 
     //seive();
     int t=1; 
     //cin>>t;
     while(t--){
         solve();
     }
}
/*
4 12
2 5 3 4
*/