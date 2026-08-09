#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    ll ans = 0;
    const int mod = 998244353;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        ans += x;
        if (ans >= mod) ans -= mod;
    }
    cout << ans << '\n';
    return 0;
}