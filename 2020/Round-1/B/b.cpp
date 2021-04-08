#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
const int MX = 1e9;

vector <pair<int,int>> iqueries;
void init () {
	iqueries.emplace_back(0,0);
	iqueries.emplace_back(-MX/2,MX/2);
	iqueries.emplace_back(-MX/2,-MX/2);
	iqueries.emplace_back(MX/2,-MX/2);
	iqueries.emplace_back(MX/2,MX/2);
}

int initialquery(int val) {
	string response;
	cout<<iqueries[val].first<<" "<<iqueries[val].second<<endl;
	cin>>response;
	while (response=="MISS") {
		cout<<iqueries[++val].first<<" "<<iqueries[val].second<<endl;
		cin>>response;
	}
	if (response=="CENTER") {
		return 101;
	}
	else if (response=="HIT") {
		return val;
	}
	else if (response=="WRONG") {
		return 404;
	}
}

pair<int,int> binarysearch (int a, int b, int parity) {
	if (parity) {
		return make_pair(a,(b-(b-a)/2));
	}
	else {
		return make_pair(a+(b-a)/2,b);
	}
}

//get the queries for x, y
//should be easy
int xquery (int x1, int x2) {
	int parity=0;
	pair<int,int> temp;

	while (x1!=x2) {
		binarysearch(x1,x2,parity);
	}


int testcase testcase(int a, int b) {
	bool firsthit=false;
	int initial;
	while (firsthit==false) {
		initial=initialquery(0);
	}
	if (initial==101 || initial==404) 
		return initial;
	
}

int main() {
	int t;
	cin>>t;
	int a,b;
	cin>>a>>b;
	init();
	int ans;
	for (int test=1;test<=t;test++) {
		printf("Case #%d: ",test);
		ans=testcase(a,b);
		if (ans==404) {
			break;
		}
	}
}