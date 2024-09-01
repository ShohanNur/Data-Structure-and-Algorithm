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

#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  test        int t; cin>>t ;while(t--)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002

typedef long long ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// init (ordered_set st)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>


// another template:  init ( ordered_set<int> st)
template <class T> using ordered_set = tree<T, null_type,
                         less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using multi_ordered_set = tree<T, null_type,
                         less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// upper_bound of multiset and erase
auto ub = st.upper_bound(a[i]);
v.pb(*ub);
st.erase(st.find(*ub));
// multiset upper_bound returns the upper bound value not index.
// it returns an iterator , so we have to * it to get the value.


// to find the element which is most close to some element
for (auto i : vv) {

    auto ub  = upper_bound(a.begin(), a.end(), i);
    if (ub != a.end()) {
        mn = min(mn , abs(*ub - i));
    }
    if (ub != a.begin()) {
        ub--;
        mn = min(mn, abs(*ub - i));
    }


    /* same thing if we do use array.

          ll ub = upper_bound(a+1,a+n+1,xx)-a;

          if(ub!=n+1){
             mn = min(mn,abs(xx-a[ub]));
          }
          if(ub!=1){
             ub--;
             mn = min(mn,abs(xx-a[ub]));
          }
    */
}

// st.order_of_key(k) : Number of items strictly smaller than k .
// *st.find_by_order(k) : K-th element in a set (counting from zero).
ordered_set st;

//1.. count the number of elements which are strictly smaller than the current element
ll sum = 0;
multi_ordered_set st;
for (int i = 0; i < n; i++)
{
    ll id = st.order_of_key(a[i]);
    sum += (st.size() - id);
    st.insert(a[i]);
}
cout << sum << endl;

//2 .. count the number of elements which are strictly smaller than the current element
ordered_set<int>st;

for (auto i : v)
    st.insert(i.f);

ll ans = 0;

for (auto i : v)
{
    int x = st.order_of_key(i.f);
    ans += x;
    st.erase(i.f);
}

cout << ans << endl;

// short code for seive:

const int N = 1000000;
vector<ll>Prime;
bool prime[N + 5];

void seive() {

    prime[0] = 1;
    prime[1] = 1;

    for (int i = 2; i * i <= N; i++) {
        if (!prime[i]) {
            Prime.pb(i);
            for (int j = i * i; j <= N; j += i) {
                prime[j] = 1;
            }
        }
    }
}


///long code for seive

const ll N = 10000003;
vector<ll>Prime;
bool prime[N + 5];
void seive()
{

    int i, j;
    prime[0] = true;
    prime[1] = true;
    for (i = 4; i <= N; i += 2)
    {
        prime[i] = true;
    }
    for (i = 3; i * i <= N; i += 2)
    {
        if (!prime[i])
        {
            for (j = i * i; j <= N; j += i)
            {
                prime[j] = true;
            }
        }
    }

    for (ll i = 0; i <= N; i++)
    {
        if (prime[i] == 0)
        {
            Prime.pb(i);
        }
    }

}

ll primefact[1000001];
ll n;
void getPrimeFact(ll n) {
    int mx = 1000000;
    for (int i = 1; i <= mx; i++) {
        primefact[i] = -1;
    }

    for (int i = 2; i <= mx; i++) {
        if (primefact[i] == -1) {
            for (int j = i; j <= mx; j += i) {
                if (primefact[j] == -1) {
                    primefact[j] = i;
                }
            }
        }
    }
    vector<ll>ans;
    while (n != 1) {
        ans.pb(primefact[n]);
        n = n / primefact[n];
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

}

// mobius function
void Mobius()
{
    for (int i = 1; i < sz; i++) {

        // If number is one
        if (i == 1)
            mobius[i] = 1;
        else {

            // If number has a squared prime factor
            if (spf[i / spf[i]] == spf[i])
                mobius[i] = 0;

            // Multiply -1 with the previous number
            else
                mobius[i] = -1 * mobius[i / spf[i]];
        }
    }
}




// recursive
ll bigmod(ll base, ll power)
{
    if (power == 0)return 1;
    ll h = bigmod(base, power / 2);
    h = (h * h) % mod;
    if (power % 2 )h = (h * base) % mod;
    return h;

}

// Function to compute the prefix XOR array
vector<ll> computePrefixXOR(const vector<ll> arr)
{
    ll n = arr.size();
    vector<ll> prefixXOR(n);

    prefixXOR[0] = arr[0];

    for (ll i = 1; i < n; ++i)
    {
        prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
    }

    return prefixXOR;
}

// Function to perform range XOR query
ll rangeXORQuery(const vector<ll> &prefixXOR, ll left, ll right)
{
    if (left == 0)
    {
        return prefixXOR[right];
    }
    else
    {
        return prefixXOR[right] ^ prefixXOR[left - 1];
    }
}


// lower_bound :
ll first = -1, last = -1;
ll left = 1;
ll right = n;

while (left <= right) {

    ll mid = left + (right - left) / 2;

    if (a[mid] < x) {
        left = mid + 1;
    }
    else {
        first = mid;
        right = mid - 1;
    }
}
// upper_bound = lower_bound of (x+1)
left = 1;
right = n;

while (left <= right) {
    ll mid = left + (right - left) / 2;

    if (a[mid] <= x) {
        last = mid;
        left = mid + 1;
    }
    else {
        right = mid - 1;
    }
}


ll modular_inverse(ll n) {
    return bigmod(n, mod - 2);
}
// iterative

ll bigmod(ll a, ll n) {

    ll res = 1;

    while (n) {
        if (n % 2) {
            res = (res * a) % mod;
        }
        n /= 2;

        a = (a * a) % mod;
    }
    return res;
}

// phi iteratively
ll phi(ll n) {

    ll res = n;
    for (ll i = 2; i * i <= n; i++) {


        if (n % i == 0) {
            res /= i;
            res *= (i - 1);

            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1)
        res /= n, res *= (n - 1);

    return res;
}

// phi using seive
ll phi[1000001];

void init() {
    for (ll i = 1; i <= MXN; i++) {
        phi[i] = i;
    }

    for (ll i = 2; i <= MXN; i++) {
        if (phi[i] == i) {
            for (ll j = i; j <= MXN; j += i) {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}

// kadane's algo for maximum subarray sum :
int maxSubArraySum()
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

ll binaryToDecimal(ll n)
{
    ll num = n;
    ll dec_value = 0;


    ll base = 1;

    ll temp = num;
    while (temp) {
        ll last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}
bool isKthBitSet(int n, int k)
{
    if (n & (1ll << k))
        return 1;
    else
        return 0;
}

ll setBit(ll n) {
    ll cnt = 0;
    for (ll i = 0; i < 30; i++) {
        if ((n >> i) & 1 == 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    cnt = 0;
    while (n) {
        cnt++;
        n = n & (n - 1);
    }
    cout << cnt << endl;
}

ll power(ll base, ll n) {
    ll res = 1;
    while (n) {
        if (n % 2) {
            res = (res * a) % mod;
            n--;
        }
        else {
            a = (a * a) % mod;
            n /= 2;
        }
    }
    return res;
}
ll palin(ll num) {
    ll n = num, digit, rev = 0;
    do
    {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);
    if (n == rev) {
        return n;
    }
    else {
        return 0;
    }
}

bool com(pair<ll, ll>&a , pair<ll, ll>&b) {

    if (a.f == b.f) {
        return a.s < b.s;
    }
    else {
        return a.f < b.f;
    }
}

typedef pair<ll, ll> pii;

class com {
public:
    bool operator()(pii below, pii above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }

        return false;
    }
};

bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

// vector<pair<ll,pair<ll,ll>>>v
bool com(pair<ll, pair<ll, ll>>&a , pair<ll, pair<ll, ll>>&b) {

    if (a.f == b.f) {

        if (a.s.f == b.s.f) {
            return a.s.s < b.s.s;
        }
        else {
            return a.s.f < b.s.f;
        }
    }
    else {
        return a.f > b.f;
    }
}

struct abc
{
    ll first_val, second_val, third_val;
};

bool com(abc a, abc b)
{
    if (a.first_val == b.first_val)
    {
        if (a.second_val == b.second_val)
            return a.third_val < b.third_val;
        else
            return a.second_val < b.second_val;
    }
    else
        return a.first_val > b.first_val;
}


void binary_search_minimum() {


    ll low = 0;
    ll high = 1e18;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
}

ll maxSumSubarray(vector<ll>&a, ll n) {
    ll meh = 0; // max ending here
    ll msf = LLONG_MIN; // max so far

    for (int i = 0; i < n; i++) {
        meh += a[i];

        if (meh < a[i]) {
            meh = a[i];
        }
        if (msf < meh) {
            msf = meh;
        }

    }
    return msf;
}
void binary_search_maximum() {
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
}

// prime factors set
set<int> fact(int n) {
    set<int> factorization;
    for (long long d : Prime) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.insert(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.insert(n);
    return factorization;
}

// Prime factorization
vector<ll> PrimeFactors(ll n) {
    vector<ll> factorization;
    for (long long d : Prime) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.pb(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.pb(n);
    return factorization;
}

// divisors of a number
vector<ll> printDivisors(ll n)
{
    vector<ll>divisors;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i) {
                divisors.pb(i);
            }
            else {
                divisors.pb(i);
                divisors.pb(n / i);
            }
        }
    }
    return divisors;
}

// find mex
int mex = 0;
while (st.count(mex)) {
    mex++;
}
ll mex(vector<ll> &arr, ll N)
{

    // sort the array
    sort(arr.begin(), arr.end());

    ll mex = 0;
    for (int idx = 0; idx < N; idx++)
    {
        if (arr[idx] == mex)
        {
            // Increment mex
            mex += 1;
        }
    }

    // Return mex as answer
    return mex;
}

cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";


// Ternery Search : O(log3(n))

   ll low = 1;
    ll high = n;
    ll ans=-1; 
    while(low<=high){
          ll mid1 = low + (high-low)/3;
          ll mid2 = high - (high-low)/3;
          
          if(a[mid1]==x){
             ans = mid1;
          } 
          if(a[mid2]==x){
             ans = mid2;
          }
          if(a[mid1]>x){
               high = mid1-1;
          }
          else if(a[mid2]<x){
               low = mid2+1;
          }
          else{
               low = mid1+1;
               high = mid2-1;
          }
    }
    

// prime factors in log(n)
// in smallest prime factor

vector<ll> spf(sz + 10);

void seive()
{
    for (ll i = 1ll; i <= sz; i++) spf[i] = i;

    for (ll i = 2ll; i <= sz; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i + i; j <= sz; j += i)
            {
                spf[j] = min(spf[j], i);
            }
        }

    }
}


// spf using seive

const int mod = 1e9 + 7;
const int N = 5e5 + 6;

#define sz 10000010
bool siv[sz];
int spf[sz];

void seive()
{
    int  limit = sqrt(sz + 1);

    for (int i = 1 ; i < sz ; i++)
        spf[i] = i;

    for (int i = 2 ; i < sz ; i += 2)
        spf[i] = 2;

    for (int  i = 3; i <= limit; i += 2)
        if (!siv[i])
            for (int  j = i * i; j < sz; j += i + i)
                siv[j] = 1, spf[j] = min(spf[j], i);
}

// prime fact using spf : log(n)

while (x > 1)
{
    v[i].pb(spf[x]);
    x /= spf[x];
}



vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1) {
        ll temp = spf[x];
        ret.push_back(temp);
        while (x % temp == 0)
            x = x / temp;
    }
    return ret;
}

ll modular_inverse(ll x){
      return bigmod(x, mod-2);
}

ll add (ll a, ll b) { return (mod+(a % mod+ b % mod) % mod + mod) % mod;}
ll sub (ll a, ll b) { return add(a, mod - b); }
ll dvd (ll a, ll b) { return mul(a, modular_inverse(b));}
ll mul (ll a, ll b) { return ((a%mod) * 1LL * (b % mod))%mod;}



// nCr :

ll F[1000001];

void make_fact() {

    F[0] = F[1] = 1ll;

    for (ll i = 2; i <= 1000000; i++) {
        F[i] = (F[i - 1] * i) % mod;
    }
}

ll bigmod(ll a, ll n) {
   if(n==0) return 1ll;
 
   ll x = bigmod(a,n/2);
 
   x = mul(x,x);
 
   if(n%2==1){
     return mul(x,a);
   }
   return x;
}

ll nCr(ll n, ll r) {
    if (r > n) return 0;

    ll res = F[n];

    res = (res * bigmod(F[r], mod - 2)) % mod;
    res = (res * bigmod(F[n - r], mod - 2)) % mod;

    return res;
}
ll nPr(ll n, ll r) {
    if (r > n) return 0;

    ll res = F[n];

    res = (res * bigmod(F[n - r], mod - 2)) % mod;

    return res;
}



// fermat's primality test

ll mulmod(ll a, ll b , ll c) {
    ll x = 0, y = a % c;

    while (b > 0) {
        if (b % 2 == 1) {
            x = (x + y) % c;
        }
        y = (y * 2ll) % c;
        b /= 2;
    }

    return x % c;
}

ll binPower(ll a, ll n, ll m) {

    ll res = 1;

    while (n) {

        if (n & 1) {
            res = mulmod(res, a , m);
        }
        n >>= 1;

        a = mulmod(a, a, m);
    }
    return res % m;
}
bool isPrime(ll n, ll item = 5) {

    if (n <= 4) {
        return n == 2 || n == 3;
    }

    for (int i = 1; i <= item; i++) {
        ll a = 2 + rand() % (n - 3);

        ll res = binPower(a, n - 1 , n);

        if (res != 1) {
            return false;
        }
    }
    return true;
}


// primality test using miller-robin

typedef     unsigned long long       ULL;

ULL modular_mul(ULL a, ULL b, ULL modulus)
{
    ULL result = 0;
    a %= modulus;

    while (b > 0) {
        if (b & 1) {
            result = (result + a) % modulus;
        }

        a = (a << 1) % modulus;             // a = (a * 2) % modulus.
        b >>= 1;                            // b /= 2.
    }

    return result % modulus;
}

ULL modular_pow(ULL base, ULL exponent, ULL modulus)
{
    if (modulus == 1) return 0;

    ULL result = 1;
    base %= modulus;

    while (exponent > 0) {
        if (exponent & 1) {
            result = modular_mul(result, base, modulus);
        }

        exponent >>= 1;
        base = modular_mul(base, base, modulus);
    }

    return result;
}

bool isPrime(ULL n, int iteration)
{
    if (n < 2) return false;
    if (n <= 3) return true;
    if (!(n & 1)) return false;             // If n is even.

    ULL d = n - 1;                          // d * 2^r = n-1 where d is odd and r > 0.
    while (!(d & 1))
        d >>= 1;

    while (iteration--) {                   // Witness loop.
        ULL a = rand() % (n - 1) + 1;
        ULL x = modular_pow(a, d, n);       // x = a^d % n
        ULL d1 = d;

        while (d1 != n - 1 && x != 1 && x != n - 1) {
            x = modular_mul(x, x, n);       // x = (x * x) % n.
            d1 <<= 1;
        }

        if (x != n - 1 && !(d1 & 1)) {
            return false;
        }
    }

    return true;
}

// map

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, int> mp;
