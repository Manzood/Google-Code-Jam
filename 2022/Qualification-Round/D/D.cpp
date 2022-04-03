#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int mod = (int)1e9 + 7;

// slow approach for partial points

void propagate(int node, vector <vector <int>>& adj, vector <int>& f, vector <int>& subtreemax) {
    // find the minimum of all subtrees;
    int len = adj[node].size();
    if (len == 0) return;
    int minval = mod;
    int ind = -1;
    for (int i = 0; i < len; i++) {
        int u = adj[node][i];
        if (subtreemax[u] < minval) {
            ind = i;
            minval = subtreemax[u];
        }
    }
    // if (node == 3) debug(adj[node][ind]);
    // if (node == 3) debug(subtreemax[adj[node][ind]]);
    // if (node == 3) debug(f[node]);
    if (ind >= 0 && f[node] > subtreemax[adj[node][ind]]) {
        swap(f[node], f[adj[node][ind]]);
    }
    for (auto u: adj[node]) {
        propagate(u, adj, f, subtreemax);
    }
}

int getmax (int node, vector <vector <int>>& adj, vector <int>& f, vector <int>& subtreemax) {
    int retval = mod;
    for (auto u: adj[node]) {
        retval = min(retval, getmax(u, adj, f, subtreemax));
    }
    if (adj[node].size() == 0) retval = 0;
    retval = max(retval, f[node]);
    subtreemax[node] = retval;
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    // invert the graph
    // send nodes down the graph
    vector<int> p(n), f(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &f[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
    }
    vector <vector <int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        adj[p[i]].push_back(i + 1);
    }
    vector <int> subtreemax(n + 1, 0);
    getmax(0, adj, f, subtreemax);
    // debug(f);
    propagate(0, adj, f, subtreemax);
    // debug(f);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if ((int) adj[i].size() == 0) {
            ans += f[i];
        }
    }
    printf("%lld", ans);
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
        printf("\n");
    }
}
