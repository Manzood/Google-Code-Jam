#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase () {
    int n;
    scanf("%lld", &n);
    vector <string> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bool same = true;
        bool gt = false;
        if (i > 0 && (int) a[i].size() <= (int) a[i-1].size()) {
            // debug(a[i-1]);
            // debug(a[i]);
            for (int j = 0; j < (int) a[i-1].size(); j++) {
                if ((j < (int) a[i-1].size() - 1) && (int) a[i].size() < j + 1) {
                    if (same && a[i-1][(int) a[i-1].size() - 1] < '9') {
                        a[i] += a[i-1][j];
                    } else {
                        a[i] += '0';
                    }
                    ans++;
                }
                if (j == (int) (a[i-1].size() - 1)) {
                    // debug(a[i]);
                    // debug(same);
                    if (gt) {
                        if (a[i].size() < a[i-1].size()) {
                            a[i] += '0';
                            ans++;
                        }
                    } else {
                        if ((int) a[i].size() < (int) a[i-1].size() && same && a[i-1][j] < '9' && a[i][j] <= a[i-1][j]) {
                            a[i] += a[i-1][j];
                            a[i][(int)a[i].size() - 1]++;
                            ans++;
                        } else if ((a[i].size() < a[i-1].size()) && (!same || (a[i-1][j] == '9' && a[i][j] <= a[i-1][j]))) {
                            // debug(a[i]);
                            a[i] += '0';
                            a[i] += '0';
                            // debug(a[i]);
                            ans++;
                            ans++;
                        } else if ((int)a[i].size() == (int)a[i-1].size() && a[i][j] <= a[i-1][j]) {
                            a[i] += '0';
                            ans++;
                        }
                    }
                }
                if (same && a[i][j] > a[i-1][j]) gt = true;
                if (a[i][j] != a[i-1][j]) same = false;
                // debug(same);
            }
            // debug(a[i]);
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
