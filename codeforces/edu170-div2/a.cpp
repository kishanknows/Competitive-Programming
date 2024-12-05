#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    if (s[0] != t[0]) {
        cout << s.length() + t.length() << endl;
        return;
    }
    int res = 0;
    int i = 0;
    while (i < s.length() && s[i] == t[i]) {
        res++;
        i++;
    }
    cout << i + s.length() - i + t.length() - i + 1 << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}