#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int rand(int a, int b) {
    return a + (rand() % (b - a + 1));
}

void solve([[maybe_unused]] int test) {
    int n = 100;
    cin >> n;
    assert(n == 100);
    set <int> nums;
    vector <int> pows;
    for (int i = 0; i < 30; i++) {
        nums.insert(1LL << i);
        pows.push_back(1LL << i);
    }
    // debug(nums);
    int cur = 1;
    vector <int> others;
    for (int i = 0; i < 70; i++) {
        while (nums.count(cur * 2)) cur++;
        nums.insert(cur * 2);
        others.push_back(cur * 2);
    }
    for (int i = 0; i < 30; i++) {
        cout << pows[i] << " ";
    }
    for (int i = 0; i < 70; i++) {
        cout << others[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        others.push_back(temp);

        // int temp;
        // do {
        //     temp = rand(1, 1000);
        // } while (nums.count(temp));
        // nums.insert(temp);
        // others.push_back(temp);
    }
    sort(others.begin(), others.end());
    reverse(others.begin(), others.end());
    int a = 0, b = 0;
    vector <int> A;
    for (int i = 0; i < (int) others.size(); i++) {
        if (a < b) {
            a += others[i];
            A.push_back(others[i]);
        } else {
            b += others[i];
        }
    }
    // debug (a, b);
    for (int i = (int) pows.size() - 1; i >= 0; i--) {
        if (a < b) {
            a += pows[i];
            A.push_back(pows[i]);
        } else {
            b += pows[i];
        }
        // debug(a, b, abs(a - b), pows[i]);
    }
    // debug(a, b);
    assert(a == b);
    for (auto x: A) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
