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


ll n, m, BLOCK_NO, BLOCK_SIZE;
ll F[200002];

ll getMin(ll l, ll r, ll a[]) {
	ll lb = l / BLOCK_SIZE;
	ll rb = r / BLOCK_SIZE;

	ll mn = LLONG_MAX;

	if (lb == rb) {
		for (ll i = l; i <= r; i++) {
			mn = min(a[i], mn);
		}
		return mn;
	}

	for (ll i = l; i < BLOCK_SIZE * (lb + 1); i++) {
		mn = min(mn, a[i]);
	}

	for (ll i = lb + 1; i < rb; i++) {
		mn = min(mn, F[i]);
	}

	for (ll i = BLOCK_SIZE * rb; i <= r; i++) {
		mn = min(mn, a[i]);
	}

	return mn;
}
void solve()
{
	cin >> n;
	ll a[n + 1];
	ll q;
	cin >> q;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}

	BLOCK_SIZE = sqrt(n);
	BLOCK_NO = n / BLOCK_SIZE;
	ll x = 1;
	ll in = 1;
	while (BLOCK_NO--) {
		ll y = x + BLOCK_SIZE;
		ll mn = LLONG_MAX;
		for (ll i = x; i < y; i++) {
			mn = min(mn, a[i]);
		}
		F[in] = mn;
		in++;
		x = y;
	}



	while (q--) {
		ll l, r;
		cin >> l >> r;

		cout << getMin(l, r, a) << endl;
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
