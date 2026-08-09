#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
const int mod = 1e9 + 7;
ll power(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    while (n--) {
        ll a, b; cin >> a >> b;
        if (a == 0 && b == 0) cout << 1 << '\n';
        else cout << power(a, b) << '\n';
    }
    return 0;
}