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
    vector <vector <int>> child(n, vector <int> (2));
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &child[i][0], &child[i][1]);
    }
    vector <vector <int>> sweets(n + 1, vector <int> (2));
    for (int i = 0; i < n + 1; i++) {
        scanf("%lld%lld", &sweets[i][0], &sweets[i][1]);
    }
    vector <int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    bool possible = false;
    do {
        vector <int> marked(n + 1, false);
        bool passed = true;
        vector <int> picked(n);
        for (int i = 0; i < n; i++) {
            vector <int> closest = {0};
            int mindist = abs(sweets[0][0] - child[i][0]) + abs(sweets[0][1] - child[i][1]);
            for (int j = 1; j < n + 1; j++) {
                if (marked[j]) continue;
                int curdist = abs(sweets[j][0] - child[i][0]) + abs(sweets[j][1] - child[i][1]);
                if (curdist < mindist) {
                    closest = {i};
                    mindist = curdist;
                } else if (curdist == mindist) {
                    closest.push_back(i);
                }
            }
            // consume the best candy for that child
            if ((int) closest.size() == 1) {
                marked[closest[0]] = true;
                picked[i] = closest[0];
                if (closest[0] == 0) {
                    passed = false;
                }
            } else {
                // try each possibility
                // or try random??
                for (int j = 0; j < (int) closest.size(); j++) {
                    if (closest[j] != 0) {
                        marked[closest[j]] = true;
                        picked[i] = closest[j];
                        break;
                    }
                }
            }
        }
        if (passed) {
            possible = true;
            printf("POSSIBLE\n");
            for (int i = 0; i < n; i++) {
                printf("%lld %lld\n", perm[i] + 1, picked[i] + 1);
            }
            break;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    if (!possible) printf("IMPOSSIBLE\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
    }
}
