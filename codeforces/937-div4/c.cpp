#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    string s;
    cin >> s;
    string st;
    st.push_back(s[0]);
    st.push_back(s[1]);
    string mm = ":";
    mm.push_back(s[3]);
    mm.push_back(s[4]);
    int h = stoi(st);
    if (h == 0) {
        cout << "12" << mm << " AM" << endl;
    }
    else if (h == 12) {
        cout << s << " PM" << endl;
    }
    else if (h > 12) {
        h -= 12;
        if (h < 10) {
            cout << "0" << h << mm << " PM" << endl;
        }
        else cout << h << mm << " PM" << endl;
    }
    else {
        cout << s << " AM" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}