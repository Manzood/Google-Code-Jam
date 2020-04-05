#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<cstring>

using namespace std;

int main () {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		char s[110];
		scanf("%s",s);
		int len=strlen(s);
		int left=0,right=0;
		int previous='0';
		printf("Case #%d: ",test);
		for (int i=0;i<len;i++) {
			int temp=s[i]-previous;
			if (s[i]>previous) {
				for (int j=0;j<temp;j++) {
					printf("(");
					left++;
				}
			}
			else if (s[i]<previous) {
				for (int j=0;j>temp;j--) {
					printf(")");
					right++;
				}
			}
			printf("%c",s[i]);
			previous=s[i];
		}
		for (int i=right;i<left;i++) {
			printf(")");
		}
		printf("\n");
	}
}