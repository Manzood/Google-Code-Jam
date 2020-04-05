#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

set <long long> primes;

long long findprimes (long long val, int n) {
	if (val%2==0) {
		primes.insert(val/2,2);
		return 2;
	}
	else {
		long long div=3;
		while (div<n && div<val) {
			if (val%div==0)
				primes.insert(val/div,div);
			div+=2;
		}
		return div;
	}
}

int main () {
	int t;
	cin>>t;
	while (t--) {
		long long  n,l,value;
		scanf("%lld",&n);
		scanf("%lld",&l);
		vector <int> line;
		int previous;
		int firstprevious;
		for (int i=0;i<l;i++) {
			int num;
			scanf("%d",value);
			if (i==0) {
				num=findprimes(value);
				line.push_back(num,value/num);
				previous=value/num;
				firstprevious=num;
			}
			else {
				if (firstprevious==num) {
					
				}
			}
		}

		vector <int> primesvect;
		for (auto it=primes.begin();it!=primes.end();it++) {
			primesvect.push_back(*it);
		}
		sort (primesvect.begin(),primesvect.end());

	}
}