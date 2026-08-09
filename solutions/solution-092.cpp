#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    int n;
    ll c, k; cin >> n >> c >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll cur = c;
    for (int i = 0; i < n; i++) {
        if (cur >= v[i]) {
            if (k > 0) {
                ll diff = cur - v[i];
                cur += min(k, diff);
                k -= min(k, diff);
                cur += v[i];
            } else {
                cur += v[i];
            }
        } else {
            break;
        }
    }
    cout << cur << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}