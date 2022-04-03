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
    int n, m;
    printf("\n");
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * m + 1; j++) {
            if (i < 2 && j < 2) {
                printf(".");
            } else if (i % 2 == 0 && j % 2 == 0) {
                printf("+");
            } else if (i % 2 == 0) {
                printf("-");
            } else if (j % 2 == 0) {
                printf("|");
            } else {
                printf(".");
            }
        }
        if (i != 2 * n) printf("\n");
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
