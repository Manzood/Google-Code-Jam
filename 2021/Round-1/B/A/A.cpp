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

const int conversion = 12 * 1e10;
void testcase() {
    int a[3];
    scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);
    a[0] /= conversion;
    a[1] /= conversion;
    a[2] /= conversion;
    // debug(a[0], a[1], a[2]);
    bool found = false;
    for (int i = 0; i < 3; i++) {
        // picking seconds;
        int h, m, s, n;
        n = 0;
        float minutesangle = a[i] / 360.0;
        s = a[i] / 6;
        for (int j = 0; j < 3; j++) {
            // picking minutes
            if (j != i) {
                m = a[j] / 6;
                int hoursangle = a[j] / 360.0;
                for (int k = 0; k < 3; k++) {
                    // picking hours
                    if (k != j && k != i) {
                        h = a[k] / 30;
                        // debug(h);
                        if (hoursangle - a[k] % 30 > (int) 1e5) {
                            found = true;
                        }
                    }
                    if (found) break;
                }
                if (minutesangle - (a[j] % 6) > (int) 1e5) {
                    found = false;
                }
            }
            if (found) break;
        }
        if (found) {
            printf ("%lld %lld %lld %lld", h, m, s, n);
            break;
        }
    }
    if (!found) {
        printf("0 0 0 0");
    }
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
