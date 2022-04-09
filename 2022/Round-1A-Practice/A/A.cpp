#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = s.size();
    vector <bool> expand(n, false);
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == s[i+1]) {
            expand[i] = expand[i+1];
        } else if (s[i] > s[i+1]) {
            expand[i] = false;
        } else {
            expand[i] = true;
        }
    }
    string ans;
    for (int i = 0; i < n; i++) {
        ans += s[i];
        if (expand[i]) {
            ans += s[i];
        }
    }
    cout << ans;
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
