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
    int n;
    scanf("%lld", &n);
    vector <int> s(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
    }
    sort (s.begin(), s.end());
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] > cur) cur++;
    }
    printf("%lld", cur);
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
