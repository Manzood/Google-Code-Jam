#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

bool compare (pair<long long, int> &x1, pair<long long, int> &x2) {
	return (x1.second>x2.second);
}

void testcase() {
	int n, d;
	cin>>n>>d;
	int temp=d;
	long long sum=0;
	vector <long long> a(n);
	vector <pair<long long, int>> b;
	vector <long long> t;
	int min;
	int count=1;
	for (int i=0;i<n;i++) {
		scanf("%lld",&a[i]);
		if (i==0) min=a[i];
		else {
			if (a[i]<min) {
				min=a[i];
				count=1;
			}
			else if (a[i]==min) {
				count++;
			}
		}
		t.push_back(a[i]);
	}
	for (int i=0;i<n;i++) {
		sum+=a[i]/min;
	}
	if (sum<d) {
		cout<<d-1;
		return;
	}
	sort (t.begin(),t.end());
	int cnt=0;
	long long prev=t[0];
	for (int i=0;i<n;i++) {
		if (t[i]==prev)
			cnt++;
		else {
			b.push_back(make_pair(prev,cnt));
			prev=t[i];
			cnt=1;
		}
	}
	b.push_back(make_pair(prev,cnt));
	sort (b.begin(),b.end(),compare);
	for (int i=0;i<b.size();i++) {
		if (b[i].second>=d) {
			cout<<0;
			return;
		}
	}
	//store the size of the multiple
	vector <int> multiples;
	set<int> used;
	for (int i=0;i<a[i];i++) {
		if (a[i]%min==0 && a[i]!=min) {
			multiples.push_back(a[i]/min);
			used.insert(i);
		}
		if (a[i]==min)
			used.insert(i);
	}
	sort (multiples.begin(),multiples.end());
	d-=count;
	//debug(count);
	int cuts=0;
	int slices=0;
	int pos=0;
	if (d<=0) {
		cout<<0;
		return;
	}
	else {
		//I have d more cuts to make;
		while (slices<d && pos<multiples.size()) {
			//debug(multiples[pos]);
			multiples[pos]--;
			slices++;
			cuts++;
			if (multiples[pos]==1) {
				pos++;
				slices++;
			}
		}
		if (slices>=d) {
			cout<<cuts;
			return;
		}
		else {
			pos=0;
			for (int i=0;i<n && slices<d;i++) {
				if (used.count(i)==0) {
					if (a[i]<min)
						pos++;
				}
				else {
					cuts++;
					slices++;
				}
			}
			if (slices>=d) {
				cout<<cuts;
				return;
			}
		}
	}
	//you have too few slices to make it happen;
	cout<<temp-1;
}

int main() {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		printf("Case #%d: ",test);
		testcase();
		printf("\n");
	}
}