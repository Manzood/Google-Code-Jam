#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int main () {
	int t;
	cin>>t;
	char s[1000000];
	for (int test=1;test<=t;test++) {
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		int len=strlen(s);
		printf("Case #%d: ",test);
		for (int i=0;i<len;i++) {
			if (s[i]=='E') {
				printf("S");
			}
			else {
				printf("E");
			}
		}
		printf("\n");
	}
}