#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

//store the start activity with the index as a pair, so that when it's sorted and you check, you can just go to the index to store the answer
//genius

int main () {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		int n;
		scanf("%d",&n);
		vector <pair <int,int> > start(n);
		vector <int> end(n);
		for (int i=0;i<n;i++) {
			int temp;
			scanf("%d",&temp);
			start[i]=make_pair(temp,i);
			scanf("%d",&end[i]);
		}
		sort(start.begin(),start.end());
		vector <int> ans(n);
		int cend=0;
		int jend=0;
		bool impossible=false;
		for (int i=0;i<n;i++) {
			if (start[i].first<cend) {
				if (start[i].first<jend) {
					impossible=true;
				}
				else {
					ans[start[i].second]='J';
					jend=end[start[i].second];
				}
			}
			else {
				ans[start[i].second]='C';
				cend=end[start[i].second];
			}
		}
		printf("Case #%d: ",test);
		if (impossible) {
			printf("IMPOSSIBLE");
		}
		else {
			for (int i=0;i<n;i++) {
				printf("%c",ans[i]);
			}
		}
		printf("\n");
	}
}