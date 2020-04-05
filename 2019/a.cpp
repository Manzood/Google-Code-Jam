#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main () {
    int t;
    cin>>t;
    char n[110];
    for (int test=0;test<t;test++) {
        scanf("%s",n);
        int len=strlen(n);
        vector <char> a;
        vector <char> b;
        int alen=0;
        int blen=0;
        int first=0;
        for (int i=0;i<len;i++) {
            if (n[i]!='4') {
                a.push_back(n[i]);
                if (first) {
                    b.push_back('0');
                    blen++;
                }
                alen++;
            }
            else {
                a.push_back('1');
                b.push_back('3');
                alen++;
                blen++;
                first=1;
            }
        }
        printf("Case #%d: ",test+1);
        for (int i=0;i<alen;i++) {
            printf("%c",a[i]);
        }
        printf(" ");
        for (int i=0;i<blen;i++) {
            printf("%c",b[i]);
        }
        printf("\n");
    }
}