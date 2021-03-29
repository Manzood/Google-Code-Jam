#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase() {
    int x, y;
    scanf("%lld%lld", &x, &y);
    string s;
    cin >> s;
    int n = s.size();
    int cost = 0;
    char p = s[0];
    if (x + y >= 0) {
        for (int i = 1; i < n; i++) {
            if (s[i] == 'J') {
                if (p == 'C') {
                    cost += x;
                }
                p = s[i];
            } else if (s[i] == 'C') {
                if (p == 'J') {
                    cost += y;
                }
                p = s[i];
            }
        }
    } else {
        // TODO: Fix it
        // for (int i = 1; i < n; i++) {
            // if (s[i] == '?') {
                // if (s[i-1] == 'J') {
                    // s[i] = 'C';
                // }
                // else {
                    // s[i] = 'J';
                // }
            // }
        // }
        // debug(s);
        // for (int i = 1; i < n; i++) {
            // if (s[i] == 'C') {
                // if (s[i-1] == 'J') {
                    // cost += y;
                // }
            // } else {
                // if (s[i-1] == 'C') {
                    // cost += x;
                // }
            // }
        // }
    }
    printf("%lld", cost);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
