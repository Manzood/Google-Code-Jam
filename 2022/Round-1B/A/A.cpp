#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int l = 0, r = n - 1;
    int ans = 0;
    int mx = 0;
    while (l <= r) {
        if (a[l] < a[r]) {
            if (a[l] >= mx) {
                mx = a[l];
                ans++;
            }
            l++;
        } else {
            if (a[r] >= mx) {
                mx = a[r];
                ans++;
            }
            r--;
        }
    }
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
