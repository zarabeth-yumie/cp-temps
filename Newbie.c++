#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// Macros
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define REPR(i, a, b) for (int i = (a); i > (b); --i)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double PI = acos(-1.0);

// Debugging macros
#define DEBUG
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define debug(...)
#define dbg(x)
#endif

// Utility functions
template <typename T>
void print(T t) {
    cout << t << "\n";
}

template <typename T, typename... Args>
void print(T t, Args... args) {
    cout << t << " ";
    print(args...);
}

template <typename T>
void printVector(const vector<T>& v) {
    for (const T& x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

// Math functions
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod_add(ll a, ll b, ll m) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m) { return (a % m - b % m + m) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
ll mod_pow(ll b, ll p, ll m) {
    ll r = 1;
    while (p) {
        if (p & 1) r = mod_mul(r, b, m);
        b = mod_mul(b, b, m);
        p >>= 1;
    }
    return r;
}

// Problem-solving function
void solve() {
    // Read input
    int n;
    cin >> n;
    vi a(n);
    for (int& x : a) cin >> x;

    // TODO: Implement your solution here
    
    // Example: Calculate sum and product of array elements
    ll sum = 0, product = 1;
    for (int x : a) {
        sum = mod_add(sum, x, MOD);
        product = mod_mul(product, x, MOD);
    }
    
    // Print results
    print("Sum:", sum);
    print("Product:", product);
}

// Main function
int main() {
    fastio;  // Fast I/O
    
    // Uncomment the following line if you want to use file I/O
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    int t = 1;
    cin >> t;  // Read number of test cases
    while (t--) {
        solve();
    }
    
    return 0;
}
