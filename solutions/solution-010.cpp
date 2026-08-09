#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    ll n, h, k; cin >> n >> h >> k;
    ll sum = 0;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll cycles = (h - 1) / sum;
    ll r = (h - 1) % sum + 1;
    vector<ll> max_s(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        max_s[i] = max(max_s[i + 1], v[i]);
    }
    ll pref = 0;
    ll min_p = INF;
    ll best_m = n;
    for (int m = 1; m <= n; m++) {
        pref += v[m - 1];
        min_p = min(min_p, v[m - 1]);
        ll max_possible_damage = pref - min_p + max(min_p, max_s[m]);
        if (max_possible_damage >= r) {
            best_m = m;
            break;
        }
    }
    ll ans = cycles * (n + k) + best_m;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}