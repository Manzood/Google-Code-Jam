#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <pair<int, int>> ans;
    bool possible = true;
    int y = 2;
    int prevx = -10000, prevy = -20000;
    if (n < 2) {
        possible = false;
    } else {
        for (int j = 0; j < m; j++) {
            int x = 1;
            for (int i = 0; i < n / 2; i++) {
                if (prevx == x || prevy == y || prevx + prevy == x + y || prevx - prevy == x - y) {
                    possible = false;
                }
                ans.push_back({x + 1, y + 1});
                prevx = x;
                prevy = y;
                int cur = y;
                cur -= 2;
                if (cur < 0) cur += m;
                ans.push_back({x, cur + 1});
                if (prevx == x - 1 || prevy == cur || prevx + prevy == x + cur - 1 || prevx - prevy == x - 1 - cur) {
                    possible = false;
                }
                prevx = x - 1;
                prevy = cur;
                x += 2;
            }
            y++;
            y %= m;
        }
    }
    if (!possible) {
        printf("IMPOSSIBLE\n");
        // for (int i = 0; i < (int)ans.size(); i++) {
            // printf("%lld %lld\n", ans[i].first, ans[i].second);
        // }
    } else {
        printf("POSSIBLE\n");
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%lld %lld\n", ans[i].first, ans[i].second);
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        // printf("\n");
    }
}
