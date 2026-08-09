#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; ll cur; cin >> n >> cur;
    ll node = (1 << (n + 1)) - 1, m = (1 << n) - 1;
    vector<array<pair<int, int>, 2>> adj(node + 1);
    vector<bool> leaf(node + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w, d; cin >> u >> v >> w >> d;
        leaf[u] = 1; // not leaf
        adj[u][0] = {v, d}; //take
        adj[u][1] = {w, 0}; //skip
    }
    ll ans = -INF;
    auto dfs = [&] (auto &&self, int u, ll best) -> void {
        if (!leaf[u]) { //is leaf
            ans = max(ans, best);
            return;
        }
        self(self, adj[u][0].first, best + adj[u][0].second);
        self(self, adj[u][1].first, best + adj[u][1].second);
    };
    dfs(dfs, 1, cur);
    cout << ans << '\n';
    return 0;
}