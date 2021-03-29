#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define int long long

void reverse (vector <int>& a, int x, int y) {
    for (int i = x; i <= x + (y - x) / 2; i++) {
        swap(a[i], a[y + x - i]);
    }
}

void testcase() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[ind]) {
                ind = j;
            }
        }
        reverse (a, i , ind);
        cost += ind - i + 1;
    }
    printf("%lld", cost);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
