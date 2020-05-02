#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

void testcase() {
	int x,y;
	string m;
	cin>>x>>y>>m;
	int time=0;
	if (x==0 && y==0) {
		cout<<0;
		return;
	}
	for (int i=0;i<m.size();i++) {
		if (m[i]=='N') 
			y++;
		else if (m[i]=='S') 
			y--;
		else if (m[i]=='E') {
			x++;
		}
		else {
			x--;
		}
		time++;
		if (abs(x)+abs(y)<=time) {
			cout<<time;
			return;
		}
	}
	cout<<"IMPOSSIBLE";
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