#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool solve_recursively(int cur, vector <vector <int>>& all_shortcuts, int required, vector <vector <int>>& shortcuts) {
    if (required == 0) return true;
    if (required < 0) return false;
    int len = (int) all_shortcuts.size();
    for (int i = cur + 1; i < len; i++) {
        if (cur > -1 && all_shortcuts[i][0] < all_shortcuts[cur][1]) continue;
        int diff = all_shortcuts[i][1] - all_shortcuts[i][0] - 1;
        if (solve_recursively(i, all_shortcuts, required - diff, shortcuts)) {
            shortcuts.push_back(all_shortcuts[i]);
            return true;
        }
    }
    return false;
}

void solve([[maybe_unused]] int test) {
    // make the grid
    int n, k;
    scanf("%lld%lld", &n, &k);
    int dir = 0;
    int curx = 0, cury = 0;
    int cur = 1;
    vector <vector <int>> grid(n, vector <int> (n, 0));
    vector <vector <bool>> marked(n, vector <bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[curx][cury] = cur;
            marked[curx][cury] = true;
            cur++;
            if (!ok(curx + dirs[dir][0], cury + dirs[dir][1], n, n) || marked[curx + dirs[dir][0]][cury + dirs[dir][1]]) {
                dir = (dir + 1) % ((int) dirs.size());
            }
            vector <int> nxt = dirs[dir];
            curx += nxt[0];
            cury += nxt[1];
        }
    }

    // try greedy
    int diff = n * n - 1 - k;
    bool possible = true;
    if (diff & 1) possible = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            marked[i][j] = false;
        }
    }
    vector <vector <int>> all_shortcuts;
    dir = 0; curx = 0; cury = 0;

    while (grid[curx][cury] < (int) n * n) {
        marked[curx][cury] = true;
        if (!ok(curx + dirs[dir][0], cury + dirs[dir][1], n, n) || marked[curx + dirs[dir][0]][cury + dirs[dir][1]]) {
            dir = (dir + 1) % ((int) dirs.size());
        }
        for (auto x: dirs) {
            int tempx = curx + x[0];
            int tempy = cury + x[1];
            if (ok(tempx, tempy, n, n)) {
                if (grid[tempx][tempy] > grid[curx][cury] + 1) {
                    all_shortcuts.push_back({grid[curx][cury], grid[tempx][tempy]});
                }
            }
        }
        vector <int> nxt = dirs[dir];
        curx += nxt[0];
        cury += nxt[1];
    }
    // debug(all_shortcuts);

    vector <vector <int>> shortcuts;
    if (!solve_recursively(-1, all_shortcuts, diff, shortcuts)) possible = false;
    reverse(shortcuts.begin(), shortcuts.end());

    if (possible) {
        printf("%lld\n", (int) shortcuts.size());
        for (auto x: shortcuts) {
            printf("%lld %lld\n", x[0], x[1]);
        }
    } else {
        printf("IMPOSSIBLE\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
        // printf("\n");
    }
}
