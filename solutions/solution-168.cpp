#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    auto prime = [&] (int x) {
    if (x == 2) return true;
    if (x < 2 || !(x & 1)) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
};
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        n *= 2;
        for (int i = 3; i <= n / 2; i += 2) {
            int x = n - i;
            if (prime(i) && prime(x)) {
                cout << i << " " << x << '\n';
                break;
            }
        }
    }
    return 0;
}