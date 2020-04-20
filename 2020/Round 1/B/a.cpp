#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

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

vector <int> getnegative(int num) {
	int temp=1;
	int count=1;
	while (temp<num) {
		temp*=2;
		count++;
	}
	int diff=temp-num;
	vector <int> neg=getbin(diff);
	vector <int> res(count);
	for (int i=0;i<neg.size();i++) {
		if (neg[i]==1) {
			res[i]=-1;
		}
	}
	res[count-1]=1;
	return res;
}

bool check (vector <int> a, vector <int> b) {
	for (int i=0;i<a.size() && i<b.size();i++) {
		if (a[i]!=0 && b[i]!=0) {
			return false;
		}
		else if (a[i]==0 && b[i]==0) {
			return false;
		}
	}
	if (a.size()>b.size()) {
		for (int i=b.size();i<a.size();i++) {
			if (a[i]==0) {
				return false;
			}
		}
	}
	if (b.size()>a.size()) {
		for (int i=a.size();i<b.size();i++) {
			if (b[i]==0) {
				return false;
			} 
		}
	}
	return true;
}

void printans(vector <int> a, vector <int> b, bool negx,bool negy) {
	char east='E', west='W',north='N',south='S',temp;
	if (negx==true) {
		temp=west;
		west=east;
		east=temp;
	}
	if (negy==true) {
		temp=south;
		south=north;
		north=temp;
	}
	for (int i=0;i<min(a.size(),b.size());i++) {
		if (a[i]==1) {
			cout<<east;
		}
		else if (a[i]==-1) {
			cout<<west;
		}
		else if (b[i]==1) {
			cout<<north;
		}
		else {
			cout<<south;
		}
	}
	if (a.size()>b.size()) {
		for (int i=b.size();i<a.size();i++) {
			if (a[i]==1) {
				cout<<east;
			}
			else if (a[i]==-1) {
				cout<<west;
			}
		}
	}
	else {
		for (int i=a.size();i<b.size();i++) {
			if (b[i]==1) {
				cout<<north;
			}
			else {
				cout<<south;
			}
		}
	}
}

void testcase(int test) {
	int x,y;
	cin>>x>>y;
	printf("Case #%d: ",test);
	int xpos=0,ypos=0;
	if ((x+y)%2==0) {
		printf("IMPOSSIBLE");
		return;
	}
	bool negx=false,negy=false;
	if (x<0) {negx=true;x=-x;}
	if (y<0) {negy=true;y=-y;}
	if (x+y==5) {
		if ((abs(x)==1 || abs(y)==1) && (abs(x)==4 || abs(y)==4)) {
			char east='E', west='W',north='N',south='S',temp;
			if (negx==true) {
				temp=west;
				west=east;
				east=temp;
			}
			if (negy==true) {
				temp=south;
				south=north;
				north=temp;
			}
			if (abs(x)==1) {
				cout<<west<<east<<north;
			}
			else {
				cout<<south<<north<<east;
			}
			return;
		}
	}
	vector <int> xmoves=getbin(x);
	vector <int> ymoves=getbin(y);
	if (check(xmoves,ymoves)) {
		printans(xmoves,ymoves,negx,negy);
		return;
	}
	vector <int> yneg=getnegative(y);
	if (check(xmoves,yneg)) {
		printans(xmoves,yneg,negx,negy);
		return;
	}
	vector <int> xneg=getnegative(x);
	if (check(xneg,yneg)) {
		printans(xneg,yneg,negx,negy);
		return;
	}
	if (check(xneg,ymoves)) {
		printans(xneg,ymoves,negx,negy);
		return;
	}
	printf("IMPOSSIBLE");
}

int main() {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		testcase(test);
		printf("\n");
	}
}