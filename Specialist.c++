#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
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

// Segment Tree
struct SegmentTree {
    int n;
    vector<ll> tree;

    SegmentTree(int size) : n(size), tree(4 * n) {}

    void build(const vll& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    void update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm))
             + query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
};

// Graph algorithms
vector<vi> adj;
vi visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

vi bfs(int start) {
    vi distance(sz(adj), INF);
    queue<int> q;
    distance[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (distance[u] == INF) {
                distance[u] = distance[v] + 1;
                q.push(u);
            }
        }
    }
    return distance;
}

// Problem-solving function
void solve() {
    // Read input
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    visited.assign(n, false);
    REP(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;  // 0-based indexing
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // Example: Find connected components
    int components = 0;
    REP(i, 0, n) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
    
    // Example: Find distances from node 0
    vi distances = bfs(0);
    
    // Print results
    print("Number of connected components:", components);
    print("Distances from node 0:");
    printVector(distances);
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
