#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1000000000000000LL
#define MXN      1001
#define endl     "\n"
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define eps      1e-6
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;


vector<ll> st[4*MXN];
ll a[MXN];

void build(int si, int ss, int se){
     if(ss==se){
         st[si].pb(a[ss]);
         return;
     }

     ll mid = (se+ss)/2;

     build(2*si, ss, mid);
     build(2*si+1,mid+1,se);

     int i=0;
     int j=0;

     while(i< st[2*si].size() and j<st[2*si+1].size()){
         if(st[2*si][i] <= st[2*si+1][j]){
            st[si].pb(st[2*si][i]);
            i++;
         }
         else{
            st[si].pb(st[2*si+1][j]);
            j++;
         }
     }

     while(i < st[2*si].size()){
          st[si].pb(st[2*si][i]);
          i++;
     }
     while(j < st[2*si+1].size()){
          st[si].pb(st[2*si+1][j]);
          j++;
     }

}

int query(int si, int ss, int se, int qs, int qe, int k){
      if(ss > qe or se < qs){
          return 0;
      }

      if(ss >= qs and se <= qe){
          int res = lower_bound(st[si].begin(),st[si].end(),k) - st[si].begin();
          return res;
      }

      ll mid = (ss+se)/2;
      ll l = query(2*si, ss, mid, qs, qe, k);
      ll r = query(2*si+1, mid+1,se, qs, qe,k);

      return l+r;
}     



void solve()
{
     ll n,q,l,r,k;

     cin>>n>>q;

     for(ll i=1;i<=n;i++){
          cin>>a[i];
     }

     build(1,1,n);


     while(q--){
           cin>>l>>r>>k;

           cout<<query(1,1,n,l,r,k)<<endl;
     }
}
int32_t main()
{
   fastio
   int t = 1;


   //cin>>t;
   while (t--) {
      solve();
   }
}

/*
5 2
1 2 3 4 5
1 3 2
1 4 4
*/