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
#define inf      1e9
#define endl     '\n'
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
#define sz       100003

typedef long long ll;

using namespace std;
using namespace std::chrono;
int n; 

struct Point
{
    int x, y;
};

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    return (val >= 0)? 1: 0; 
}

void convexHull(vector<Point>&points)
{
  
    if (n < 3) return;
 
    vector<Point> res;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
 

    int p = l, q;
 
     while(1){

        res.push_back(points[p]);
 
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
   
           if (orientation(points[p], points[i], points[q]) == 0)
               q = i;
        }

        p = q;
        if(p==l) break;
       }


    for (int i = 0; i < res.size(); i++)
        cout << "(" << res[i].x << ", "
              << res[i].y << ")\n";
}

int main(){
   cin>>n;
   vector<Point>v;
   Point p;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    p.x = x;
    p.y = y;
    v.pb(p);
  }
  convexHull(v);
}