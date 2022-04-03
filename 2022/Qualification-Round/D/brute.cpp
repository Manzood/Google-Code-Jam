#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int mod = (int) 1e9 + 7;

// slow approach for partial points

// technically, this isn't a DFS
vector <bool> visited;
int dfs (int node, vector <int>& p, vector <int>& f) {
    int retval = 0;
    if (visited[node]) return retval;
    visited[node] = true;
    retval = f[node];
    if (p[node] > 0) retval = max(retval, dfs(p[node] - 1, p, f));
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> f(n);
    vector <int> p(n);
    vector <int> cnt(n, 0);
    visited.resize(n, false);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &f[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
        if (p[i] > 0) cnt[p[i] - 1]++;
    }
    vector <int> start;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            start.push_back(i);
        }
    }
    // debug(start);
    int len = start.size();
    vector <int> order(len);
    iota(order.begin(), order.end(), 0);
    int ans = 0;
    do {
        visited.assign(n, false);
        int cur = 0;
        for (int i = 0; i < len; i++) {
            cur += dfs(start[order[i]], p, f);
        }
        ans = max(cur, ans);
    } while (next_permutation(order.begin(), order.end()));
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
