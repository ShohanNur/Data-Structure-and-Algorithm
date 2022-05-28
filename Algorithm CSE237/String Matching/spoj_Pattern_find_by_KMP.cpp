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
#define NIL      -1

typedef long long ll;
using namespace std;


int n,m;

//void buildLPS(string pattern);
void buildLPS(string pattern,int *lps){
    lps[0] = 0;
    int i=1,j=0;
    while(i<m){
        if(pattern[i]==pattern[j]){
            lps[i] = j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void kmp(string text,string pattern){
     n = text.size();
     m = pattern.size();
     
    int lps[m];
    buildLPS(pattern,lps);
    // for(auto i:lps){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    vector<int>v;
    int j=0; // pattern
    int i=0; //text 
    bool flag = 0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            flag = 1;
            //cout<<"Found pattern from index "<<i-j<<" to index "<<(i-j)+m-1<<endl;
            v.pb(i-j+1);

            j = lps[j-1];
        }
        else if(i<n && text[i]!=pattern[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }

    }
    if(!flag){
        cout<<"Not Found"<<endl;
    } 
    else{
        cout<<v.size()<<endl;
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}


int main(){
    test{
    string text;
    cin>>text;
    string pattern;
    cin>>pattern;
    kmp(text,pattern);
 }
    return 0;
}