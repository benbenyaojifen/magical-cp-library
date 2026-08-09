#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<ll> a;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        a.push_back(x); a.push_back(y);
        v.emplace_back(x, y);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    auto get_id = [&] (ll x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    };
    vector<bool> vis(a.size() - 1);
    //or use differene array to optimize
    for (int i = 0; i < v.size(); i++) {
        auto[x, y] = v[i];
        x = get_id(x); y = get_id(y);
        //[x, y)
        for (int j = x; j < y; j++) {
            vis[j] = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < vis.size(); i++) {
        if (vis[i]) ans += a[i + 1] - a[i];
    }
    cout << ans << '\n';
    return 0;
}