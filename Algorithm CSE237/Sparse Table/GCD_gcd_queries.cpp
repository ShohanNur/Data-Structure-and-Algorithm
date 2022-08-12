https://codeforces.com/gym/390737/problem/D

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
//int arr[N];

void build(int arr[], int N)
{
    for(int i=0;i<N;i++)
    table[i][0]=arr[i];

    for(int j=1;j<=K;j++)
    {
        for (int i = 0; i + (1 << j) <= N; i++)
        table[i][j] = __gcd(table[i][j-1],table[i + (1 << (j - 1))][j - 1]);
    }
}
int query(int L,int R)
{
    int j = log2(R-L+1);
    int minimum =__gcd(table[L][j], table[R-(1 << j) + 1][j]);
    return minimum;
}

int main(){
   fastio 
   test{ 

   // memset(arr,0,sizeof arr);

    int n; cin>>n;

    int arr[n+1];

    for(ll i=0;i<n;i++){

    cin>>arr[i];
  }
  sort(arr,arr+n);

  build(arr, n);
  
  for(int i=0;i<n;i++){
      int x = i+1;

      if(x%2==0){
        cout<<query((x-1)/2, n-(x/2)-1)<<" ";
      }
      else{
        cout<<query(x/2, n-(x/2)-1)<<" ";

      }
  }
  cout<<endl;
  }
}
/*
2
3
12 8 30
2
5 7

*/