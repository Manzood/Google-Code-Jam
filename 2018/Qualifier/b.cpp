#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define debug(x) cout<<x<<endl;

int main () {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		int n;
		scanf("%d",&n);
		vector <int> even(n/2);
		vector <int> odd(n/2+1);
		for (int i=0;i<n;i++) {
			if (i%2==0) {
				scanf("%d",&even[i/2]);
			}
			else
				scanf("%d",&odd[i/2]);
		}
		sort(even.begin(),even.end());
		sort(odd.begin(),odd.end());
		bool possible=true;
		int previous=even[0];
		int ans;
		for (int i=0;i<=n/2;i++) {
			if (previous>even[i]) {
				possible=false;
				ans=2*i;
			}
			else {
				previous=even[i];
			}
			if (previous>odd[i]) {
				possible=false;
				ans=2*i+1;
			}
			else {
				previous=odd[i];
			}
		}
		printf("Case %d: ",test);
		if (possible) printf("OK\n");
		else printf("%d\n",ans);
	}
}