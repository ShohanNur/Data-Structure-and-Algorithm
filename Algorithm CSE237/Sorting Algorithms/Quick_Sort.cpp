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
#define sz       1000

typedef long long ll;

using namespace std;

int partition(int arr[],int left, int right)
{
    bool r = true;
    while(left<right)
    {
        if(arr[left]>arr[right])
        {
            swap(arr[left],arr[right]);
            /*if(r) r = false;
            else
                r = true;
                */
             r^=1;
        }
        if(r) right--;
        else
            left++;
    }
    return right;
    /// return left ( left = right , so we can return any of these 2)
}
void quicksort(int arr[],int left, int right)
{
  if(left >= right) return;

  int pivot = partition(arr,left,right);
  quicksort(arr,left,pivot-1);
  quicksort(arr,pivot+1,right);
}
int main()
{
    int n , arr[sz];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    quicksort(arr,0,n-1);

    cout<<"Sorted Array using Quick sort: \n";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" \n"[i==n-1];
}
/**
12
44 33 11 55 77 90 40 60 99 22 88 66
*/
