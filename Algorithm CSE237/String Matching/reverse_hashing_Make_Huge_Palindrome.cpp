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
#define MAX      1000002

typedef long long ll;
using namespace std;


ll Hash1[MAX], Pow1[MAX];
const ll Base1=1231;
const ll Mod1=1e9+7;
string s;
int n;
void PowerGenerate1(ll n)
{
     Pow1[0]=1;
     for(int i=1 ; i<=n ; i++)
     {
       Pow1[i]=(Pow1[i-1]*Base1)%Mod1;
     }

}

void GenerateHash1(string text)
{
       Hash1[0]=0;

       for(int i=1 ; i<=text.size() ; i++) //1 base indexing for string
       {
           Hash1[i] = ( (Hash1[i-1]*Base1)%Mod1 + (text[i-1]-'a'+1) ) % Mod1;
       }

}

ll GetHash1(int Left , int Right)
{
      ll HashValue = (Hash1[Right] - (Hash1[Left-1]*Pow1[Right-Left+1])%Mod1)%Mod1 ; //Here pow is base^mod
      HashValue+=Mod1;
      HashValue%=Mod1;

      return HashValue;

}

ll PatternHash1(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = ( (x*Base1)%Mod1 + (pattern[i-1]-'a'+1))%Mod1;
      x+=Mod1;
      x%=Mod1;
     return x;
}


ll Hash2[MAX], Pow2[MAX];
const ll Base2=1231;
const ll Mod2=1e9+7;

void PowerGenerate2(ll n)
{
     Pow2[0]=1;
     for(int i=1 ; i<=n ; i++)
     {
       Pow2[i]=(Pow2[i-1]*Base2)%Mod2;
     }

}

void GenerateHash2(string text)
{
       Hash2[0]=0;

       for(int i=1 ; i<=text.size() ; i++) //1 base indexing for string
       {
           Hash2[i] = ( (Hash2[i-1]*Base2)%Mod2 + (text[i-1]-'a'+1) ) % Mod2;
       }

}

ll GetHash2(int Left , int Right)
{
      ll HashValue = (Hash2[Right] - (Hash2[Left-1]*Pow2[Right-Left+1])%Mod2)%Mod2 ; //Here pow is base^mod
      HashValue+=Mod2;
      HashValue%=Mod2;

      return HashValue;

}

ll PatternHash2(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = ( (x*Base2)%Mod2 + (pattern[i-1]-'a'+1))%Mod2;
     
      x+=Mod2;
      x%=Mod2;
     return x;
}



ll k=0;
int main()
{          ios::sync_with_stdio(false);
          cin.tie(0);

         test{
          cout<<"Case "<<++k<<": ";
          string text,pattern;
          cin>>text;
          PowerGenerate1(text.size());
          GenerateHash1(text);
         // ll x =  PatternHash1(text);
         // cout<<x<<" x "<<endl;
          //ll len = pattern.size();
          // ll y = GetHash1(1,5);

          bool ok=0;
          string text2 = text;

          reverse(text2.begin(),text2.end());

          PowerGenerate2(text2.size());
          GenerateHash2(text2);
         // ll y =  PatternHash2(text2);
         // cout<<y<<" x "<<endl;

          ll j=text.size();
          ll jj = 1;
          ll cnt=0;
          ll mx=0;
          for(ll i=text.size();i>=1;i--){
             ll val1 = GetHash1(i,j);
             ll val2 = GetHash2(1,jj);    
             //j++;
             jj++;
             cnt++;
            // cout<<val1<<" "<<val2<<endl;

             if(val1==val2){
                mx=  max(mx,cnt);
            }
          }
          ll siz = 2*(text.size()-mx); 
          cout<<mx+siz<<endl; 

    } 
}

/*
4
bababababa
pqrs
madamimadam
anncbaaababaaa
*/