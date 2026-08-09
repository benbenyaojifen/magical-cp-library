#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
const int mod = 676767677;
void solve() {
    int x, y; cin >> x >> y;
    int s = abs(x - y);
    if (s == 0) {
        cout << 1 << '\n';
        for (int i = 0; i < x; i++) cout << 1 << " ";
        for (int i = 0; i < y; i++) cout << -1 << " ";
        cout << '\n';
        return;
    }
    ll cnt = 0;
    for (int i = 1; i * i <= s; i++) {
        if (s % i == 0) {
            int j = s / i;
            cnt += (i == j ? 1 : 2);
        }
    }
    cout << cnt % mod << '\n';
    if (x >= y) {
        for (int i = 0; i < x; i++) cout << 1 << " ";
        for (int i = 0; i < y; i++) cout << -1 << " ";
        cout << '\n';
    } else {
        for (int i = 0; i < y; i++) cout << -1 << " ";
        for (int i = 0; i < x; i++) cout << 1 << " ";
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}