#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      INT_MIN
#define  N      100001
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;

int a[N];
int n, q;
 
struct BIT {
 
    long long M[N], A[N];
    BIT() {
        memset(M, 0, sizeof M);
        memset(A, 0, sizeof A);
    }
    void update(int i, long long mul, long long add)
    {
        while (i < N)
        {
            M[i] += mul;
            A[i] += add;
            i |= (i + 1);
        }
    }
    void upd(int l, int r, long long x)
    {
        update(l, x, -x * (l - 1));
        update(r, -x, x * r);
    }
    long long query(int i)
    {
        long long mul = 0, add = 0;
        int st = i;
        while (i >= 0)
        {
            mul += M[i];
            add += A[i];
            i = (i & (i + 1)) - 1;
        }
        return (mul * st + add);
    }
    long long query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
} t;
 

void solve()
{
    cin >> n >> q;
  
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        t.upd(i , i, a[i]);
    }

    for(int i=0;i<q;i++){
          ll code;
          cin>>code;

          if(code==1){
              ll x,val; cin>>x>>val;
              t.upd(x,x,val);

          }
          else{
              ll l,r; cin>>l>>r;

              cout<<t.query(l,r)<<endl;
          }
    }
}
int32_t main()
{
    fastio
    int t = 1;
  //  cin>>t;

    while (t--) {
        solve();
    }
}
/*
7 6
6 4 1 10 3 2 4
2 1 7
2 4 5
1 3 5
2 4 4
1 5 7
2 1 7
*/