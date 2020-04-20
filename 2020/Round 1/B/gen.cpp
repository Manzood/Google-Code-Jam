#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a+rand()%(b-a+1);
}

int main (int argc, char*argv[]) {
	srand(atoi(argv[1]));
	int n=rand(2,20);
	printf("%d\n",n);
	set <pair<int,int> > used;
	for (int i=0;i<n;i++) {
		int x,y;
		pair<int,int> p;
		do {
			x=rand(-4,4);
			y=rand(-4,4);
			p=make_pair(x,y);
		} while (used.count(p) && (x!=0||y!=0));
		used.insert(p);
		printf("%d %d\n",x,y);
	}
	puts("");
}