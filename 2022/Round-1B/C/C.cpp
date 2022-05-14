#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query (int n) {
    string out = "00000000";
    for (int i = 7; i >= 7 - (n - 1); i--) {
        out[i] = '1';
    }
    cout << out << endl;
    int response;
    cin >> response;
    return response;
}

void solve([[maybe_unused]] int test) {
    int bits = query(0);
    while (bits != 0 && bits != -1) {
        bits = query(bits);
        if (bits == -1) exit(0);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
