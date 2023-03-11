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

int dp[100][100];
void solve(){

    int n; cin>>n;
    string s; cin>>s;
    
    s='*'+s;
    for(int i=0;i<=n;i++){
        dp[0][i]=dp[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s[j]==s[j-i+1] && dp[i-2][j-1]==1){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
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
/*
4 12
2 5 3 4
*/