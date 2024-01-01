#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <numeric>
#include <climits>
#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

void solve(){
    int n, q;
    string s;
    cin >> n;
    vector<int> a(n), xors(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        xors[i+1] = xors[i] ^ a[i];
    }
    cin >> s;
    cin >> q;
    int xor0 = 0, xor1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0')
            xor0 ^= a[i];
        else
            xor1 ^= a[i];
    }
    for(int i = 0; i < q; i++){
        int qt;
        cin >> qt;
        if(qt == 1){
            int l, r;
            cin >> l >> r;
            xor0 ^= (xors[r] ^ xors[l-1]);
            xor1 ^= (xors[r] ^ xors[l-1]);
        }
        else{
            int g;
            cin >> g;
            if(g == 1) cout << xor1 << " ";
            else cout << xor0 << " ";
        }
    }
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}