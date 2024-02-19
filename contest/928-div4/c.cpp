#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int> res(200001);

void solve() {
    int n;
    cin >> n;
    cout << res[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= 200000; i++) {
        int cur = 0;
        int x = i;
        while (x) {
            cur += x % 10;
            x /= 10;
        }
        res[i] = res[i - 1] + cur;
    }
    while (t--) solve();
    return 0;
}