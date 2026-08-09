#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t, n; cin >> t >> n;
    vector<vector<pair<int, int>>> group(t + 1);
    for (int i = 0; i < n; i++) {
        int c, v, tt; cin >> c >> v >> tt;
        group[tt].emplace_back(c, v);
    }
    int b; cin >> b;
    for (int i = 1; i <= t; i++) {
        if (group[i].empty()) {
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<int> old(b + 1, -inf);
    old[0] = 0;
    for (int i = 1; i <= t; i++) {
        vector<int> cur(b + 1, -inf);
        for (auto[c, v] : group[i]) {
            for (int j = c; j <= b; j++) {
                if (old[j - c] == -inf) continue;
                cur[j] = max(cur[j], old[j - c] + v);
            }
        }
        swap(old, cur);
    }
    int ans = *max_element(old.begin(), old.end());
    cout << (ans < 0 ? -1 : ans) << '\n';
    return 0;
}