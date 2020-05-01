#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>

using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

bool check(int x, int y) {
	if (x==0 && y==0) {
		return true;
	}
	if ((x/2+y/2)%2==0) 
		return false;
	return true;
}

int solve () {
	int x,y;
	scanf("%d %d",&x,&y);
	bool impossible=false;
	string ans;
	while (impossible==false && (x!=0 || y!=0)) {
		/*debug(x);
		debug(y);*/
		//debug((x+y)%2);
		if ((x+y)%2==0 && (x!=0 || y!=0)) {
			impossible=true;
			break;
		}
		if (x%2!=0) {
			int count=0;
			char move;
			if (check (x-1,y)) {
				move='E';
				count++;
			}
			if (check(x+1,y)) {
				move='W';
				count++;
			}
			if (count==0) {
				// cout<<"Entered here"<<endl;
				impossible=true;
				move='I';
			}
			if (count>1) {
				if (abs(x+y+1)>(abs(x+y-1))) {
					move='E';
				}
				else {
					move='W';
				}
			}
			if (move!='I') ans+=move;
			if (move=='E') {
				x--;
			}
			else if (move=='W') {
				x++;
			}
		}
		else {
			int count=0;
			char move;
			if (check(x,y-1)) {
				move='N';
				count++;
			}
			if (check(x,y+1)) {
				move='S';
				count++;
			}
			//debug(count);
			if (count==0) {
				// cout<<"Entered here"<<endl;
				impossible=true;
				move='I';
			}
			if (count==2) {
				if (abs(x+y+1)>abs(x+y-1)) {
					move='N';
				}
				else {
					move='S';
				}
			}
			if (move!='I') ans+=move;
			if (move=='N') {
				y--;
			}
			else if (move=='S') {
				y++;
			}
		}
		x=x/2;
		y=y/2;
	}
	if (impossible==false) {
		cout<<ans;
	}
	else {
		cout<<"IMPOSSIBLE";
	}
}


int main() {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		printf("Case #%d: ",test);
		solve();
		printf("\n");
	}
}
