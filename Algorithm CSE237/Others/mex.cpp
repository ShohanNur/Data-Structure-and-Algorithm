#include<bits/stdc++.h>
#define   ll    long long
using namespace std;


void solve(){
   int t; cin>>t; while(t--){
     set<ll>st;
     multiset<ll>mst;

     map<ll,ll>mp;

     for(ll i=0;i<=1000;i++){
         st.insert(i);
     }

     ll n; cin>>n;
     ll a[n+1];

     ll mx=0;
     for(ll i=1;i<=n;i++){
        cin>>a[i];
        mx = max(mx,a[i]);
        if(st.find(a[i])!=st.end()){
            st.erase(a[i]);
            mp[a[i]]++;
            mst.insert(a[i]);
        }
     }
     mx++;

     if(st.find(mx)!=st.end()){
        st.erase(mx);
        mp[mx]++;
        mst.insert(mx);
     }

     // auto value = st.begin();
     cout<<mx<<endl;
     ll x;
     while(1){
        cin>>x;
        if(x==-1){
             return ;
        }
        if(mp[x]>1){
               mp[x]--;
          }
          else if(mp[x]==1){
              mp[x]--;
              st.insert(x);
          }
         auto ans = st.begin();
         cout<<*ans<<endl;

        if(st.find(*ans)!=st.end()){
        st.erase(*ans);
        mp[*ans]++;
        mst.insert(*ans);
     }
     }
  }
}
int main(){
   int t = 1;
   cin>>t;
   while(t--){
      solve();
   }
}
