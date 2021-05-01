#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9+7;

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

string stringnot (string s) {
    string retval = "";
    int start = -1;
    /* debug(s); */
    for (int i = 0; i < (int) s.size(); i++) {
        if (start == -1 && s[i] == '1') {

        } else {
            if (start == -1) start = i;
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }
    }
    /* debug(start); */
    if (start >= 0) {
        for (int i = start; i < (int) s.size(); i++) {
            retval += s[i];
        }
    } else {
        retval = "0";
    }
    return retval;
}

void leftshift (string& s) {
    bool foundone = false;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '1') {
            foundone = true;
        }
    }
    if (foundone) s += '0';
}

int strcompare (string s, string e) {
    if (s.size() < e.size()) {
        // smaller
        return -1;
    } else {
        if (s.size() > e.size()) {
        // larger
            return 1;
        } else {
            for (int i = 0; i < (int) s.size(); i++) {
                if (s[i] > e[i]) return 1;
                else if (s[i] < e[i]) return -1;
            }        
        }
    }
    return 0;
}


void testcase() {
    // if it's larger, do a not
    // it its' smaller, do a left shift
    string s, e;
    cin >> s >> e;
    string original = s;
    /* bool isone = true; */
    /* for (int i = 0; i < (int) e.size(); i++) { */
        /* if (e[i] == '0') isone = false; */
    /* } */
    // brute force first?
    /* debug(stringnot(s)); */
    /* if (strcompare (s, e) == 0) ans = 0; */
    int moves = 0;
    int temp;
    while ((temp = strcompare (s, e)) != 0) {
        if (s.size() == 1 && s[0] == '0') {
            s = stringnot (s);
        } else if (temp == 1) {
            s = stringnot (s);
        } else {
            leftshift (s);
        }
        moves++;
        if (moves > 1000) break;
    }
    // also check complete removal
    bool allones = true;
    for (int i = 0; i < (int) e.size(); i++) {
        if (e[i] == '0') allones = false;
    }
    if (allones) moves = min(moves, (int) e.size());
    if (moves <= 1000) printf("%lld", moves);
    else printf("IMPOSSIBLE");
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
