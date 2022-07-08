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
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;
int a[100001],st[400004];
 
void build(int si, int ss, int se){
     if(ss == se){
       st[si] = a[ss];
       return;
     }
     int mid = (ss+se)/2;
     build(2*si,ss,mid);
     build(2*si+1,mid+1,se);
 
     st[si] = max(st[2*si],st[2*si+1]);
}
 
int query(int si, int ss, int se, int qs, int qe){
     if(ss > qe || se < qs) return inf;
 
     if(ss >= qs && se <= qe) return st[si]; 
 
     int mid = (ss+se)/2;
     
     int segmentLeft = query(2*si, ss ,mid , qs , qe);
     int segmentRight = query(2*si+1, mid+1, se, qs, qe);
 
     return max(segmentLeft,segmentRight); 
}
void update(int si, int ss, int se, int qi, int val){
   if(ss == se){
    st[si] = a[ss] = val;
    return;
   }
   int mid = (ss+se)/2;

   if(qi<=mid){
     update(2*si, ss , mid , qi ,val);
   }
   else{
     update(2*si+1, mid+1, se , qi , val);
   }

   st[si] = max(st[2*si], st[2*si+1]);

}
int main()
{
  int n,q,l,r,p,x,y;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
 
  build(1,1,n);
  cin>>q;
 
  cout<<"Before update :\n";
  for(int i=0;i<q;i++){
      cin>>l>>r;
      cout<<query(1,1,n,l+1,r+1)<<endl; 
  }
  cin>>p;
  for(int i=0;i<p;i++){
      cin>>x>>y;

      update(1,1,n,x+1,y);
  }
  cin>>q;
    cout<<"After update :\n";
   for(int i=0;i<q;i++){
      cin>>l>>r;
      cout<<query(1,1,n,l+1,r+1)<<endl; 
  }

} 

/*
5
-1 2 -3 4 5 
3
0 2
1 3
2 4
2
0 32
2 223
3
0 2
1 3
2 4
*/