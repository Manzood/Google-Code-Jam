#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main() {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		int n,temp,trace=0;
		cin>>n;
		vector <vector <int> > a(n);
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				scanf("%d",&temp);
				a[i].push_back(temp);
				if (i==j) {
					trace+=temp;
				}
			}
		}
		int rowcount=0,colscount=0;
		bool rowcheck,colscheck;
		for (int i=0;i<n;i++) {
			set <int> row;
			set <int> cols;
			rowcheck=false;
			colscheck=false;
			for (int j=0;j<n;j++) {
				if (row.count(a[i][j])==1 && rowcheck==false) {
					rowcount++;
					rowcheck=true;
				}
				else {
					row.insert(a[i][j]);
				}
				if (cols.count(a[j][i])==1 && colscheck==false) {
					colscount++;
					colscheck=true;
				}
				else {
					cols.insert(a[j][i]);
				}
			}
		}
		printf("Case #%d: %d %d %d\n",test,trace,rowcount,colscount);
	}
}