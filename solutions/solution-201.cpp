#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        v.emplace_back(x, y);
    }
    ll cnt = 0;
    sort(v.begin(), v.end());
    auto slope_less = [&](int i, int a, int b) { // slope(i,a) <= slope(i,b)
        i128 lhs = (i128)(v[a].second - v[i].second) * (v[b].first - v[i].first);
        i128 rhs = (i128)(v[b].second - v[i].second) * (v[a].first - v[i].first);
        return lhs <= rhs;
    };
    auto slope_greater = [&](int i, int a, int b) { // slope(i,a) >= slope(i,b)
        i128 lhs = (i128)(v[a].second - v[i].second) * (v[b].first - v[i].first);
        i128 rhs = (i128)(v[b].second - v[i].second) * (v[a].first - v[i].first);
        return lhs >= rhs;
    };
    for (int i = 0; i < n; i++) {
        int mn = -1, mx = -1;
        for (int j = i + 1; j < n; j++) {
            bool flag = 1;
            if (mn != -1) {
                if (!(slope_less(i, j, mn) || slope_greater(i, j, mx))) flag = 0;
            }
            if (flag) cnt++;
            if (mn == -1) {
                mn = mx = j;
            } else {
                if (slope_less(i, j, mn)) mn = j;
                if (slope_greater(i, j, mx)) mx = j;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}