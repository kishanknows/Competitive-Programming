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
    int a, b, c;
    cin >> a >> b >> c;
    int x = c - c/2 + a;
    int y = c/2 + b;
    cout << (x > y ? "First" : "Second") << endl;
}