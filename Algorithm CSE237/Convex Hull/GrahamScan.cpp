
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <chrono>
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
#define inf      1e18
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;

using namespace std;
using namespace std::chrono;
int n,m;


class Point{
 public: 
    int x,y; 

    bool operator <(Point b){
    	if(y!=b.y){
    		 return y<b.y;
    	}
    	else{
    		return x<b.x;
    	}
    }	
};

vector<Point>v;
stack<Point>hull;
Point pivot;

int  ccw(Point A, Point B, Point C){
	 int val = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);

	 if(val==0) return 0; // collinear
	 else if(val<0) return -1; //cw
	 else return 1; // ccw
}


int  sqD(Point A, Point B){
	int X = (A.x - B.x) ,  Y = (A.y - B.y);

	return X*X+Y*Y; 
}
bool POLAR_ORDER(Point A, Point B){
    int order = ccw(pivot, A, B);
    if(order == 0 ){
    	return sqD(pivot,A) < sqD(pivot,B);
    }
    return (order==1);
}
void grahamScan(){
	  if(n<3) return ;
      
      int l =0;

      for(int i=1;i<n;i++){
      	  if(v[i]<v[l]){
      	  	l = i;
      	  }
      }
      
     // swap(v[0],v[l]);
      Point temp = v[0];
      v[0] = v[l];
      v[l] = temp;

      pivot = v[0];

      sort(v.begin()+1, v.end() , POLAR_ORDER);
      hull.push(v[0]);
      hull.push(v[1]);
      hull.push(v[2]);

      for(int i=3;i<n;i++){
      	  Point top = hull.top();
      	  hull.pop();

      	  while(ccw(hull.top(),top,v[i])!=1){
      	  	top = hull.top();
      	  	hull.pop();
      	  }
      	  hull.push(top);
      	  hull.push(v[i]);
      }
     
     while(!hull.empty()){
     	  Point P;
     	  P = hull.top();
     	  hull.pop();
           
     	  cout<<P.x<<" "<<P.y<<endl;
     }

}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
    	 int x,y;
    	 cin>>x>>y;
    	 Point p;
    	 p.x = x;
    	 p.y= y;
    	 v.pb(p);
    }
    
   grahamScan();
}