#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> depth(n + 1, -1), child_cnt(n + 1), cnt_depth(n + 1);
    queue<int> q;
    depth[1] = 0;
    // 1 is root
    q.push(1);
    int mx_depth = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int d = depth[u];
        cnt_depth[d]++;
        mx_depth = max(mx_depth, d);
        for (int v : g[u]) {
            if (depth[v] == -1) {
                depth[v] = d + 1;
                // v is child of u
                child_cnt[u]++;
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= mx_depth; i++) {
        ans = max(ans, cnt_depth[i]);
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, 1 + child_cnt[i]);
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}