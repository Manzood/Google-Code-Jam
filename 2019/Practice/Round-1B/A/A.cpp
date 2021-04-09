#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

void testcase () {
    int p, q;
    scanf("%lld%lld", &p, &q);
    vector <vector <char>> grid(q);
    vector <int> down(q, 0);
    vector <int> right(q, 0);
    vector <int> up(q, 0);
    vector <int> left(q, 0);
    for (int i = 0; i < q; i++) {
        grid[i].resize(q, 'O');
    }
    for (int i = 0; i < p; i++) {
        int x, y;
        char dir;
        scanf("%lld%lld %c", &x, &y, &dir);
        grid[x-1][y-1] = dir;
    }
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < q; j++) {
            if (i > 0 && grid[i-1][j] == 'S') {
                down[i]++;
            }
            if (i > 0) down[i] += down[i-1];
            if (j > 0 && grid[j-1][i] == 'R') {
                right[i]++;
            }
            if (j > 0) right[i] += right[i-1];
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        for (int j = q - 1; j >= 0; j--) {
            if (i < q - 1 && grid[i+1][j] == 'N') {
                up[i]++;
            }
            if (i < q - 1) up[i] += up[i+1];
            if (j < q - 1 && grid[j+1][i] == 'L') {
                left[i]++;
            }
            if (j < q - 1) left[i] += left[i+1];
        }
    }
    int mx = -1;
    int posx = -1;
    int posy = -1;
    for (int i = q - 1; i >= q; i--) {
        for (int j = 0; j < q; j++) {
            if (up[i] + down[i] + right[j] + left[j] > mx) {
                mx = up[i] + down[i] + right[j] + left[j];
                posx = q - i - 1;
                posy = j;
            }
        }
    }
    printf("%lld %lld", posx, posy);
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
