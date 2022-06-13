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
#define inf      100000000000000
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;
 
const int N = 90000003;
 vector<int>Prime;
bool prime[N+5];
void seive()
{
 
    int i, j;
    prime[0]=true;
    prime[1]=true;
    for(i=4; i<=N; i+=2)
    {
        prime[i]=true;
    }
    for(i=3; i*i<=N; i+=2)
    {
        if(!prime[i])
        {
            for(j=i*i; j<=N; j+=i)
            {
                prime[j]=true;
            }
        }
    }
 
    for(ll i=0;i<=N;i++)
    {
        if(prime[i]==0)
        {
            Prime.pb(i);
        }
    }
  
 
}
int main(){
	fastio
    seive();
    test{
        int n;
        cin>>n;
        cout<<Prime[n-1]<<endl;
    }
}  