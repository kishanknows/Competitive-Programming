#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void print(vector<int> &a)
{
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (auto m : mp)
    {
        for (auto id : m.second)
        {
            int i = id - 1, j = id + 1;
            while (i >= 0 && a[i] <= m.first && a[i] != b[i])
            {
                a[i] = m.first;
                i--;
            }
            while (j < n && a[j] <= m.first && a[j] != b[j])
            {
                a[j] = m.first;
                j++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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