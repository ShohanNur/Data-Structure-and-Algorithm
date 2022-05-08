#include<bits/stdc++.h>
using namespace std;
#define sz       200000
#define ll       long long
#define pb       push_back
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define mod      1000000007
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
///process 1

int b_search(int a[],int n,int k){
  int low =0;
  int high=n-1;
  int mid;
  while(low<=high){
    mid = low+(high-low)/2;
    ///mid = (low+high)/2; condition will be: while(low<=high)
    ///mid = (low+high+1)/2; condition will be: while(low<high)
    if(a[mid]==k){
      return mid;
    }
    if(a[mid]<k){
      low = mid+1;
    }
    if(a[mid]>k){
      high = mid-1;
    }
  }
  return 0;
}

///process 2


int main()
{
  int n,k;
  cin>>n>>k;
  int a[n+1];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  if(b_search(a,n,k)==0) cout<<"No Solution "<<endl;
  else 
    cout<<b_search(a,n,k)<<endl;
}
