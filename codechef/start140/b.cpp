#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    if(2*x >= y){
        cout << n * x << endl;
    }
    else{
        cout << (n/2) * y + (n%2)*x << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
