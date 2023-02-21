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


int dp[10000001];

int ok(int n){

    if(n==0){
        return 1;
    }
    if(n<=2){
        return n;
    }

    if(~dp[n]){
        return dp[n];
    }

    return dp[n] = ok(n-1)+ok(n-2);

}
void solve(){   
  int n; cin>>n;

  memset(dp,-1,sizeof dp);
  cout<<ok(n);

 // cout<<dp[n]<<endl;
}
int main(){
     fastio 
     int t=1;
     cin>>t;
     while(t--){
         solve();
     }
}
/*
4 12
2 5 3 4
*/