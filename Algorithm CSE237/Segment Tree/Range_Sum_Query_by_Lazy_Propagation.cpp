#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>
 
 
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MIN
#define MXN      100001
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;
int a[MXN],st[4*MXN],lazy[4*MXN];
int n,q,code,l,r,val;
 
void build(int si, int ss, int se){
     if(ss == se){
       st[si] = a[ss];
       return;
     }
     int mid = (ss+se)/2;
     build(2*si,ss,mid);
     build(2*si+1,mid+1,se);
 
     st[si] = (st[2*si]+st[2*si+1]);
}
 
int query(int si, int ss, int se, int qs, int qe){

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
     
     int segmentLeft = query(2*si, ss ,mid , qs , qe);
     int segmentRight = query(2*si+1, mid+1, se, qs, qe);
 
     return (segmentLeft+segmentRight); 
}
void update(int si, int ss, int se, int qs,int qe, int val){
   
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

   
     update(2*si, ss , mid , qs ,qe,val);
     update(2*si+1, mid+1, se , qs ,qe, val);
  

   st[si] = (st[2*si]+st[2*si+1]);

}
int main()
{

   cin>>n>>q;

   build(1,1,n);

   for(int i=0;i<q;i++){
      cin>>code;
      if(code==1){
         cin>>l>>r;
         cout<<query(1,1,n,l,r)<<endl;
      }
      else{
         cin>>l>>r>>val;
         update(1,1,n,l,r,val);
      }
   }
} 

/*
5 5
1 1 5
2 1 5 1
2 1 5 1
2 1 5 1
1 1 5


code = 1 means print range sum 
code = 2 means update range 
*/