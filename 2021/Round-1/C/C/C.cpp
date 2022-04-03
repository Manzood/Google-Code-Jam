#include "bits/stdc++.h"
using namespace std;
#define int long long
/* const int mod = 1e9+7; */

vector<string> vec_splitter(string s) {
	s += ','; vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
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

int checkthreedigits (string s, int start, int p) {
    if (p == -1) {
        if (start + 2 >= (int) s.size()) return 0;
        else p = s[start] + s[start+1] + s[start+2] - '0' - '0' - '0';
        start += 3;
    }
    if (p == 999) return 0;
    while (start + 3 < (int) s.size()) {
        int num = (s[start] - '0') * 100 + (s[start + 1] - '0') * 10 + s[start+2] - '0';
        if (num <= p) {
            return 0;
        }
        p = num;
        if (p == 999) return 0;
        start += 3;
    }
    if (start != (int) s.size()) return 0;
    return 1;
}

int checktwodigits (string s, int start, int p) {
    if (p == -1) {
        if (start + 1 >= (int) s.size()) return 0;
        else p = s[start] + s[start+1] - '0' - '0';
        start += 2;
    }
    if (p == 99) return checkthreedigits (s, start, p);
    while (start + 1 < (int) s.size()) {
        int num = (s[start] - '0') * 10 + (s[start + 1]) - '0';
        if (num <= p) {
            return 0;
        }
        p = num;
        if (p == 99) return checkthreedigits (s, start, p);
        start += 2;
    }
    if (start + 1 == (int) s.size()) return 0;
    return 1;
}

int checkonedigit (string s) {
    // one at a time, two at a time, three at a time
    int start = 0;
    while (start < (int) s.size() && s[start] == '0') start++;
    int p = s[0] - '0';
    for (int i = start; i < s.size(); i++) {
        if (p < '9' - '0') {
            if (s[i] != p + 1 + '0') {
                return 0;
            } else {
                p = s[i] - '0';
            }
        } else {
            return checktwodigits (s, start, p);
        }
    }
    return 1;
}

void testcase() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool found = false;
        while (!found) {
            if (checkonedigit(s)) found = true;
            if (checktwodigits(s, 0, -1)) found = true;
            if (checkthreedigits(s, 0, -1)) found = true;
            for (int i = (int) s.size() - 1; i >= 0; i--) {
            }
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
