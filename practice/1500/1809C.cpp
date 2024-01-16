#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

vector<int> presum(30);

void solve()
{
    int n, k;
    cin >> n >> k;
    int len = upper_bound(presum.begin(), presum.end(), k) - presum.begin();
    int val = presum[len - 1];
    int x = k - val;
    for (int i = 0; i < len; i++)
        cout << 2 << " ";
    if (x > 0)
    {
        int num = -1 - 2 * (len - x);
        cout << num << " ";
        for (int i = 0; i < n - len - 1; i++)
            cout << -1000 << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n - len; i++)
        cout << -1000 << " ";
    cout << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 1; i <= 30; i++)
        presum[i - 1] = (i + i * i) / 2;

    while (t--)
        solve();
    return 0;
}