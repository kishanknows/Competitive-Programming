#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    int pos;
    string s;
    cin >> s >> pos;
    int n = s.length();
    int count = 0;
    while (pos > n) {
        pos -= n;
        n--;
        count++;
    }
    vector<int> stk;
    vector<int> idx;
    for (int i = 0; i < s.length(); i++) {
        if (stk.empty()) {
            stk.push_back(i);
            continue;
        }
        while (!stk.empty() && s[stk.back()] > s[i]) {
            idx.push_back(stk.back());
            stk.pop_back();
        }
        stk.push_back(i);
    }
    while (!stk.empty()) {
        idx.push_back(stk.back());
        stk.pop_back();
    }
    set<int> st;
    for (int i = 0; i < count; i++) st.insert(idx[i]);
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        if (st.find(i) != st.end()) continue;
        res.push_back(s[i]);
    }
    cout << res[pos - 1];

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}