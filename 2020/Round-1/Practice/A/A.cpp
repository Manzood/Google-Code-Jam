#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
using namespace std;

void testcase() {
    int n;
    scanf("%lld", &n);
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s;
    }
    string ans = "";
    string ansmid = "";
    string anspref = "";
    string anssuff = "";
    bool possible = true;
    for (int i = 0; i < n; i++) {
        string s = a[i];
        string pref = s.substr(0, s.find('*'));
        debug(s.find('*'));
        string rev = s;
        reverse(rev.begin(), rev.end());
        string suff = rev.substr(0, rev.find('*'));
        string mid = "";
        for (int i = pref.size(); i < (int) (s.size() - suff.size()); i++) {
            if (s[i] != '*') mid += s[i];
        }
        for (int j = 0; j < min((int)anspref.size(), (int)pref.size()); j++) {
            if (anspref[j] != pref[j]) possible = false;
        }
        if ((int)anspref.size() < (int)pref.size()) anspref = pref;
        for (int j = min((int)anssuff.size(), (int)suff.size()) - 1; j >= 0; j--) {
            if (anssuff[j] != suff[j]) possible = false;
        }
        if ((int)anssuff.size() < (int)suff.size()) anssuff = suff;
        ansmid += mid;
    }
    debug(anspref);
    debug(anssuff);
    debug(ansmid);
    ans = anspref;
    ans += ansmid;
    ans += anssuff;
    cout << ans;
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf ("Case #%lld: ", tt);
        testcase();
        printf("\n");
    }
}
