#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
const int mod = 1000000007;
const int MM = 100000 + 5;
ll fac[MM], ifac[MM];
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n; cin >> n;
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<pair<int, ll>> v;
    auto cal = [&] (int n, int k) -> ll {
        if (k < 0 || k > n) return 0;
        return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
    };
    for (int i = n; i >= 1; i--) {
        ll cur = b[i];
        for (auto[j, wj] : v) {
            cur = (cur - 1LL * wj * cal(j, i)) % mod;
            if (cur < 0) cur += mod;
        }
        if (cur != 0) {
            v.emplace_back(i, cur);
        }
    }
    vector<int> cnt(29);
    for (auto[j, wj] : v) {
        for (int bit = 0; bit < 29; bit++) {
            if ((wj >> bit) & 1) {
                cnt[bit] = j;
            }
        }
    }
    vector<int> a(n);
    for (int bit = 0; bit < 29; bit++) {
        for (int i = 0; i < cnt[bit]; i++) {
            a[i] |= (1 << bit);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fac[0] = 1;
    for (int i = 1; i < MM; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    ifac[MM - 1] = power(fac[MM - 1], mod - 2);
    for (int i = MM - 2; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}