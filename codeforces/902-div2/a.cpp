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
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int score;
        cin >> score;
        sum += score;
    }
    cout << -sum << endl;
}