#include<bits/stdc++.h>

#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1e18
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;
ll a[200100];
ll n;

void merge(ll st, ll mid, ll end){

    ll temp[n+1];

    for(int i=1; i<=n ; i++){
      temp[i] = a[i];
    }

    ll i=st;
    ll j=mid+1;
    ll k=st;


    while(i<=mid && j<=end){
      if(temp[i]>temp[j]){
        a[k++] = temp[j++];
      }
      else{
        a[k++] = temp[i++];
      }
    }

    while(i<=mid){
      a[k++] = temp[i++];
    }
    while(j<=end){
      a[k++] = temp[j++];
    }


}
void mergesort(ll left, ll right){
      if(left>=right) return;

      ll mid = (left+right)/2;

      mergesort(left, mid);
      mergesort(mid+1, right);
      merge(left, mid, right);

}
int main(){

 cin>>n;
  for(int i=1;i<=n;i++){
     cin>>a[i];
  }


  mergesort(1,n);


 for(ll i=1;i<=n;i++){
    cout<<a[i]<<" ";
 }

}