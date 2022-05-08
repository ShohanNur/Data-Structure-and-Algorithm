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
#define inf      1e18
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;

using namespace std;


void merge(vector<int>&arr,int st, int en, int mid)
{
    vector<int>temp(arr.size());

    int i,j;
    for(i=0;i<arr.size();i++)
        temp[i] = arr[i];

    int n= mid - st + 1, m = en - mid ; ///m = en - (mid+1)+1 => m = en -mid-1+1
    int k = st;

    i = j = 0;
    while(i<n && j<m)
    {
        if(temp [st+i] <= temp[mid+1+j])
            arr[k++] = temp [st + i++];
        else
            arr[k++] = temp[mid+1+j++];
    }
    while(i<n)
        arr[k++] = temp [st+i++];
    while(j<m)
        arr[k++] = temp [mid+1+j++];
}
void mergesort(vector<int>&arr, int st, int en)
{
    /*int mid = (st+en/2);*/
    if(st>=en) return;
    int mid = ((st+en)>>1);
    mergesort(arr,st,mid);
    mergesort(arr,mid+1,en);
    merge(arr,st,en,mid);
}
int main()
{
   
    int n;
    cin>>n;
   vector<int>v(n);

   for(int i=0;i<n;i++)
    cin>>v[i];

   mergesort(v,0,n-1);

   for(int i=0;i<n;i++)
    cout<<v[i]<<" \n"[i==n-1];
 
  

}
/**
15
98 -87 -9 0 45 345 4 323 21 12 -312 88 -999 6 9
*/
