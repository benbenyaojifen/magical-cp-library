#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int m; cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(m + 1, {inf, inf}));
    auto calc = [&] (int cur, int p) {
        return ((cur + 1 & 1) == p ? cur + 1 : cur + 2);
    };
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0) {
                dp[i][j][0] = min(calc(dp[i - 1][j][0], v[i - 1]), calc(dp[i - 1][j][1], v[i - 1]));
            }
            if (j > 0) {
                dp[i][j][1] = min(calc(dp[i][j - 1][0], a[j - 1]), calc(dp[i][j - 1][1], a[j - 1]));
            }
        }
    }
    cout << min(dp[n][m][0], dp[n][m][1]) << '\n';
    return 0;
}