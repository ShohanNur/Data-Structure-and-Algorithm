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


struct query {
	ll l;
	ll r;
	ll i;
};
query Q[200002];

ll ar[200002] , ans[200002];
ll fre[1000001];
ll BLOCK;
ll power = 0;

bool comp(query a , query b)
{
	if (a.l / BLOCK != b.l / BLOCK)
		return a.l / BLOCK < b.l / BLOCK;

	return a.r < b.r;
}

void add(int pos)
{

	ll temp = fre[ar[pos]];
	fre[ar[pos]]++;
	power -= (temp * temp) * ar[pos];
	temp++;
	power += (temp * temp) * ar[pos];

}

void remove(int pos)
{
	ll temp = fre[ar[pos]];
	fre[ar[pos]]--;
	power -= (temp * temp) * ar[pos];
	temp--;
	power += (temp * temp) * ar[pos];
}

void solve()
{

	int n , q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	BLOCK = sqrt(n);

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

		ans[Q[i].i] = power;

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
