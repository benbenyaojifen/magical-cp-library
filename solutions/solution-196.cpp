#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, l;
    ll s; cin >> n >> l >> s;
    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll lo = 0, hi = sum + (n - 1) * s;
    auto check = [&] (ll w) {
        int indx = 0;
        for (int i = 0; i < l && indx < v.size(); i++) {
            ll cur = w;
            while (indx < v.size() && cur >= v[indx]) {
                if (cur == w) {
                    cur -= v[indx];
                    indx++;
                } else {
                    if (cur >= v[indx] + s) {
                        cur -= v[indx] + s;
                        indx++;
                    } else {
                        break;
                    }
                }
            }
        }
        return indx == v.size();
    };
    ll ans = INF;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        int res = check(mid);
        if (res) {
            ans = min(ans, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}