#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1000000000000000LL
#define MXN      500001
#define endl     "\n"
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define eps      1e-6
#define mod      1000000007
#define all(x)   x.begin(), x.end()
#define rev(x)   x.rbegin(),x.rend()
#define spc(x)   cout<<fixed<<setprecision(x)
#define fastio   {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define test     ll t; cin>>t; while(t--)

typedef long long ll;
using namespace std;


struct query
{
    ll l;
    ll r;
    ll i;
};

query Q[200002];
ll freq[1000002];
ll ans[200002];
ll a[200002];
ll BLOCK = 555;
ll cnt = 0;
ll m;
void remove(ll pos) {

    freq[a[pos]]--;
    if (freq[a[pos]] == 0) {
        cnt--;
    }
}

void add(ll pos) {
    freq[a[pos]]++;
    if (freq[a[pos]] == 1) {
        cnt++;
    }
}

bool comp( query a, query b) {
    if (a.l / BLOCK != b.l / BLOCK) {
        return a.l / BLOCK < b.l / BLOCK;
    }

    return a.r < b.r;
}
void solve()
{
    ll n, q;
    cin >> n;


    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i , Q[i].l-- , Q[i].r--;
    }

    sort(Q , Q + q , comp);




    int ML = 0 , MR = -1;
    for (int i = 0; i < q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while (ML > L)
            ML-- , add(ML);

        while (MR < R)
            MR++ , add(MR);

        while (ML < L)
            remove(ML) , ML++;

        while (MR > R)
            remove(MR) , MR--;

        ans[Q[i].i] = cnt;

    }

    for (int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}
int32_t main()
{
    fastio
    int t = 1;


    //cin>>t;
    while (t--) {
        solve();
    }
}
/*
5
1 1 2 1 3
3
1 5
2 4
3 5
*/