#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve()
{
    int k;
    cin >> k;
    vector<int> digits;
    while (k)
    {
        digits.push_back(k % 9);
        k /= 9;
    }
    reverse(digits.begin(), digits.end());
    for (auto d : digits)
        cout << (d >= 4 ? d + 1 : d);
    cout << endl;
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