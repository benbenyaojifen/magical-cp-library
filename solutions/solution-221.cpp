#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<vector<int>> v(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int x; cin >> x;
            v[i - 1].push_back(x);
        }
    }
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].assign(i + 1, 0);
    }
    dp[0][0] = v[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j < i) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + v[i][j]);
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + v[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << '\n';
    return 0;
}