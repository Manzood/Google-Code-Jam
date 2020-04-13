#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<cstring>

using namespace std;

//A couple of things here are important
//checking if the strings match
//should probably add this to a function, you know
//changing answer
//*hello
//*cohello
//*ll*
//*
//answer=cohello

//check if ans is within
//if not, check if string provided is a subset of answer
//if not, it is not possible

int checkrest (char *str, char *ans, int strbegin) {
	int len=strlen(str);
	int anslen=strlen(ans);
	int j=0;
	for (int i=strbegin;i<len && i<strbegin+anslen;i++) {
		if (str[i]!=ans[j++]) {
			return 0;
		}
	}
	return 1;
}

int checkstring (char *str, char *ans) {
	int len=strlen(str);
	int anslen=strlen(ans);
	int ansptr=0;
	int strptr=0;
	bool star=false;
	if (anslen>len) {
		//check if str is within ans
		while (ansptr<anslen) {
			if (ans[ansptr]==str[0]) {
				if (checkrest(ans,str,ansptr)) {
					return 0;
				}
			}
			ansptr++;
		}
		return -1;
	}
	else {
		//check if ans is within str and expand to fit
		if (anslen==0) {
			return 1;
		}
		while (strptr<len) {
			if (str[strptr]==ans[0]) {
				if (checkrest(str,ans,strptr))
					return 1;
			}
			strptr++;
		}
		printf("%s\n%s\nreturning\n",str,ans);
		return -1;
	}
}

void testcase () {
	int n;
	scanf("%d",&n);
	char s[110];
	char ans[110];
	int anslen=0;
	bool star=false;
	char s2[110];
	for (int i=0;i<n;i++) {
		scanf("%s",s2);
		int len=strlen(s2);
		for (int i=1;i<len;i++) {
			s[i-1]=s2[i];
		}
		len--;
		//printf("%s",s);
		int x=checkstring(s,ans);
		if (x==1) {
			for (int j=0;j<len;j++) {
				ans[j]=s[j];
				anslen=j+1;
			}
		}
		else if (x==-1) {
			printf("*");
			return;
		}
	}
	for (int i=0;i<anslen;i++) {
		printf("%c",ans[i]);
	}
}

int main () {
	int test;
	cin>>test;
	//char teststr1[100];
	//char teststr2[100];
	//cin>>teststr1>>teststr2;
	//cout<<teststr1<<endl<<teststr2<<endl;
	//cout<<checkstring(teststr1,teststr2)<<endl;
	for (int i=1;i<=test;i++) {
		printf("Case #%d: ",test);
		testcase();
		printf("\n");
	}
}