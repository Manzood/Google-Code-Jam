#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<string> vec_splitter(string s) {
    s += ','; vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; } template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef local
    #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
    #define debug(...) 42
#endif

void testcase() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <pair<int, int>> ans;
    bool possible = true;
    if (n == 1 && m == 1) {
        ans = {{1, 1}};
    } else if (n > 1 && m > 2) {
        int prevx = -1000, prevy = -2000;
        for (int j = 2; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (i == prevx || j == prevy || i + j == prevx + prevy || i - j == prevx - prevy) {
                    debug(i, j);
                    possible = false;
                }
                ans.push_back({i + 1, j + 1});
                prevx = i;
                prevy = j;
                int cur = i - 1;
                if (cur < 0) cur = n - 1;
                int cury = j - 2;
                if (cury < 0) cury += m;
                ans.push_back({cur + 1, cury + 1});
                if (cur == prevx || cury == prevy || cur + cury == prevx + prevy || cur - cury == prevx - prevy) {
                    // debug(cur, cury);
                    possible = false;
                }
                prevx = cur;
                prevy = cury;
            }
        }
        ans.push_back({n, 2});
        ans.push_back({1, m - 1});
        ans.push_back({n, 1});
        ans.push_back({1, m - 2});
    } else {
        if (m == 2) {
            int prevx = -1000, prevy = -2000;
            for (int i = 0; i < n; i++) {
                int cur = i - 2;
                if (cur < 0) cur += n;
                ans.push_back({i + 1, 2});
                if (i == prevx || 1 == prevy || prevx + prevy == i + 1 || prevx - prevy == i - 1) possible = false;
                prevx = i;
                prevy = 1;
                ans.push_back({cur + 1, 1});
                if (cur == prevx || 0 == prevy || prevx + prevy == cur || prevx - prevy == cur) possible = false;
                prevx = cur;
                prevy = 0;
            }
        } else {
            possible = false;
        }
    }
    if (!possible) {
        printf("IMPOSSIBLE\n");
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%lld %lld\n", ans[i].first, ans[i].second);
        }
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
