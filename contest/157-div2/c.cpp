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
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
        int len = s[i].length();
        int sum = 0;
        for(int j = 0; j < len; j++){
            sum += s[i][j] - '0';
            v[i].push_back(sum);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int len = v[i].size() + v[j].size();
            if(len%2 == 0){
                if(v[i].size() < v[j].size()){
                    if(2*v[j][len/2 - v[i].size() - 1] == v[i].back() + v[j].back()) res++;
                }
                else if(v[i].size() > v[j].size()){
                    if(2*v[i][len/2 - 1] == v[i].back() + v[j].back()) res++;
                }
                else{
                    if(v[i].back() == v[j].back()) res++;
                }
            }
        }
    }
    cout << res << endl;
}

int32_t main(){
    // int t; 
    // cin >> t;
    // while(t--) 
    solve();
    return 0;
}