#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MAX
#define MXN      200001
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;


ll n,m,q;
 
int query(int si, int ss, int se, int qs, int qe,int a[], int st[], int lazy[]){

     if(lazy[si]!=0){
        int x = lazy[si];
        lazy[si] = 0;
        st[si]+=x*(se-ss+1);

        if(ss!=se){
          lazy[2*si]+=x,lazy[2*si+1]+=x;
        }
     } 
     if(ss > qe || se < qs) return 0;
 
     if(ss >= qs && se <= qe) return st[si]; 
 
     int mid = (ss+se)/2;
     
     int segmentLeft = query(2*si, ss ,mid , qs , qe,a,st,lazy);
     int segmentRight = query(2*si+1, mid+1, se, qs, qe,a,st,lazy);
 
     return (segmentLeft+segmentRight); 
}
void update(int si, int ss, int se, int qs,int qe, int val,int a[], int st[], int lazy[]){
   
     if(lazy[si]!=0){
        int x = lazy[si];
        lazy[si] = 0;
        st[si]+=x*(se-ss+1);

        if(ss!=se){
          lazy[2*si]+=x,lazy[2*si+1]+=x;
        }
     } 
   if(ss > qe || se < qs) return;
   if(ss>=qs && se<=qe){
      int x = (se-ss+1)*val;

      st[si]+=x;

      if(ss!=se){
        lazy[2*si]+=val, lazy[2*si+1]+=val;
      }
        return;
      
   }

     int mid = (ss+se)/2;

   
     update(2*si, ss , mid , qs ,qe,val,a,st,lazy);
     update(2*si+1, mid+1, se , qs ,qe, val,a,st,lazy);
  

   st[si] = (st[2*si]+st[2*si+1]);

}

bool ok(ll k , vector<pair<pair<ll,ll>,ll>>&v, vector<ll>&vv){
         int a[n+1];
         int st[4*n+1];
         int lazy[4*n+1]; 
         memset(st,0,sizeof st);
         memset(a,0,sizeof a);
         memset(lazy,0,sizeof lazy);

         for(int i=0;i<=k;i++){
              update(1,1,n,vv[i],vv[i],1,a,st,lazy);
         }

         for(int i=0;i<m;i++){
              ll l = v[i].f.f;
              ll r = v[i].f.s;

              ll val = v[i].s;

              if(query(1,1,n,l,r,a,st,lazy)>=val){
               return 1;
              }
         }
         return 0;
}
void solve()
{
   cin>>n>>m;

   vector<pair<pair<ll,ll>,ll>>v;

   for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;

        ll r = (y-x+1); 

        if(r%2==0){
            ll l = (r/2)+1;
            v.pb({{x,y},l});
        }
        else{
            ll l = (r+1)/2 ;
            v.pb({{x,y},l});  
        }
   }
   cin>>q;
   vector<ll>vv;
   for(int i=0;i<q;i++){
       ll x;
       cin>>x;
       vv.pb(x);
   }
   ll ans=-1;

   ll low = 0;
   ll high = vv.size()-1;

   while(low<=high){
       ll mid = (low+high)/2;

       if(ok(mid,v,vv)){
           ans = mid+1;
           high = mid-1;
       }
       else{
           low = mid+1; 
       }
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
