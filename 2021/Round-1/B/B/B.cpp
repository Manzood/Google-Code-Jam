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

void testcase() {
    int n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    vector <int> A(n + 30, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    int ans = n + 100;
    bool possible = false;
    for (int i = n + 20; i >= n; i--) {
        bool satisfied = true;
        int cur = i;
        vector <int> temp (cur + 1, 0);
        temp[cur] = 1;
        while (cur >= 0) {
            int cur_available = temp[cur] - A[cur];
            if (cur_available < 0) satisfied = false;
            if (cur - a >= 0) {
                temp[cur-a] += cur_available;
            }
            if (cur - b >= 0) {
                temp[cur-b] += cur_available;
            }
            cur--;
        }
        // if (i == 3) {
            // for (int j = 0; j < n + 3; j++) {
                // printf("%lld ", temp[j]);
            // }
            // printf("\n");
            // for (int j = 0; j < n + 3; j++) {
                // printf("%lld ", A[j]);
            // }
            // printf("\n");
        // }
        if (satisfied) {
            possible = true;
            ans = i + 1;
        }
    }
    if (possible) printf("%lld", ans);
    else printf("IMPOSSIBLE");
}

int32_t main() {
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
