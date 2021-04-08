#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

vector <vector <int> > getpascal () {
	vector <vector <int> > grid(30);
	for (int i=0;i<30;i++) {
		for (int j=0;j<=i;j++) {
			if (i==0 || j==i || j==0) {
				grid[i].push_back(1);
			}
			else {
				grid[i].push_back(grid[i-1][j-1]+grid[i-1][j]);
			}
		}
	}
	return grid;
}

vector <int> getbin (int n) {
	vector <int> bin;
	int size=0;
	while (n>0) {
		if (n%2==1) {
			bin.push_back(1);
		}
		else {
			bin.push_back(0);
		}
		n/=2;
		size++;
	}
	return bin;
}

//19

//10011

void testcase (vector <vector <int> > grid) {
	int n;
	scanf("%d",&n);
	vector <int> bin;
	int size,ones;
	if (n>30) {
		bin=getbin(n-30);
		size=bin.size();
		ones=0;
		for (int i=0;i<size;i++) {
			if (bin[i]==1) {
				ones++;
			}
			//printf("%d",bin[i]);
		}
		//printf("\n%d\n",size);
	}
	int sum=0;
	int side=0;
	if (n>30) {
		for (int i=0;i<30;i++) {
			if (i<size&&bin[i]==1) {
				if (side==0) {
					for (int j=0;j<=i;j++) {
						printf("%d %d\n",i+1,j+1);
						sum+=grid[i][j];
					}
				}
				else {
					for (int j=i;j>=0;j--) {
						printf("%d %d\n",i+1,j+1);
						sum+=grid[i][j];
					}
				}
				if (side==1) {
					side=0;
				}
				else {
					side=1;
				}
			}
			else {
				if (side==0) {
					printf("%d 1\n",i+1);
				}
				else {
					printf("%d %d\n",i+1,i+1);
				}
			}
		}
		for (int i=0;i<ones;i++) {
			if (side==0) {
				printf("%d 1\n",i+31);
			}
			else {
				printf("%d %d\n",i+31,i+31);
			}
		}
	}
	else {
		for (int i=0;i<n;i++) {
			printf("%d 1\n",i+1);
		}
	}
}

int main () {
	int t;
	cin>>t;
	vector <vector <int> > grid(30);
	grid = getpascal();
	for (int test=1;test<=t;test++) {
		printf("Case #%d:\n",test);
		testcase(grid);
		//cin>>r>>c;
		//cout<<getpascal(r,c)<<endl;
		//printf("\n");
	}
}