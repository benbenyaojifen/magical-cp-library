#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> cnt(n + 1, inf);
    deque<int> dq;
    cnt[1] = 0;
    dq.push_front(1);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, d] : adj[u]) {
            int nd = cnt[u] + d;
           if (nd < cnt[v]) {
                cnt[v] = nd;
                if (d == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
           } 
        }
    }
    if (cnt[n] == inf) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> step(n + 1, inf);
    queue<int> q;
    step[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto[v, d] : adj[u]) {
            if (cnt[u] + d == cnt[v]) {
                if (step[u] + 1 < step[v]) {
                    step[v] = + step[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    cout << cnt[n] << " " << step[n] << '\n';
    return 0;
}