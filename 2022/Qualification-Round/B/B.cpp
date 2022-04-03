#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int mod = (int) 1e9 + 7;

void solve([[maybe_unused]] int test) {
    vector <int> a(4), b(4), c(4), mi(4);
    for (int i = 0; i < 4; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i = 0; i < 4; i++) {
        mi[i] = min(a[i], min(b[i], c[i]));
    }
    int req = (int) 1e6;
    vector <int> ans(4);
    for (int i = 0; i < 4; i++) {
        ans[i] = min(req, mi[i]);
        req -= min(req, mi[i]);
    }
    if (req) {
        printf("IMPOSSIBLE");
    } else {
        for (int i = 0; i < 4; i++) {
            printf("%lld ", ans[i]);
        }
    }
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

