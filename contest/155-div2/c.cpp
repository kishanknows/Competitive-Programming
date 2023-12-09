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
    string s;
    cin >> s;
    int a = 0, b = 1, cur = 1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == s[i+1]) {
            a++;
            cur  = cur*(cur+1);
        }
        else{
            b = b* cur;
            cur = 1;
        }
    }
    int tmp = a+1;
    while(tmp){
        b = (b*tmp)%998244353;
        tmp--;
    }
    cout << a << " " << b << endl;
}

int main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}