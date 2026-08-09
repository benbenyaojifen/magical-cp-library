#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
ll power(ll a, ll b, int mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1LL;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    while (n--) {
        ll a, b, c; cin >> a >> b >> c;
        if (b == 0 && c == 0) {
            cout << a << '\n';
            continue;
        }
        ll p = power(b, c, 1e9 + 6); // by fermats little theorem
        cout << power(a, p, 1e9 + 7) << '\n';
    }
    return 0;
}