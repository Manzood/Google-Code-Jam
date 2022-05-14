#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<vector<int>> grid1;
vector<vector<int>> grid2;
void draw_circle_perimeter(int R, int actual_radius) {
    for (int x = -R; x <= R; x++) {
        int y = (int) (sqrt(R * R - x * x) + 0.499999999);
        // debug(x, y, x + actual_radius, y + actual_radius);
        grid2[x + actual_radius][y + actual_radius] = 1;
        grid2[x + actual_radius][-y + actual_radius] = 1;
        grid2[y + actual_radius][x + actual_radius] = 1;
        grid2[-y + actual_radius][x + actual_radius] = 1;
    }
}

void draw_circle_filled(int R) {
    for (int x = -R; x <= R; x++) {
        for (int y = -R; y <= R; y++) {
            int cur = (int) (sqrt(x * x + y * y) + 0.499999999);
            if (cur <= R) {
                grid1[x + R][y + R] = 1;
            }
        }
    }
}

void draw_circle_filled_wrong(int R) {
    for (int r = 0; r <= R; r++) {
        draw_circle_perimeter(r, R);
    }
}

void solve([[maybe_unused]] int test) {
    int r;
    scanf("%lld", &r);
    grid1 = vector<vector<int>>(2 * r + 1, vector<int>(2 * r + 1, 0));
    grid2 = vector<vector<int>>(2 * r + 1, vector<int>(2 * r + 1, 0));
    draw_circle_filled(r);
    draw_circle_filled_wrong(r);
    int ans = 0;
    // for (int i = 0; i < 2 * r + 1; i++) {
    //     for (int j = 0; j < 2 * r + 1; j++) {
    //         printf("%lld ", grid1[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for (int i = 0; i < 2 * r + 1; i++) {
    //     for (int j = 0; j < 2 * r + 1; j++) {
    //         printf("%lld ", grid2[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < 2 * r + 1; i++) {
        for (int j = 0; j < 2 * r + 1; j++) {
            ans += grid1[i][j] != grid2[i][j];
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        solve(tt);
    }
}
