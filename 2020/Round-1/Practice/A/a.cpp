#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<string>

using namespace std;

string findprefix(string s) {
	string prefix=s.substr(0,s.find('*'));
	return prefix;
}

string findsuffix(string s) {
	string suffix;
	bool found=false;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='*') {
			suffix.resize(0);
			found=true;
		}
		else {
			suffix+=s[i];
		}
	}
	if (!found)
		suffix.resize(0);
	return suffix;
}

int compareprefix (string ansprefix, string prefix) {
	int len1=prefix.size();
	int len2=ansprefix.size();
	for (int i=0;i<min(len1,len2);i++) {
		if (ansprefix[i]!=prefix[i]) {
			return 0;
		}
	}
	return 1;
}

int comparesuffix (string anssuffix, string suffix) {
	int len1=suffix.size();
	int len2=anssuffix.size();
	for (int i=min(len1,len2)-1;i>=0;i--) {
		//printf("%c %c\n",anssuffix[i+len2-min(len1,len2)],suffix[i+len1-min(len1,len2)]);
		if (anssuffix[i+len2-min(len1,len2)]!=suffix[i+len1-min(len1,len2)]) {
			return 0;
		}
	}
	return 1;
}

void testcase() {
	int n;
	scanf("%d",&n);
	bool possible=true;
	string prefix,suffix,mid,current;
	string ansprefix,ansmid,anssuffix;
	for (int i=0;i<n;i++) {
		cin>>current;
		int len=current.size();
		prefix=findprefix(current);
		suffix=findsuffix(current);
		if (prefix.size()!=len && suffix.size()!=len-1) {
			mid=current.substr(current.find('*')+1,len-suffix.size()-2-prefix.size());
		}
		if (ansprefix.size()==0) {
			ansprefix=prefix;
		}
		else {
			if (!compareprefix(ansprefix,prefix)) {
				possible=false;
			}
			else {
				if (prefix.size()>ansprefix.size()) {
					ansprefix=prefix;
				}
			}
		}
		if (anssuffix.size()==0) {
			anssuffix=suffix;
		}
		else {
			//compare suffix
			if (!comparesuffix(anssuffix,suffix)) {
				possible=false;
			}
			else {
				if (suffix.size()>anssuffix.size()) {
					anssuffix=suffix;
				}
			}
		}
		ansmid+=mid;
	}
	if (possible==true) {
		cout<<ansprefix;
		for (int i=0;i<ansmid.size();i++) {
			if (ansmid[i]!='*') {
				cout<<ansmid[i];
			}
		}
		cout<<anssuffix; 
	}
	else {
		cout<<'*';
	}
}


int main () {
	int t;
	cin>>t;
	for (int test=1;test<=t;test++) {
		printf("Case #%d: ",test);
		testcase();
		printf("\n");
	}
}