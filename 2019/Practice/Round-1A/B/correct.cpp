/**
 *    author:  tourist
 *    created: 31.03.2018 11:41:48       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt, n, g;
  cin >> tt >> n >> g;
  for (int qq = 1; qq <= tt; qq++) {
    const int MAX = (int) 1e6 + 10;
    vector<int> likelihood(MAX, 0);
    for (int x : {16, 9, 5, 7, 11, 13, 17}) {
      for (int i = 0; i < 18; i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << x;
      }
      cout << endl;
      int sum = 0;
      for (int i = 0; i < 18; i++) {
        int foo;
        cin >> foo;
        sum = (sum + foo) % x;
      }
      for (int i = sum; i < MAX; i += x) {
        likelihood[i]++;
      }
    }
    int ans = -1;
    for (int i = 1; i < MAX; i++) {
      if (likelihood[i] == 7) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
    int verdict;
    cin >> verdict;
    assert(verdict == 1);
  }
  return 0;
}
