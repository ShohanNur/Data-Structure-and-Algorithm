#include<bits/stdc++.h>

#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1e18
#define endl     '\n'
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define lcm(a,b) a*b/(__gcd(a,b)) 
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       400003
#define MXN      1000001

typedef long long ll;


#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
ll nextSmaller[sz];
ll prevSmaller[sz];
ll prevGreater[sz];
ll nextGreater[sz];

void previousSmallerElement(ll a[],ll n){
    stack<ll>st;

    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(st.empty()){
            prevSmaller[i] = -1;
        }
        else{
            prevSmaller[i] = st.top();
        }
        st.push(i);
    }
}

void nextSmallerElement(ll a[], ll n)
{

 stack<ll> st;
 
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && a[st.top()] >= a[i])
    {
      st.pop();
    }
 
    if (!st.empty())
      nextSmaller[i] = st.top();
    else
      nextSmaller[i] = n;
    st.push(i);
  }
 
}
void nextGreaterElement(ll a[],ll n){
    stack<ll> st;
 
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            st.pop();
        }
 
        if (!st.empty())
            nextGreater[i] = st.top();
        else
            nextGreater[i] = n;
        st.push(i);
    }
}

void previousGreaterElement(ll a[], ll n){
        stack<ll> st;
 
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            st.pop();
        }
 
        if (!st.empty())
            prevGreater[i] = st.top();
        else
            prevGreater[i] = -1;
        st.push(i);
    }
}
void init(){
    memset(nextSmaller,0,sizeof nextSmaller);
    memset(nextGreater,0,sizeof nextGreater);
    memset(prevSmaller,0,sizeof prevSmaller);
    memset(prevGreater,0,sizeof prevGreater);
}

void solve(){
    ll n; cin>>n;
    ll a[n+1];
    for(int i=0;i<n;i++){
          cin>>a[i];
    }
    init();
    nextGreaterElement(a,n);
    nextSmallerElement(a,n);
    previousGreaterElement(a,n);
    previousSmallerElement(a,n);
    
    for(int i=0;i<n;i++){
       cout<<nextSmaller[i]<<" "<<prevSmaller[i]<<" "<<nextGreater[i]<<" "<<prevGreater[i]<<endl;   
    }
}
int main() {
     fastio 
     int t; 
     //cin>>t;
     t=1;
     while(t--){
         solve();
     } 
}