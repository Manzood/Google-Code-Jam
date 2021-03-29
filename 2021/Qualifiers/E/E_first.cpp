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
    int n = 100;
    int m = 10000;
    vector <int> score(100, 0);
    int ind = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            int temp = s[j] - '0';
            score[i] += temp;
        }
        if (score[i] > score[ind]) ind = i;
    }
    printf("\n");
    for (int i = 0; i < 100; i++) {
        printf("%lld ", score[i]);
    }
    printf("\n");
    debug(score[ind]);
    printf("%lld", ind + 1);
}

int32_t main() {
    int t = 1;
    cin >> t;
    int p;
    cin >> p;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
