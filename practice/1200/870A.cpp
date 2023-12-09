#include <vector>
#include <iostream>
#define int long long
using namespace std;

void solve(void);
int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<int> count(n);
    for(int i = 0; i < n; i++) cin >> count[i];
    for(int x = 0; x <= n; x++){
        int liars = 0;
        for(int i = 0; i < n ; i++){
            if(count[i] > x) liars++;
        }
        if(x == liars){
            cout << liars << endl;
            return;
        }
    }
    cout << -1 << endl;
}