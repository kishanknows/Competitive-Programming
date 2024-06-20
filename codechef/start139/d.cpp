#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<int> primes(10 * *6 + 1);

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void solve() {
    int k;
    cin >> k;
    cout << k * primes[k] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    for (int i = 2; i < 10 * *6 + 1; i++) {
        if (isPrime(i)) {
            primes[i] = primes[i - 1] + i;
        }
        else {
            primes[i] = primes[i - 1];
        }
    }
    while (t--) solve();
    return 0;
}