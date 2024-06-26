#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; i++){
        if(a[i-1] > i){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    
}

int main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
