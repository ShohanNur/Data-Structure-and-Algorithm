//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/sum-of-numbers-9/
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
   
   int n,m; cin>>n;

   int a[n+1];

   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   cin>>m;
   for(int mask=0;mask<(1<<n);mask++){
           vector<int>v;

       for(int i=0;i<n;i++){
           if((mask&(1<<i))){
             //cout<<a[i]<<" ";
            v.pb(a[i]);
           } 
        }
        int x = accumulate(v.begin(), v.end(), 0);
           if(x==m){
            cout<<"YES\n"; return;
           }
   } 
   cout<<"NO\n";
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

4 
2 5 3 4

*/