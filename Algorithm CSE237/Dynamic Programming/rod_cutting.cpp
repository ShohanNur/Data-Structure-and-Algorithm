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
    int n; cin>>n;

    int price[n+1];

    for(int i=1;i<=n;i++){
         cin>>price[i];
    }

    int dp[n+1];

    dp[0]=0;

    for(int i=1;i<=n;i++){
           int mx = 0;
           for(int j=1;j<=i;j++){

               cout<<price[j]+dp[i-j]<<endl;

               mx = max(price[j]+dp[i-j] , mx);
           }
           cout<<endl;

           dp[i] = mx;
    }

    for(int i=0;i<=n;i++){
          cout<<dp[i]<<" ";
    }
    cout<<endl;
}
int main(){
     fastio 
     int t=1;
  //  cin>>t;
     while(t--){
         solve();
     }
}
/*
4
1 5 8 9
*/