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
    char trump; cin >> trump;
    map<char, vector<int>> mp;
    for (int i = 0; i < 2 * n; i++) {
        string st;
        cin >> st;
        mp[st[1]].push_back(st[0] - '0');
    }
    int cnt = 0;
    for (auto m : mp) {
        int len = m.second.size();
        if (len % 2 == 1 && m.first != trump) cnt++;
    }
    int tsize = mp[trump].size();
    if ((tsize - cnt < 0) || (tsize - cnt) % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        sort(it->second.rbegin(), it->second.rend());
    }
    for (auto m : mp) {
        if (m.first == trump) continue;
        while (!m.second.empty()) {
            int x = m.second.back();
            cout << x << m.first << " ";
            m.second.pop_back();
            if (!m.second.empty()) {
                cout << m.second.back() << m.first << endl;
                m.second.pop_back();
            }
            else {
                cout << mp[trump].back() << trump << endl;
                mp[trump].pop_back();
            }
        }
    }
    while (!mp[trump].empty()) {
        cout << mp[trump].back() << trump << " ";
        mp[trump].pop_back();
        cout << mp[trump].back() << trump << endl;
        mp[trump].pop_back();
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}