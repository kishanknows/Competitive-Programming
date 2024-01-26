#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int t, q, n = s1.length();
    cin >> t >> q;
    int cur = 0;
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) st.insert(i + 1);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < q; i++) {
        int typ;
        cin >> typ;
        while (!pq.empty() && cur - pq.top().first >= t) {
            st.insert(pq.top().second);
            pq.pop();
        }
        if (typ == 1) {
            int id;
            cin >> id;
            if (st.find(id) == st.end()) continue;
            st.erase(id);
            pq.push({ cur, id });
        }
        else if (typ == 2) {
            int x, y, p, q;
            cin >> x >> p >> y >> q;
            if (st.find(p) != st.end()) st.erase(p);
            if (st.find(q) != st.end()) st.erase(q);
            if (x == 1 && y == 1) swap(s1[p - 1], s1[q - 1]);
            else if (x == 2 && y == 2) swap(s2[p - 1], s2[q - 1]);
            else if (x == 1 && y == 2) swap(s1[p - 1], s2[q - 1]);
            else swap(s2[p - 1], s1[q - 1]);
            if (s1[p - 1] != s2[p - 1]) st.insert(p);
            if (s1[q - 1] != s2[q - 1]) st.insert(q);
        }
        else {
            cout << (st.empty() ? "YES" : "NO") << endl;
        }
        cur++;
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