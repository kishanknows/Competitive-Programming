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
    if (n == 1) {
        cout << '1' << endl;
        return;
    }
    for (int i = 0; (i < n / 2); i++) {
        cout << '1';
        for (int j = 0; j < i; j++) cout << '0';
        cout << '6';
        for (int j = 0; j < i; j++) cout << '0';
        cout << '9';
        for (int j = 0; j < n - 3 - 2 * i; j++) cout << '0';
        cout << endl;
    }
    for (int i = 0; (i < n / 2); i++) {
        cout << '9';
        for (int j = 0; j < i; j++) cout << 0;
        cout << '6';
        for (int j = 0; j < i; j++) cout << 0;
        cout << '1';
        for (int j = 0; j < n - 3 - 2 * i; j++) cout << '0';
        cout << endl;
    }
    cout << "196";
    for (int i = 0; i < n - 3; i++) cout << '0';
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