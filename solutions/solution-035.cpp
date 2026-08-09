#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n, k, w; cin >> n >> k >> w;
    vector<int> psa(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        psa[i] = psa[i - 1] + x;
    }
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int i = 0; i <= k; i++) dp[i][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][max(0, j - w)] + psa[j] - psa[j - w >= 0 ? j - w : j]);
        }
    }
    cout << dp[k][n] << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}