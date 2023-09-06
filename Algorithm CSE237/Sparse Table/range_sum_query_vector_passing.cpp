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
#define  int   long long


int n;
void buildSparseTable(vector<int> &arr, int n, vector<vector<int>> &sparse)
{
    for (int i = 0; i < n; i++)
        sparse[i][0] = arr[i];
 
    /* Build sparse table*/
    for (int m = 1; m < 18; m++)
        for (int i = 0; i <= n - (1 << m); i++)
 
            /* Updating the value of gcd. */
            sparse[i][m] = (sparse[i][m - 1]+
                                 sparse[i + (1 << (m - 1))][m - 1]);
}
 
int query(int L,int R, vector<vector<int>> &sparse)
{
    ll ans=0;
    ll K = log2(n);
    for(int j=K; j>=0; j--){
      if(L + (1 << j) - 1 <= R){
         ans+=sparse[L][j];
         L+=1<<j;
      }
    }
    return ans;
}


void solve()
{
    cin>>n;
    vector<ll>arr(n);

    for(ll i=0;i<n;i++){
    cin>>arr[i];
    }

    vector<vector<int>> sparse(n, vector<int>(18));
    buildSparseTable(arr, n, sparse);
    
    ll q; cin>>q;

    while(q--){
          int l,r;
          cin>>l>>r;

          cout<<query(l-1,r-1,sparse)<<endl;
    }
}
int32_t main()
{
   fastio
   int t = 1;


   cin>>t;
   while (t--) {
      solve();
   }
}
/*
1
5
1 2 4 1 12
3
1 2
2 3
2 4
*/