#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, id = 0, x = 0, mx = 0;
    cin >> n;
    char ch;

    for (int i = 1; i < n; i++) {
        cout << "? " << id << " " << id << " " << i << " " << i << endl;
        cout.flush();
        cin >> ch;
        if (ch == '<') {
            id = i;
        }
    }
    vector<int> idx;
    idx.push_back(x);
    for (int i = 1; i < n; i++) {
        cout << "? " << x << " " << id << " " << i << " " << id << endl;
        cout.flush();
        cin >> ch;
        if (ch == '<') {
            idx.clear();
            x = i;
            idx.push_back(x);
        }
        else if (ch == '=') {
            idx.push_back(i);
        }
    }
    int mn = idx[0];
    for (auto i : idx) {
        cout << "? " << mn << " " << mn << " " << i << " " << i << endl;
        cout.flush();
        cin >> ch;
        if (ch == '>') {
            mn = i;
        }
    }
    cout << "! " << mn << " " << id << endl;
    cout.flush();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}