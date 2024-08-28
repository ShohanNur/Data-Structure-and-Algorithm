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




void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll x;
    cin >> x;
    ll a[x + 1];

    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }

    sort(a, a + x);
    reverse(a, a + x);

    int grid[n + 1][m + 1];
    memset(grid, 0 , sizeof grid);

    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            grid[i][j]++;
            if (i + k < n) {
                grid[i + k][j]--;
            }
            if (j + k < m) {
                grid[i][j + k]--;
            }
            if (i + k < n and j + k < m) {
                grid[i + k][j + k]++;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        grid[i][0] += grid[i - 1][0];
    }
    for (int j = 1; j < m; j++) {
        grid[0][j] += grid[0][j - 1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            grid[i][j] += (grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1]);
        }
    }
    
    for(int i=)
    vector<int>v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v.pb(grid[i][j]);
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll ans = 0;

    for (int i = 0; i < min(x, n * m); i++) {
        ans += (v[i] * a[i]);
    }
    cout << ans << endl;
}
int32_t main()
{
    fastio
    int t = 1;


    cin >> t;
    while (t--) {
        solve();
    }
}
