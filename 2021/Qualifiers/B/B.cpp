#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
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

int getcost (string& s, int ind, int x, int y) {
    int cost = 0;
    if (ind > 0) {
        if (s[ind] == 'J') {
            if (s[ind - 1] == 'C') {
                cost += x;
            }
        }
        if (s[ind] == 'C') {
            if (s[ind - 1] == 'J') {
                cost += y;
            }
        }
    }
    return cost;
}

void testcase() {
    int x, y;
    scanf("%lld%lld", &x, &y);
    string s;
    cin >> s;
    debug(s);
    int n = s.size();
    int cost = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        int curj = 0;
        if (s[i] == '?') {
            s[i] = 'C';
            cur = getcost (s, i, x, y);
            if (i < n - 1) cur += getcost (s, i + 1, x, y);
            s[i] = 'J';
            curj = getcost (s, i, x, y);
            if (i < n - 1) curj += getcost (s, i + 1, x, y);
            if (curj > cur) s[i] = 'C';
            cost += getcost (s, i, x, y);
        } else {
            cost += getcost (s, i, x, y);
        }
        debug(i, s[i]);
        debug(i, cost);
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
