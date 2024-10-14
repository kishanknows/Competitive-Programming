#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int res = 0;
    string str = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            int cur = 2;
            char ch = 'a' + i;
            string tmp = "";
            for (int k = 0; k < j; k++) {
                tmp.push_back(s[k]);
            }
            tmp.push_back(ch);
            for (int k = j; k < n; k++) {
                tmp.push_back(s[k]);
            }
            for (int k = 1; k < tmp.length(); k++) {
                if (tmp[k] == tmp[k - 1]) cur++;
                else cur += 2;
            }
            if (cur > res) {
                str = tmp;
                res = cur;
            }
        }
    }
    cout << str << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}