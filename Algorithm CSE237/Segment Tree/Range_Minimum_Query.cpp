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
#define inf      INT_MAX
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
 
     st[si] = min(st[2*si],st[2*si+1]);
}
 
int query(int si, int ss, int se, int qs, int qe){
     if(ss > qe || se < qs) return inf;
 
     if(ss >= qs && se <= qe) return st[si]; 
 
     int mid = (ss+se)/2;
     
     int segmentLeft = query(2*si, ss ,mid , qs , qe);
     int segmentRight = query(2*si+1, mid+1, se, qs, qe);
 
     return min(segmentLeft,segmentRight); 
}
int main()
{
  int n,q,l,r;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
 
  build(1,1,n);
  cin>>q;
 
  while(q--){
      cin>>l>>r;
      cout<<query(1,1,n,l+1,r+1)<<endl; 
  }
} 