#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MAX
#define MXN      500001
#define endl     "\n"
#define eps      1e-6
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;



void buildSparseTable(vector<int> &arr, int n, vector<vector<int>> &sparse)
{
    for (int i = 0; i < n; i++)
        sparse[i][0] = arr[i];
 
    for (int m = 1; m < 18; m++)
        for (int i = 0; i <= n - (1 << m); i++)
 
            sparse[i][m] = (sparse[i][m - 1] & sparse[i + (1 << (m - 1))][m - 1]);
}
 
/* Query Processed */
int query(int L, int R, vector<vector<int>> &sparse)
{
    int m = (int)log2(R - L + 1);
    return (sparse[L][m] & sparse[R - (1 << m) + 1][m]);
}

void solve()
{
     int n,k; cin>>n>>k;
     vector<int>a(n);

     for(int i=0;i<n;i++){
          cin>>a[i];
     }
    vector<vector<int>> sparse(n, vector<int>(18));
    buildSparseTable(a, n, sparse);   
    

    int ans=0;
    
  
    for(int i=0;i<n;i++){
          
         int left = i;
         int right = n-1;
         int leftmost=-1;
         while(left<=right){
              int mid = (left+right)/2;

              int val = query(i,mid,sparse);

              if(val<=k){
                  if(val==k){
                      leftmost = mid;
                  }   
                  right = mid-1;
              }
              else{
                  left = mid+1;
              }
         }

         if(leftmost==-1){
              continue;
         }

         left = i;
         right = n-1;
         int rightmost = -1;

         while(left<=right){
              int mid = (left+right)/2;

              int val = query(i,mid,sparse);

              if(val>=k){
                  if(val==k){
                     rightmost = mid;
                  }
                  left = mid+1;
              }
              else{
                  right = mid-1;
              }
         }

         if(rightmost==-1){
             continue;
         }
         ans+=(rightmost-leftmost+1);
    } 
    cout<<ans<<endl;
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
