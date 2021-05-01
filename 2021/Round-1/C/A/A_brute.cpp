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

int calculatedist (vector <int>& a, int i, int k, int p) {
	int n = a.size();
	int dist = 0;
	if (i == n) {
		dist = k - a[n-1];
	} else {
		dist = a[i] - p - 1;
	}
	if (i != 0 && i != n) {
		if (dist % 2 == 1) dist++;
		dist /= 2;
	}
	/* if (i != n) debug(dist); */
	return dist;
}

void testcase() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort (a.begin(), a.end());
	int prev = 0;
	int ans = 0;
	for (int i = 0; i < n + 1; i++) {
		int temp = calculatedist (a, i, k, prev);
		/* debug(i, temp ; */
		int p = 0;
		for (int j = 0; j < n + 1; j++) {
			if (j != i) {
				int t2 = calculatedist (a, j, k, p);
				if (j < n) p = a[j];
				ans = max (ans, temp + t2);
			}
            if (j < n) p = a[j];
		}
        if (i == n) ans = max (ans, k - a[n-1]);
        else ans = max(ans, a[i] - prev - 1);
		if (i < n) prev = a[i];
	}
	/* debug(ans); */
	float printval = (float) ans / k;
	printf("%f", printval);
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
