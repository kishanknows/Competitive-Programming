#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= m;
    }
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i] %= m;
        mp[b[i]]++;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += mp[(m-a[i])%m];
    }
    cout << res << endl;
    
    
}

int32_t main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
