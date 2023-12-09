#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    long long s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++){
        s1 += a[i];
        s2 += b[i];
    }
    long long m1 = *min_element(a.begin(), a.end());
    long long m2 = *min_element(b.begin(), b.end());
    cout << min(m1*n + s2, m2*n + s1) << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}