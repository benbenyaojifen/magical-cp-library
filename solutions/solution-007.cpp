#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️]
void solve() {
    int n; cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<ll> ans(n + 1);
    if (n == 2) {
        ans[1] = v[2];
        ans[2] = v[1];
        cout << ans[1] << " " << ans[2] << '\n';
        return;
    }
    for (int i = 2; i <= n - 1; i++) {
        ll val = v[i + 1] - 2LL * v[i] + v[i - 1];
        ans[i] = val / 2;
    }
    ll mid1 = 0;
    for (int i = 2; i <= n - 1; i++) {
        mid1 += ans[i] * (i - 1LL);
    }
    ans[n] = (v[1] - mid1) / (n - 1LL);
    ll midn = 0;
    for (int i = 2; i <= n - 1; i++) {
        midn += ans[i] * (n - i * 1LL);
    }
    ans[1] = (v[n] - midn) / (n - 1LL);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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