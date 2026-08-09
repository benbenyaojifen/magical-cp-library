#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> g(n, vector<int>(n)), pre(n, vector<int>(n));
    int ans = 0;
    while (q--) {
        int r, c, v; cin >> r >> c >> v;
        r--; c--;
        int add = v - pre[r][c];
        pre[r][c] = v;
        for (int i = max(0, r - k + 1); i <= min(r, n - k); i++) {
            for (int j = max(0, c - k + 1); j <= min(c, n - k); j++) {
                g[i][j] += add;
                ans = max(ans, g[i][j]);

            }
        }
        cout << ans << '\n';
    }
    return 0;
}