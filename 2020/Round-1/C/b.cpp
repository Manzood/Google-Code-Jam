#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define int long long

void testcase() {
	int u;
	cin>>u;
	map <char, int> mp;
	for (int i=0;i<10000;i++) {
		string a;
		int temp;
		cin>>temp;
		getchar();
		cin>>a;
		for (char x: a) {
			mp[x]++;
		}
	}
	vector <int> occurances;
	for (auto x: mp) {
		occurances.push_back(x.second);
		// debug(x.first);
		// debug(x.second);
	}
	string res;
	sort(occurances.begin(),occurances.end());
	for (auto x: mp) {
		if (x.second==occurances[0])
			res+=x.first;
	}
	for (int i=occurances.size()-1;i>0;i--) {
		for (auto x: mp) {
			if (x.second==occurances[i]) {
				res+=x.first;
				break;
			}
		}
	}
	cout<<res;
}

int32_t main() {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		printf("Case #%lld: ",test);
		testcase();
		printf("\n");
	}
}