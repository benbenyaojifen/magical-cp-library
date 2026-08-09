#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1LL << 60;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b, k, t; cin >> a >> b >> k >> t;
    if (t == 1) {
        if (b < a) swap(a, b);
        i128 s = (i128)(b - a) / k;
        ll ans1 = (b - a) % k + s;
        ll ans2 = (i128)(s + 1LL) * (i128)k - (b - a) + s + 1;
        cout << min(ans1, ans2) << '\n';
    } else {
        if (b < a) swap(a, b);
        i128 s = (i128)(b - a) / k;
        ll ans1 = (b - a) % k + s;
        ll ans2 = (i128)(s + 1LL) * (i128)k - (b - a) + s + 1;
        ll ans3 = (s >= 1 ? (i128)(b - a) - (i128)(s - 1LL) * (i128)k + (i128)(s - 1LL) : INF);
        ll best = min({b - a, ans1, ans2, ans3});
        ll ans = best + 2;
        for (ll x : {ans1, ans2, ans3, b - a}) {
            if (x > best) ans = min(ans, x);
        }
        cout << ans << '\n';
    }
    return 0;
}