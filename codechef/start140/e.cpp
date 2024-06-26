#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    if(n % 2 == 1){
        for(int i = 1; i <= n/2; i++){
            cout << i << " " << n-i << " ";
        }
        cout << n << endl;
    }
    else{
        for(int i = 1; i <= n/2; i++){
            cout << i << " " << n-i+1 << " ";
        }
        cout << endl;
    }
}

int32_t main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
