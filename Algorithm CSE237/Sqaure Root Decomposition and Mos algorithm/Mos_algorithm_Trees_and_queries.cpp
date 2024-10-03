#include<bits/stdc++.h>
#define pb       push_back
#define pf       push_front
#define pi       2*acos(0.0)
#define f        first
#define s        second
#define inf      1000000000000000LL
#define MXN      100001
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

ll BLOCK = 555;
vector<ll>graph[MXN];
ll start[MXN];
ll termination[MXN];
ll bucket[MXN];
ll FlatTree[2 * MXN];
ll col[MXN];
ll nodefreq[MXN];
ll elementFreq[MXN];
ll FreqFreq[MXN];
ll ans[MXN];
ll n, timer;

struct query
{
	ll l;
	ll r;
	ll idx;
	ll k;
};
query Q[MXN];

void dfs(ll s, ll par) {
	timer++;
	start[s] = timer;
	FlatTree[timer] = s;

	for (auto child : graph[s]) {
		if (child != par) {
			dfs(child, s);
		}
	}
	timer++;
	termination[s] = timer;
	FlatTree[timer] = s;
}

bool comp(query a, query b) {
	ll x = a.l / BLOCK;
	ll y = b.l / BLOCK;

	if (x != y) {
		return x < y;
	}

	if (x % 2) {
		return a.r < b.r;
	}
	else {
		return a.r > b.r;
	}
}
ll getBlock(ll idx){
	 return (idx+BLOCK-1)/BLOCK;
}
void add(ll idx) {
	ll node = FlatTree[idx];
	ll c = col[node];
	nodefreq[node]++;

	if (nodefreq[node] == 2) {
		elementFreq[c]++;
		FreqFreq[elementFreq[c]]++;
		bucket[getBlock(elementFreq[c])]++;
		FreqFreq[elementFreq[c] - 1]--;
		bucket[getBlock(elementFreq[c]-1)]--;
	}
}

void remove(ll idx) {
	ll node = FlatTree[idx];
	ll c = col[node];
	nodefreq[node]--;

	if (nodefreq[node] == 1) {
		elementFreq[c]--;
		FreqFreq[elementFreq[c]]++;
		bucket[getBlock(elementFreq[c])]++;
		FreqFreq[elementFreq[c] + 1]--;
		bucket[getBlock(elementFreq[c]+1)]--;
	}
}

ll getAns(ll k, ll n) {
	ll ans = 0;
    ll LB = getBlock(k);
    ll RB = getBlock(n);

    if(LB == RB){
    	for(ll i=k;i<=n;i++){
    		ans+=FreqFreq[i]; 
    	}
    }
    else{
    	for(ll i=k;i<=LB*BLOCK;i++){
    		ans+=FreqFreq[i];
    	} 
    	for(ll i=LB+1;i<RB;i++){
    		ans+=bucket[i];
    	}
    	for(ll i=RB*BLOCK+1;i<=n;i++){
    		ans+=FreqFreq[i]; 
    	}
    }

    return ans;
}

void solve()
{
	ll q, a, b, k;

	cin >> n >> q;

	for (ll i = 1; i <= n; i++) {
		cin >> col[i];
	}

	for (ll i = 1; i <= n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	dfs(1, -1);

	for (ll i = 1; i <= q; i++) {
		cin >> a >> k;

		Q[i].l = start[a];
		Q[i].r = termination[a];
		Q[i].k = k;
		Q[i].idx = i;
	}

	sort(Q + 1, Q + 1 + q, comp);

	ll ML = 1 , MR = 0;
	for (int i = 1; i <= q; i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;
		int idx = Q[i].idx;
		k = Q[i].k;
		while (ML > L)
			ML-- , add(ML);

		while (MR < R)
			MR++ , add(MR);

		while (ML < L)
			remove(ML) , ML++;

		while (MR > R)
			remove(MR) , MR--;

		ans[idx] = getAns(k, n);

	}
	for (ll i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}
}
int32_t main()
{
	fastio
	int t = 1;


	//cin >> t;
	while (t--) {
		solve();
	}
}
