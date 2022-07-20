#include<bits/stdc++.h>

#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1e18
//#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;

ll Pow[200200];
ll Hash[200200];

const ll base = 1231;
const ll mod = 1000000007;
void power(ll n){
   Pow[0] = 1;
   for(ll i=1;i<=n;i++){
      Pow[i]  = (Pow[i-1]*base)%mod;
   }
}

void generateHash(string text){
    Hash[0]=0;

    for(int i=1;i<=text.size();i++){
        Hash[i] = ((Hash[i-1]*base)%mod + text[i-1]-'a'+1)%mod;
        Hash[i]+=mod;
        Hash[i]%=mod;
    }
}
ll patternHash(string pattern){
   ll x = 0;

   for(int i=1;i<=pattern.size();i++){
       x  =  ((x*base)%mod + pattern[i-1]-'a'+1)%mod;
   }
   x+=mod;
   x%=mod;

   return x;
}
ll getHash(ll left , ll right){

     ll x = (Hash[right] - (Hash[left-1]*Pow[right-left+1])%mod)%mod;

     x+=mod;
     x%=mod;

     return x;

}
int main(){
     string text, pattern;

     cin>>text>>pattern;

     power(text.size());
     ll x = patternHash(pattern);

     generateHash(text);
    
     //cout<<getHash(3,4)<<endl;
     for(int i=1;i<=text.size()-pattern.size()+1;i++){
          ll val = getHash(i,pattern.size()+i-1);
          if(val == x){
            cout<<"found at "<<i<<endl;
          }
         // cout<<val<<" "<<x<<endl; 
     }


}