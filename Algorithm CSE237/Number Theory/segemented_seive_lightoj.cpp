#include<bits/stdc++.h>
using namespace std;
#define ll       long long int
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1e
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)


vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    vector<ll>vv;
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;

    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
ll k;
int main(){
    test{
    ll l,r;
    cin>>l>>r;
    vector<char>vec;
    vec = segmentedSieve(l,r);

    ll cnt=0;

    for(ll i=0;i<vec.size();i++){
        ll x = (ll)vec[i];
        if(x==1){
          cnt++;
        }   
    }

    cout<<"Case "<<++k<<": ";
    cout<<cnt<<endl;
   }
}