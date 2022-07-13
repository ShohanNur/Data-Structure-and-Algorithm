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
#define inf      1e12
#define mod      1000000007
#define MXN      1000001
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;

int gcd(int a, int b, int &x, int &y){
   if(b==0){
      x = 1;
      b = 0;
      return a;
   }

   int x1,y1;
   int d= gcd(b,a%b,x1,y1);

   x = y1;
   y = x1-y1*(a/b);

   return d;
}

bool find_any_solution(int a, int b, int c, int &x, int &y){
   int x0, y0;
   int g = gcd(abs(a),abs(b),x0,y0);

   if(c%g){
      return 0;
   }

   if(a<0) x=-x;
   if(b<0) y=-y;

   return 1;
}
int main(){
     test{
    int a,b,c,x,y;
    cin>>a>>b>>c;

    if(find_any_solution(a,b,c,x,y)==false){
      cout<<"No sol\n";
    }
    else{
      cout<<"x = "<<x<<" , "<<"y = "<<y<<endl;
    }
}
}

/*

2
2 3 6
81 57 18
*/