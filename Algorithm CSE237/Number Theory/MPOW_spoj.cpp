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
#define inf      1e
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)
 
typedef long long ll;
using namespace std;
#define N 101
ll a[N][N],I[N][N];
void mul(ll a[][N],ll b[][N], ll dim){
	 ll res[dim+1][dim+1];
	 for(ll i=0;i<dim;i++){
	 	for(ll j=0;j<dim;j++){
	 		res[i][j]=0; 
	 		for(ll k=0;k<dim;k++){
	 			res[i][j] = ((res[i][j]%mod) + (a[i][k]%mod * b[k][j]%mod)%mod)%mod; 
	 		}
	 	}
	 } 
	 for(ll i=0;i<dim;i++){
	 	for(ll j=0;j<dim;j++){
	 		a[i][j] = res[i][j];
	 	}
	 } 
}
void power(ll a[][N], ll dim , ll n){
	 for(ll i=0;i<dim;i++){
	 	for(ll j=0;j<dim;j++){
	 	if(i==j){ I[i][j] = 1;}
	 	else    { I[i][j] = 0;}
	 }
	}
	 // for(ll i=0;i<n;i++){
	 // 	mul(I,a,dim); 
	 // }
	 while(n){
	 	if(n%2){
	 		mul(I,a,dim),n--;
	 	}
	 	else
	 		mul(a,a,dim),n/=2;
	 }
	 for(ll i=0;i<dim;i++){
	 	for(ll j=0;j<dim;j++){
	 		a[i][j] = I[i][j];
	 	}
	 }
}
void printMat(ll a[][N], ll dim){
	for(ll i=0;i<dim;i++){
		for(ll j=0;j<dim;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
   int t; cin>>t;
   ll dim,n;
 
   while(t--){
   	   cin>>dim>>n;
   	   for(ll i=0;i<dim;i++){
   	   	for(ll j=0;j<dim;j++){
   	   		cin>>a[i][j];
   	   	}
   	   }
   	   power(a,dim,n);
   	   printMat(a,dim); 
   }
} 