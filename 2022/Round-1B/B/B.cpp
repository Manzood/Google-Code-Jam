#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, p;
    scanf("%lld%lld", &n, &p);
    vector <vector <int>> a(n, vector <int> (p));
    vector <int> mx(n + 1, 0);
    vector <int> mi(n + 1, (int) 1e9 + 7);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%lld", &a[i][j]);
            mx[i + 1] = max(mx[i + 1], a[i][j]);
            mi[i + 1] = min(mi[i + 1], a[i][j]);
        }
    }
    mi[0] = 0;
    vector <vector <int>> dp(n + 1, vector <int> (2, 0));
    // dp[i][0] represents when max is chosen to start, dp[i][1] represents when min is chosen to start
    for (int i = 1; i < n + 1; i++) {
        dp[i][0] = dp[i-1][1] + abs(mx[i-1] - mx[i]);
        dp[i][0] = min(dp[i-1][0] + abs(mi[i-1] - mx[i]), dp[i][0]);
        dp[i][1] = dp[i-1][0] + abs(mi[i-1] - mi[i]);
        dp[i][1] = min(dp[i-1][1] + abs(mx[i-1] - mi[i]), dp[i][1]);
        dp[i][0] += abs(mx[i] - mi[i]);
        dp[i][1] += abs(mx[i] - mi[i]);
    }
    // debug(dp);
    int ans = min(dp[n][0], dp[n][1]);
    printf("%lld", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
        printf("\n");
    }
}
