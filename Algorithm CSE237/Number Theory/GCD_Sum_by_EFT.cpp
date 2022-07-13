#include <bits/stdc++.h>
using namespace std;
 
 
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MIN
#define mod      1000000007
#define MXN      1000001
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;
// sum of gcd(i,n) 
ll phi[1000001];
void init(){
   for(ll i=1;i<=MXN;i++){
     phi[i] = i;
   }

   for(ll i=2;i<=MXN;i++){
      if(phi[i]==i){
         for(ll j=i;j<=MXN;j+=i){
            phi[j]/=i;
            phi[j]*=(i-1);
         }
      }
   }
}

int getCount(int d, int n){
  return phi[n/d];
}
int main()
{ 
    init();

    test{
       ll n; cin>>n;

       ll res = 0;

       for(int i=1;i*i<=n;i++){
         if(n%i==0){

         int x = i;
         int y = n/i;

          res+= x * getCount(x,n);

         if(x!=y){
           res+= y * getCount(y,n);
         } 
         }
       }
       cout<<res<<endl;
    }
} 