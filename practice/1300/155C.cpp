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
    string s;
    cin >> s;
    int n = s.length(), mod = 998244353;

    //to make the string alternating we just have to find the substring that
    //has '1' or '0' continuously including single '1' or '0'
    //So the min operation should be the total number of substring we find subtracted from length of string
    //because we will keep only one character from each substring
    //Now we know the min operations we just have to find the number of ways we can choose a character
    //from the substring such that it is not removed
    //no of ways of choosing one character from ith substring = len_i so
    //total number of ways = prod(len_1 -> len_k) we have found out number of ways to keep one element
    //but we need the number of ways to remove elements which is (n-k)! so ans is product of these two terms.

    int k = 1, len = 0, res = 1;
    char cur = s[0];
    for(char ch: s){
        if(ch != cur){
            cur = ch;
            res = (res * len)%mod;
            len = 0;
            k++;
        }
        len++;
    }
    res = (res * len)%mod;
    int tmp = n-k;
    while(tmp){
        res = (res * tmp)%mod;
        tmp--;
    }
    cout << n-k << " " << res << endl;

}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}