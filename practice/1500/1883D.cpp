#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    multiset<int> stl, str;
    for(int i = 0; i < n; i++){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == '+'){
            stl.insert(a);
            str.insert(b);
        }
        else{
            stl.erase(stl.lower_bound(a));
            str.erase(str.lower_bound(b));
            if(stl.empty() || str.empty()){
                cout << "NO" << endl;
                continue;
            }
        }
        if(*str.begin() < *stl.rbegin()){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    // int t; 
    // cin >> t;
    // while(t--) solve();
    return 0;
}