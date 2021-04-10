#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase () {
    int m;
    scanf("%lld", &m);
    vector <int> a;
    for (int i = 0; i < m; i++) {
        int p, n;
        scanf("%lld%lld", &p, &n);
        for (int j = 0; j < n; j++) {
            a.push_back(p);
        }
    }
    int ans = 0;
    for (int j = 0; j < (1LL << 11); j++) {
        int sum = 0;
        int prod = 1;
        for (int i = 0; i < (int)a.size(); i++) {
            if ((1LL << i) & j) {
                sum += a[i];
            } else {
                prod *= a[i];
            }
        }
        if (sum == prod) {
            ans = max (sum, ans);
        }
    }
    printf("%lld", ans);
}

int32_t main () {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}

