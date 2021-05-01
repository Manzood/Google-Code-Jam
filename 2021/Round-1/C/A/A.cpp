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

void testcase() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.begin(), a.end());
    int prev = 0;
    int ans = -1;
    int leftendval = a[0] - 1;
    int rightendval = k - a[n-1];
    int largestnewdist = -1;
    for (int i = 0; i < n; i++) {
        int dist = a[i] - prev - 1;
        ans = max (dist, ans);
        int newdist = dist;
        if (newdist % 2 == 1) newdist++;
        newdist /= 2;
        /* debug(newdist); */
        /* debug(newdist); */
        if (prev > 0) ans = max (ans, newdist + leftendval);
        if (prev > 0) ans = max (ans, newdist + rightendval); 
        if (prev > 0) ans = max (ans, newdist + largestnewdist);
        largestnewdist = max (newdist, largestnewdist);
        prev = a[i];
    }
    /* debug(leftendval); */
    ans = max (leftendval + rightendval, ans);
    ans = max (ans, k - prev - 1);
    float printval = (float) ans / k;
    /* printf("%lld ", ans); */
    printf("%f", printval);
    /* cout << printval; */
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
