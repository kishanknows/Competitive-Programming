#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int num = 2023;
    for(int i = 0; i < n; i++){
        if(num % b[i] != 0){
            cout << "NO" << endl;
            return;
        }
        num /= b[i];
    }
    if(num == 1 || num == 7 || num == 17 || num == 119 || num == 289 || num == 2023){
        cout << "YES" << endl;
        cout << num << " ";
        for(int i = 0; i < k-1; i++){
            cout << 1 << " ";
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}