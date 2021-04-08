#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "



void test_case() {
	int x, y;
	scanf("%d%d", &x, &y);
	bool x_negative = x < 0;
	bool y_negative = y < 0;
	x = abs(x);
	y = abs(y);
	string dp[33][2][2];
	for(int i = 0; i < 33; ++i) {
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k) {
				dp[i][j][k] = "X";
			}
		}
	}
	// vector<vector<string>> dp(32, vector<string>(3, "X"));
	dp[0][0][0] = "";
	for(int i = 0; i < 32; ++i) {
		for(bool inc_x : {false, true}) {
			for(bool inc_y : {false, true}) {
				if(dp[i][inc_x][inc_y] != "X") {
					if(!inc_x && !inc_y) {
						bool ok = true;
						for(int j = i; j <= 32; ++j) {
							if(((long long) (x|y) & (1LL << j))) {
								ok = false;
							}
						}
						if(ok) {
							debug() << imie(i) imie(inc_x) imie(inc_y);
							cout << dp[i][inc_x][inc_y] << endl;
							return;
						}
					}
					for(char nxt : { 'N', 'S', 'W', 'E' }) {
						debug() << imie(nxt);
						int bit_x = inc_x;
						int bit_y = inc_y;
						if(nxt == 'S') bit_y += (y_negative ? -1 : +1);
						if(nxt == 'N') bit_y -= (y_negative ? -1 : +1);
						if(nxt == 'E') bit_x -= (x_negative ? -1 : +1);
						if(nxt == 'W') bit_x += (x_negative ? -1 : +1);
						bit_x += bool((long long) x & (1LL << i));
						bit_y += bool((long long) y & (1LL << i));
						if(bit_x % 2 || bit_y % 2 || bit_x < 0 || bit_y < 0) {
							continue;
						}
						dp[i+1][bit_x/2][bit_y/2] = dp[i][inc_x][inc_y] + string(1, nxt);
						debug() << imie(i+1) imie(bit_x) imie(bit_y) imie(dp[i+1][bit_x/2][bit_y/2]) imie(nxt);
					}
				}
			}
		}
	}
	debug() << imie(dp[1][0][1]);
	cout << "IMPOSSIBLE" << endl;
	// string answer = dp[31][0][0];
	// if(answer == "X") {
		// cout << "IMPOSSIBLE" << endl;
	// }
	// else {
		// cout << answer << endl;
	// }
	// cout << dp[31][0] 
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}