#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    int res = 0;
    for (int i = 1; i <= x; i++) {
        if (i % 2 == 1)
            res++;
    }
    cout << res << endl;

}