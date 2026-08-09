#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<int, int>> v;
    for (int i = 0; i < 3; i++) {
        int x, y; cin >> x >> y;
        v.emplace_back(x, y);
    }
    int ans = inf;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            ans = min(ans, (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
        }
    }
    cout << ans << '\n';
    return 0;
}