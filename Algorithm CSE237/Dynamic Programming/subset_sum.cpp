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
    int dp[n+2][m+2];
    int a[n+2];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<=n;i++){

        for(int j=0;j<=m;j++){
        if(i==0){
            if(j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }
        }
 
        if(j==0){
            dp[i][j]=1;
        }
      }

    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(j>=a[i-1]){ 
           dp[i][j] = (dp[i-1][j] || dp[i-1][j-a[i-1]]);
           }
           else{
            dp[i][j] = dp[i-1][j];
           }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;



}
int main(){
     fastio 
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