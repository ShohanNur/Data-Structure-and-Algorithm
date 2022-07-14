
//https://medium.com/nybles/sparse-table-f3981fbb1bc8
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


const int N=1e5;
const int K=log2(N);
int table[N][K+1];
int arr[N];

void build()
{
    for(int i=0;i<N;i++)
    table[i][0]=arr[i];

    for(int j=1;j<=K;j++)
    {
        for (int i = 0; i + (1 << j) <= N; i++)
        table[i][j] = min(table[i][j-1],table[i + (1 << (j - 1))][j - 1]);
    }
}
int query(int L,int R)
{
    int j = log2(R-L+1);
    int minimum =min(table[L][j], table[R-(1 << j) + 1][j]);
    return minimum;
}

int main(){
    ll n; cin>>n;
    for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  build();

  ll q,l,r;

  cin>>q;

  while(q--){
    cin>>l>>r;
    if(l>r){
        swap(l,r);
    }
    cout<<query(l,r)<<endl;
  }
}
/*
7
1 6 -1 5 3 1 0
3
3 6
6 2
3 5
*/