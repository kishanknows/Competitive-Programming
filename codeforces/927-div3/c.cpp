#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    string s;
    cin >> s;
    map<int, int> mp1, mp2;
    deque<map<int, int>> q;
    for (auto x : a) {
        // cout << x << endl;
        map<int, int> mp;
        while (x % 2 == 0) {
            mp[2]++;
            mp1[2]++;
            x /= 2;
        }
        for (int i = 3; i < sqrt(x); i += 2) {
            while (x % i == 0) {
                mp[i]++;
                mp1[i]++;
                x /= i;
            }
        }
        if (x > 2) {
            mp[x]++;
            mp1[x]++;
        }
        q.push_back(mp);
        for (auto m : mp) {
            cout << m.first << " " << m.second << endl;
        }
        cout << endl;
    }
    cout << "----------------" << endl;
    for (auto m : mp1) {
        cout << m.first << " " << m.second << endl;
    }
    cout << "-------------------" << endl;
    while (m % 2 == 0) {
        mp2[2]++;
        m /= 2;
    }
    for (int i = 3; i < sqrt(m); i += 2) {
        while (m % i == 0) {
            mp2[i]++;
            m /= i;
        }
    }
    if (m > 2) mp2[m]++;
    for (auto m : mp2) cout << m.first << ": " << m.second << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (auto m : mp2) {
            if (m.second - mp1[m.first] <= 0) continue;
            int cur = 1;
            for (int j = 0; j < m.second - mp1[m.first]; j++) cur *= m.first;
            res += cur;
        }
        cout << res << " ";
        if (s[i] == 'L') {
            for (auto m : q.front()) {
                mp1[m.first] -= m.second;
            }
            q.pop_front();
        }
        else {
            for (auto m : q.back()) {
                mp1[m.first] -= m.second;
            }
            q.pop_back();
        }
    }
    cout << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}