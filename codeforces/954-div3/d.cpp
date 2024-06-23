#include <bits/stdc++.h>

#define int long long
using namespace std;

int dfsr(int cur, int n, string& s) {
    if (cur == n - 1) return (s[n - 1] - '0');
    int val = s[cur] - '0';
    return min(val + dfsr(cur + 1, n, s), val * dfsr(cur + 1, n, s));
}

int dfsl(int cur, int n, string& s) {
    if (cur == 0) return (s[0] - '0');
    int val = s[cur] - '0';
    return min(val + dfsl(cur - 1, n, s), val * dfsl(cur - 1, n, s));
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int val1 = (s[0] - '0') * 10 + (s[1] - '0');
    int val2 = (s[n - 2] - '0') * 10 + (s[n - 1] - '0');
    if (n == 2) {
        cout << val1 << endl;
        return;
    }
    int res = 1e15;
    for (int i = 2; i < n - 1; i++) {
        int val = (s[i - 1] - '0') * 10 + (s[i] - '0');
        int x = dfsl(i - 2, n, s);
        int y = dfsr(i + 1, n, s);
        res = min(res, x * val * y);
        res = min(res, x + val + y);
        res = min(res, x * val + y);
        res = min(res, x + val * y);
    }
    res = min(res, val1 * dfsr(2, n, s));
    res = min(res, val1 + dfsr(2, n, s));
    res = min(res, val2 * dfsl(n - 3, n, s));
    res = min(res, val2 + dfsl(n - 3, n, s));
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