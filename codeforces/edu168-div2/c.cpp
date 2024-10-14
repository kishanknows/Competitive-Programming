#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = n / 2, r = n / 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') l--;
        if (s[i] == ')') r--;
    }
    vector<int> stk;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            res += (i - stk.back());
            stk.pop_back();
        }
        else if (s[i] == '(') {
            stk.push_back(i);
        }
        else {
            if (!stk.empty() && r) {
                res += (i - stk.back());
                stk.pop_back();
                r--;
            }
            else {
                stk.push_back(i);
                l--;
            }
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}