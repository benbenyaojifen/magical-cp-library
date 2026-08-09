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
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx += v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(mx + 1, -inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= mx; j++) {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][abs(j - v[i - 1])] != -inf) {
                dp[i][j] = max(dp[i][j], dp[i - 1][abs(j - v[i - 1])] + v[i - 1]);
            }
            if (j + v[i - 1] <= mx && dp[i - 1][j + v[i - 1]] != inf) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + v[i - 1]] + v[i - 1]);
            }
        }
    }
    int ans = dp[n][0] / 2 + mx - dp[n][0];
    cout << ans << '\n';
    return 0;
}