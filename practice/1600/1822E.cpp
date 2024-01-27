#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        cout << -1 << endl;
        return;
    }
    vector<int> cnt(26);
    for (char ch : s) {
        cnt[ch - 'a']++;
        if (cnt[ch - 'a'] > n / 2) {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> sim(26, 0);
    int pairs = 0, mx = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]) {
            sim[s[i] - 'a']++;
            mx = max(mx, sim[s[i] - 'a']);
            pairs++;
        }
    }
    cout << max((pairs + 1) / 2, mx) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}