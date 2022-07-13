#include <bits/stdc++.h>
using namespace std;
 
 
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MIN
#define MXN      100001
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;

ll F[1000001];

ll big_mod(ll a, ll n){

    ll res = 1;

    while(n){
        if(n%2){
            res = (res*a)%mod;
        }
        n/=2;

        a = (a*a)%mod;
    }
    return res;
}
ll nCr(ll n, ll k){
     if(k>n) return 0;
     // nCr = n! / (k! * (n-k)! );


     ll res = F[n];  
     // using fermat's little theorem we get inverse modulo of k! and (n-k)!

     res = (res * big_mod(F[k],mod-2))%mod;    // multiplying res by inverse modulo of k! 
     res = (res * big_mod(F[n-k],mod-2))%mod;  // multiplying res by inverse modulo of (n-k)! 
    return res;
}
int main()
{

    // precalculation of n!  
    F[0] = F[1] = 1;
    for(ll i=2;i<=1000000;i++){
       F[i] = (F[i-1] * i)%mod;
    }
    
    int q;
    cin>>q;
    ll n,k;

    while(q--){
         cin>>n>>k;
         cout<<nCr(n,k)<<endl;
    }
} 

/*
5
40000 1212
4 4
5 3
5 2
10 3
*/