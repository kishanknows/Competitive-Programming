#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == '.' && b[i] == '.' && a[i - 1] == 'x' && a[i + 1] == 'x' && b[i - 1] == '.' && b[i + 1] == '.') res++;
        if (a[i] == '.' && b[i] == '.' && b[i - 1] == 'x' && b[i + 1] == 'x' && a[i - 1] == '.' && a[i + 1] == '.') res++;
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