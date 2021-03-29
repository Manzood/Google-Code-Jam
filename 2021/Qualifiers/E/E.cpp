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
    vector <int> score(n, 0);
    vector <int> questions(m, 0);
    vector <int> sorted(m, 0);
    vector <int> easyanswered(n, 0);
    vector <int> hardanswered(100, 0);
    vector <string> a(n);
    int ind = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            questions[j] += a[i][j] - '0';
            score[i] += a[i][j] - '0';
            if (score[i] > score[ind]) ind = i;
            sorted[j] = questions[j];
        }
    }
    sort(sorted.begin(), sorted.end());
    int upperbound = sorted[99];
    int lowerbound = sorted[9900];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10000; j++) {
            if (questions[j] <= upperbound) {
                if (a[i][j] == '1') {
                    hardanswered[i]++;
                }
            } else if (questions[j] >= lowerbound) {
                if (a[i][j] == '1') {
                    easyanswered[i]++;
                }
            }
        }
    }
    ind = 0;
    for (int i = 0; i < n; i++) {
        if (easyanswered[i] - hardanswered[i] < easyanswered[ind] - hardanswered[ind]) ind = i;
        if (easyanswered[i] - hardanswered[i] == easyanswered[ind] - hardanswered[ind]) {
            if (score[i] > score[ind]) ind = i;
        }
    }
    // debug(easyanswered[ind]);
    // debug(hardanswered[ind]);
    // printf("\n");
    // for  (int i = 0; i < 100; i++) {
        // printf("%lld ", hardanswered[i]);
    // }
    // printf("\n");
    // int sum = 0;
    // for (int i = 0; i < 100; i++) {
        // if (i == ind - 2) continue;
        // printf("%lld ", score[i]);
        // sum += score[i];
    // }
    // int cnt2 = 0;
    // for (int i = 0; i < m; i++) {
        // if (questions[i] < 10) cnt2++;
    // }
    // debug(cnt2);
    // printf("\n");
    // debug(hardanswered[ind]);
    // debug(sum / 99);
    // debug(score[ind]);
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
