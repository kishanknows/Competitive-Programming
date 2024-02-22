#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    if (sm % n != 0) {
        cout << "No" << endl;
        return;
    }
    int avg = sm / n;
    for (int i = 0; i < n; i++) a[i] -= avg;
    map<int, int> mp;
    for (auto x : a) {
        if (x == 0) continue;
        int cur = 1;
        while (x + cur == 0 || ((x + cur) & (x + cur - 1)) != 0) {
            cur *= 2;
            if (x + cur > INT_MAX) {
                cout << "No" << endl;
                return;
            }
        }
        mp[cur]++;
        mp[x + cur]--;
    }
    for (auto m : mp) {
        if (m.second != 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}