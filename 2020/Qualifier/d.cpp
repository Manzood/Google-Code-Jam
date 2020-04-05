#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

vector <int> reverse (vector <int> bits, int size, int finalsize) {
	vector <int> reversed(finalsize);
	int j=size-1;
	for (int i=0;i<size;i++) {
		reversed[i]=bits[j];
		j--;
	}
	return reversed;
}

vector <int> complement (vector <int> bits, int size, int finalsize) {
	vector <int> complemented(finalsize);
	for (int i=0;i<size;i++) {
		complemented[i]=!bits[i];
	}
	return complemented;
}

pair<int,int> getnums(vector <int> bits, int size) {
	int notsame=-1, same=-1;
	for (int i=0;i<=size/2;i++) {
		if (same==-1 && bits[i]==bits[size-i-1]) {
			same=i;
		}
		if (notsame==-1 && bits[i]!=bits[size-i-1]) {
			notsame=i;
		}
	}
	return make_pair(same,notsame);
}
//if it is only reversed, same will stay constant but notsame will change
//if it is only complemented, same will change AND notsame will change
//if it is both, same will change, however, notsame will be the same
//if it is num, they will both be the same

int main() {
	int t;
	int b;
	cin>>t>>b;
	while (t--) {
		vector <int> bits(b);
		int query=1,input,pos=0,count=1;
		bool uncertain=false;
		pair <int,int> checkers;
		int state=0;
		bool same,notsame;
		bool determined=false;
		while (!determined) {
			cout<<query<<endl;
			scanf("%d",&input);
			++count;

			if (count%10==1) {
				uncertain=true;
				bits[pos]=input;
				pos++;
				state=1;
				checkers=getnums(bits,pos);
			}
			if (uncertain) {
				//logic to get next query
				if (state==1) {
					query=checkers.first+1;
					state=2;
					if (checkers.first==-1) {
						query=1;
					}
				}
				else if (state==2) {
					if (checkers.first==-1) {
						if (input!=bits[0]) {
							bits=complement(bits,pos,b);
						}
						uncertain=false;
						state=0;
						query=pos+1;
						continue;
					}
					if (input==bits[checkers.first]) {
						same=true;
					}
					else {
						same=false;
					}
					query=checkers.second+1;
					state=3;
					if (checkers.second==-1) {
						if (same==false) {
							bits=complement(bits,pos,b);
						}
						uncertain=false;
						state=0;
						query=pos+1;
					}
				}
				else if (state==3) {
					if (input==bits[checkers.second]) {
						notsame=true;
					}
					else {
						notsame=false;
					}
					query=pos+1;
					state=4;
				}
				if (state==4) {
					if (same&&notsame);
					else if (same&&!notsame) {
						//reverse
						bits=reverse(bits,pos,b);
					}
					else if (!same&&notsame) {
						//both
						bits=reverse(bits,pos,b);
						bits=complement(bits,pos,b);
					}
					else {
						//complemented
						bits=complement(bits,pos,b);
					}
					state=0;
					query=pos+1;
					uncertain=false;
				}

				if (pos>=b) {
					determined=true;
				}
			}
			else {
				//logic to get next query
				//storing input
				bits[pos]=input;
				pos++;
				query=pos+1;
				if (pos>=b) {
					determined=true;
				}
			}
			
			for (int i=0;i<pos;i++) {
				cout<<bits[i];
			}
			cout<<endl;
		}
		for (int i=0;i<b;i++) {
			cout<<bits[i];
		}
		cout<<endl;
		char ans;
		cin>>ans;
		if(ans=='N') {
			return 0;
		}
		else if (ans=='Y') {
			continue;
		}
	}
	return 0;
}