#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> dist(q);
    for (int i = 0; i < q; i++)
        cin >> dist[i];
    for (int i = 1; i < n; i++)
    {
        cout << i << " " << i + 1 << endl;
    }
    int prev = 2;
    for (auto d : dist)
    {
        if (prev == d + 1)
        {
            cout << -1 << " " << -1 << " " << -1 << endl;
            continue;
        }
        cout << 1 << " " << prev << " " << d + 1 << endl;
        prev = d + 1;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}