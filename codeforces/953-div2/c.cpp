#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    int cur = 0;
    int i = 1, j = n;
    while (i < j) {
        if (k >= (n - 2 * i + 1) + (n - 2 * (n - j + 1) + 1)) {
            k -= (n - 2 * i + 1) + (n - 2 * (n - j + 1) + 1);
            swap(a[i], a[j]);
        }
        else if (k >= (n - 2 * i + 1) + (n - 2 * (n - j + 2) + 1)) {
            k -= (n - 2 * i + 1) + (n - 2 * (n - j + 2) + 1);
            j--;
            swap(a[i], a[j]);
        }
        else if (k >= (n - 2 * (i + 1) + 1) + (n - 2 * (n - j + 1) + 1)) {
            k -= (n - 2 * (i + 1) + 1) + (n - 2 * (n - j + 1) + 1);
            i++;
            swap(a[i], a[j]);
        }
        i++; j--;
    }
    if (k != 0) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}