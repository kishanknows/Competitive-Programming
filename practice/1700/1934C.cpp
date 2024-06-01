#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m, a, b, c, d;
    cin >> n >> m;

    cout << "? " << 1 << " " << 1 << endl;
    cout.flush();
    cin >> a;

    int ly = max(1ll, a - n + 2);
    int lx = a + 2 - ly;
    cout << "? " << lx << " " << ly << endl;
    cout.flush();
    cin >> b;

    int rx = max(1ll, a - m + 2);
    int ry = a + 2 - rx;
    cout << "? " << rx << " " << ry << endl;
    cout.flush();
    cin >> c;

    cout << "? " << (lx - b / 2) << " " << ly + b / 2 << endl;
    cout.flush();
    cin >> d;
    if (d == 0) {
        cout << "! " << (lx - b / 2) << " " << ly + b / 2 << endl;
        cout.flush();
    }
    else {
        cout << "! " << (rx + c / 2) << " " << (ry - c / 2) << endl;
        cout.flush();
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