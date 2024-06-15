#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n%2 == 1){
        cout << -1 << endl;
        return;
    }
    int diff = 0;
    for(int j = 0; j < n; j++){
        diff += s[j] == '1' ? 1 : -1;
    }
    if(diff != 0){
        cout << -1 << endl;
        return;
    }
    vector<int> ids;
    int i = 0;
    while(i < s.length()){
        if(s[i] == s[s.length()-i-1]){
            if(s[i] == '1') {
                s.insert(i, "01");
                ids.push_back(i);
                i -= 2;
            }
            else{
                s.insert(s.length()-i, "01");
                ids.push_back(s.length()-i-2);
                i -= 1;
            }
        }
        i++;
    }
    if(ids.size() > 300){
        cout << -1 << endl;
        return;
    }
    cout << ids.size() << endl;
    for(int j = 0; j < ids.size(); j++)
        cout << ids[j] << " ";
    cout << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    cout << endl;
    while(t--) solve();
    return 0;
}