#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
const int mod = 1e6;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            if (i == j) continue;
            adj[i + 1].emplace_back(c, j + 1);
        }
    }
    int m; cin >> m;
    unordered_set<int> c;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        c.insert(k);
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 1, c.count(1) ? 1 : 0});
    vector<array<int, 2>> dist(n + 1, {inf, inf}), cnt(n + 1, {0, 0});
    dist[1][c.count(1) ? 1 : 0] = 0;
    cnt[1][c.count(1) ? 1 : 0] = 1;
    while(!pq.empty()) {
        auto[w, u, s] = pq.top(); pq.pop();
        if (w > dist[u][s]) continue;
        for (auto[wt, v] : adj[u]) {
            int ns = s || (c.count(v) ? 1 : 0);
            if (dist[v][ns] > w + wt) {
                dist[v][ns] = w + wt;
                cnt[v][ns] = cnt[u][s];
                pq.push({dist[v][ns], v, ns});
            } else if (dist[v][ns] == w + wt) {
                cnt[v][ns] = (cnt[v][ns] + cnt[u][s]) % mod;
            }
        }
    }
    cout << dist[n][1] << " " << cnt[n][1] << '\n';
    return 0;
}