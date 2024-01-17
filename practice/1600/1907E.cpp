#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

vector<int> perms(10);

void solve()
{
    int n;
    cin >> n;
    int res = 1;
    while (n)
    {
        res *= perms[n % 10];
        n /= 10;
    }
    cout << res << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int cur = 0; cur < 10; cur++)
    {
        for (int i = 0; i <= cur; i++)
        {
            for (int j = 0; i + j <= cur; j++)
            {
                int k = cur - i - j;
                perms[cur]++;
            }
        }
    }
    while (t--)
        solve();
    return 0;
}