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

ll __lcm(ll a, ll b){
     return  (a*b/ __gcd(a,b));
}

// for gcd queries
void buildSparseTable(vector<int> &arr, int n, vector<vector<int>> &sparse)
{
    for (int i = 0; i < n; i++)
        sparse[i][0] = arr[i];
 
    /* Build sparse table*/
    for (int m = 1; m < 18; m++)
        for (int i = 0; i <= n - (1 << m); i++)
 
            /* Updating the value of gcd. */
            sparse[i][m] = __gcd(sparse[i][m - 1],
                                 sparse[i + (1 << (m - 1))][m - 1]);
}
 
// for lcm queries

/* Query Processed */
int query(int L, int R, vector<vector<int>> &sparse)
{
    /* The maximum power of range that is less than 2 */
    int m = (int)log2(R - L + 1);
    return __gcd(sparse[L][m], sparse[R - (1 << m) + 1][m]);
}

void buildSparseTable2(vector<int> &arr, int n, vector<vector<int>> &sparse2)
{
    for (int i = 0; i < n; i++)
        sparse2[i][0] = arr[i];
 
    /* Build sparse table*/
    for (int m = 1; m < 18; m++){
        for (int i = 0; i <= n - (1 << m); i++){
 
            /* Updating the value of lcm. */
            sparse2[i][m] = __lcm(sparse2[i][m - 1],
                                 sparse2[i + (1 << (m - 1))][m - 1]);


            if(sparse2[i][m]>10000000) {
                sparse2[i][m] = 0;
            }
         }
    }

}
 
/* Query Processed */
int query2(int L, int R, vector<vector<int>> &sparse2)
{
    /* The maximum power of range that is less than 2 */
    int m = (int)log2(R - L + 1);
    return __lcm(sparse2[L][m], sparse2[R - (1 << m) + 1][m]);
}


ll toleft(ll left, ll right , vector<ll>&a , ll val,  vector<vector<int>> &sparse, vector<vector<int>> &sparse2){
      ll ans = a.size();
      ll st = left; 
      while(left<=right){
           ll mid = left+ (right-left)/2;

           ll gcd = query(st , mid, sparse);
           ll lcm = query2(st, mid , sparse2);

           if(lcm <=0 or (lcm/gcd) >= val){
                ans  = mid;
                right = mid-1;
           }
           else{
                left = mid+1;
           }
      }

      return ans;
}

ll toright(ll left , ll right , vector<ll>&a , ll val , vector<vector<int>> &sparse, vector<vector<int>> &sparse2){
    ll ans = a.size();
      ll st = left; 
      while(left<=right){
           ll mid = left+ (right-left)/2;

           ll gcd = query(st , mid, sparse);
           ll lcm = query2(st, mid , sparse2);

           if(lcm <=0 or (lcm/gcd) > val){
                ans  = mid;
                right = mid-1;
           }
           else{
                left = mid+1;
           }
      }

      return ans;
}

void solve()
{
    ll n,k; cin>>n>>k;
    vector<ll>arr(n);
    
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
// building sparse table for gcd   
    vector<vector<int>> sparse(n, vector<int>(18));
    buildSparseTable(arr, n, sparse);
// building sparse table for lcm
    vector<vector<int>> sparse2(n, vector<int>(18));
    buildSparseTable2(arr, n, sparse2);
    

    ll ans=0; 

    for(int i=0;i<n;i++){
         ll start = toleft(i,n-1,arr,k,sparse,sparse2);
         ll end = toright(i,n-1,arr,k,sparse,sparse2);
         ans+=(end-start);
    }
    cout<<ans<<endl;
    
}
main()
{
   fastio
   int t = 1;


   cin>>t;
   while (t--) {
      solve();
   }
}
