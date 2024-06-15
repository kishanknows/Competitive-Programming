#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int k = 0;
    for(int i = 0; i < n; i++){
        if(k + 1 == a[i]) k = a[i] + 1;
        else k++;
    }
    cout << k << endl;
}

int main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}