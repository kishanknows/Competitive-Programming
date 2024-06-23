#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ind(m);
    for (int i = 0; i < m; i++) cin >> ind[i];
    string c;
    cin >> c;
    sort(ind.begin(), ind.end());
    sort(c.begin(), c.end());
    // cout << c << endl;
    int l = 0, r = m - 1;
    int i = 0;
    string res = "";
    while (i < m) {
        while (ind[i] == ind[i + 1]) {
            res.push_back(c[r]);
            r--;
            i++;
        }
        res.push_back(c[l]);
        l++;
        i++;
    }
    for (int i = 0; i < m; i++) {
        s[ind[i] - 1] = res[i];
    }
    cout << s << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}