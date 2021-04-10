#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase () {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        debug(a[i]);
        if (i > 0) {
            debug(a[i-1]);
            while (a[i] <= a[i-1]) {
                a[i] *= 10;
                if (a[i] <= a[i-1] && a[i] + 9 > a[i-1]) {
                    a[i] += a[i-1] - a[i] + 1;
                }
                ans++;
            }
        }
        debug(a[i]);
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

