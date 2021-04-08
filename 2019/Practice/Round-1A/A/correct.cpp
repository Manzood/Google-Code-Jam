/**
 *    author:  tourist
 *    created: 31.03.2018 11:41:48       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(5);
  vector<int> prec[22][22];
  for (int h = 2; h <= 20; h++) {
    for (int w = 2; w <= 20; w++) {
      vector<vector<int>> g(h * w);
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          for (int ii = 0; ii < h; ii++) {
            for (int jj = 0; jj < w; jj++) {
              if (i != ii && j != jj && i - j != ii - jj && i + j != ii + jj) {
                g[i * w + j].push_back(ii * w + jj);
              }
            }
          }
        }
      }
      for (int i = 0; i < h * w; i++) {
        shuffle(g[i].begin(), g[i].end(), rng);
      }
      vector<int> cur;
      vector<int> res;
      vector<int> was(h * w, 0);
      function<void(int, int)> dfs = [&](int cnt, int v) {
        if (!res.empty()) {
          return;
        }
        cur.push_back(v);
        was[v] = 1;
        if (cnt == h * w) {
          res = cur;
        }
        for (int u : g[v]) {
          if (!was[u]) {
            dfs(cnt + 1, u);
          }
        }
        cur.pop_back();
        was[v] = 0;
      };
      for (int i = 0; i < h * w; i++) {
        dfs(1, i);
      }
      prec[h][w] = res;
//      cerr << h << " " << w << " done, res.size() = " << res.size() << '\n';
    }
  }
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int h, w;
    cin >> h >> w;
    if (prec[h][w].empty()) {
      cout << "IMPOSSIBLE" << '\n';
    } else {
      cout << "POSSIBLE" << '\n';
      for (int x : prec[h][w]) {
        cout << x / w + 1 << " " << x % w + 1 << '\n';
      }
    }
  }
  return 0;
}
