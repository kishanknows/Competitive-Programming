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
    string s, t;
    cin >> s >> t;
    int first = 0, second = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != t[i]) first++;
        if(s[i] != t[t.length()-1-i]) second++;
    }
    if(first == 0){
        cout<<0<<endl;
        return;
    }
    if(second == 0){
        cout << 2 << endl;
        return;
    }
    if(first == second){
        cout << 2*first - 1 << endl;
        return;
    }
    if(first < second) {
        cout<<(first%2 ? 2*first - 1: 2*first)<<endl;
        return;
    }
    cout << (second%2 ? 2*second : 2*second - 1) << endl;
    return;
}