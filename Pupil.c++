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
typedef vector<string> vs;
typedef unordered_map<int, int> umii;
typedef unordered_set<int> usi;

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
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())
#define REVERSE(v) reverse(all(v))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;

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
void print(T t) { cout << t << "\n"; }

template <typename T, typename... Args>
void print(T t, Args... args) {
    cout << t << " ";
    print(args...);
}

template <typename T>
void printVector(const vector<T>& v) {
    for (const T& x : v) cout << x << " ";
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

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

vll sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vll primes;
    for (int i = 2; i <= n; i++)
        if (is_prime[i]) primes.pb(i);
    return primes;
}

// Data structures
struct UnionFind {
    vi parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) parent[x] = y;
        else parent[y] = x, rank[x] += rank[x] == rank[y];
    }
};

// Problem-solving function
void solve() {
    // Read input
    int n;
    cin >> n;
    vi a(n);
    for (int& x : a) cin >> x;

    // TODO: Implement your solution here
    
    // Example: Find the longest increasing subsequence
    vi dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int lis = *max_element(all(dp));
    
    // Print results
    print("Longest Increasing Subsequence:", lis);
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
