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
    // printf("\n");
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%lld ", grid[i][j]);
    //     }
    //     printf("\n");
    // }

    // try greedy
    int diff = n * n - 1 - k;
    bool possible = true;
    if (diff & 1) possible = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            marked[i][j] = false;
        }
    }
    vector <vector <int>> shortcuts;
    dir = 0; curx = 0; cury = 0;

    bool waiting = false;
    int targetx = -1, targety = -1;
    int travelled = 0;
    while (grid[curx][cury] < (int) n * n) {
        marked[curx][cury] = true;
        if (!ok(curx + dirs[dir][0], cury + dirs[dir][1], n, n) || marked[curx + dirs[dir][0]][cury + dirs[dir][1]]) {
            dir = (dir + 1) % ((int) dirs.size());
        }
        if (waiting && curx == targetx && cury == targety) {
            waiting = false;
            travelled++;
        }
        if (!waiting) {
            for (auto x: dirs) {
                int tempx = curx + x[0];
                int tempy = cury + x[1];
                if (ok(tempx, tempy, n, n)) {
                    if (grid[tempx][tempy] > grid[curx][cury] + 1) {
                        // if (grid[curx][cury] == 17) debug(grid[tempx][tempy]);
                        int curdiff = grid[tempx][tempy] - grid[curx][cury] - 1;
                        if (curdiff <= diff) {
                            shortcuts.push_back({grid[curx][cury], grid[tempx][tempy]});
                            targetx = tempx;
                            targety = tempy;
                            waiting = true;
                            diff -= curdiff;
                            break;
                        }
                    }
                }
            }
        }
        vector <int> nxt = dirs[dir];
        curx += nxt[0];
        cury += nxt[1];
        if (!waiting) travelled++;
    }

    if (travelled > k) possible = false;
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
    }
}
