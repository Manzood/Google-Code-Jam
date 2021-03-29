#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define int long long

vector <string> vec_splitter(string s) {
	s += ','; vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out(vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>

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

void reverse (vector <int>& a, int x, int y) {
    for (int i = x; i <= x + (y - x) / 2; i++) {
        swap(a[i], a[y + x - i]);
    }
}

void testcase() {
    int n, c;
    scanf("%lld%lld", &n, &c);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    bool possible = true;
    if (c < n - 1) possible = false;
    int val = n - 1;
    c -= n - 1;
    vector <int> to_reverse(n);
    for (int i = 0; i < n - 1; i++) {
        to_reverse[i] = 0;
        // debug(i, val);
        if (c > val) {
            // reverse (a, i, n - 1);
            to_reverse[i] = 1;
            c -= val;
        } else if (c == val) {
            // reverse (a, i, n - 1);
            to_reverse[i] = 1;
            c -= val;
        }
        val--;
    }
    if (c > 0) {
        possible = false;
    }
    // debug(c);
    if (possible) {
        vector <int> ans(n);
        int startptr = 0, endptr = n - 1;
        int dir = 1;
        for (int i = 0; i < n; i++) {
            if (to_reverse[i]) {
                dir ^= 1;
            }
            if (dir) {
                ans[startptr++] = i + 1;
            } else {
                ans[endptr--] = i + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
    } else {
        printf("IMPOSSIBLE");
    }
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
