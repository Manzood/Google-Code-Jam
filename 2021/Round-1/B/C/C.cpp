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

int getrand (int a, int b) {
    return a + (rand() % (b - a + 1));
}

void testcase(int n, int b, int p) {
    // cin >> n >> b >> p;
    vector <vector <int>> a(n);
    for (int q = 0; q < n * b; q++) {
        int d;
        cin >> d;
        if (d == -1) {
            return;
        }
        vector <pair <int, int>> new_order;
        for (int i = 0; i < n; i++) {
            if ((int) a[i].size() < b) {
                new_order.push_back({(int)a[i].size(), i});
            }
        }
        sort (new_order.begin(), new_order.end());
        int probability = (9 - d) * (9 - d);
        int ind = new_order[0].second;
        for (int i = new_order.size() - 1; i >= 0; i--) {
            int r = getrand (0, probability);
            if (r == 0) {
                ind = new_order[i].second;
                break;
            }
        }
        // debug(probability);
        // debug (new_order[0].second);
        cout << ind + 1 << endl;
        a[ind].push_back(d);
    }
}

int32_t main() {
    srand (time(0));
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    int n, b, p;
    cin >> n >> b >> p;
    for (int tt = 1; tt <= t; tt++) {
        // printf("Case #%lld: ", tt);
        testcase(n, b, p);
        // cout << endl;
    }
    int res;
    cin >> res;
}
