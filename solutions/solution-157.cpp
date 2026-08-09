#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    auto change = [&] (ll ai, ll bi, ll ci, ll aj, ll bj, ll cj, int &d) {
        ll a = ai - aj, b = bi - bj, c = ci - cj;
        if (a == 0) {
            if (b != 0) return false;
            d = (c < 0 ? -1 : 1);
            return true;
        }
        ll dis = b * b - 4LL * a * c;
        if (dis >= 0) return false;
        d = (a < 0 ? -1 : 1);
        return true;
    };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
           int d = 0;
           if (!change(a[i], b[i], c[i], a[j], b[j], c[j], d)) continue;
           if (d == -1) {
                adj[i].push_back(j);
                indegree[j]++;
           } else {
                adj[j].push_back(i);
                indegree[i]++;
           }
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }
    vector<int> dp1(n, 1), dp2(n, 1);
    for (int u : topo) {
        for (int v : adj[u]) {
           dp2[v] = max(dp2[v], dp2[u] + 1); 
        }
    }
    for (int i = topo.size() - 1; i >= 0; i--) {
        int u = topo[i];
        for (int v : adj[u]) {
            dp1[u] = max(dp1[u], dp1[v] + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dp1[i] + dp2[i] - 1 << " \n"[i == n - 1];
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