#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    bool adj[7][7] = {};
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i != j && 7 - i != j) adj[i][j] = 1;
        }
    }
    vector<int> dp(7, inf), ndp(7, inf);
    for (int i = 1; i <= 6; i++) {
        dp[i] = (v[1] == i ? 0 : 1);
    }
    for (int i = 2; i <= n; i++) {
        fill(ndp.begin(), ndp.end(), inf);
        for (int j = 1; j <= 6; j++) {
            int best = inf;
            for (int k = 1; k <= 6; k++) {
                if (adj[j][k]) {
                    best = min(best, dp[k]);
                } 
            }
            ndp[j] = best + (v[i] == j ? 0 : 1);
        }
        swap(dp, ndp);
    }
    int ans = inf;
    for (int i = 1; i <= 6; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}