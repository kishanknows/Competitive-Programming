#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k, p;
    cin >> n >> k;
    string s;
    cin >> s;
    char ch = s[n - 1];
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (ch != s[i]) {
            cnt = n - i - 1;
            break;
        }
    }
    if (cnt >= k) {
        cout << -1 << endl;
        return;
    }
    map<int, int> mp;
    int i = 0, j = 0;
    while (i < n) {
        j = i;
        char cur = s[i];
        if (cur != ch) {
            i++;
            continue;
        }
        int cnt = 0;
        while (j < n && s[j] == cur) {
            cnt++;
            j++;
        }
        mp[cnt % k] = i;
        i = j;
    }
    if (mp.find(k - cnt) != mp.end()) {
        p = mp[k - cnt] + k - cnt;
        cout << p << endl;
        return;
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}