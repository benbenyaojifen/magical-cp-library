#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, k; cin >> n >> k;
    if (n == 1 || n == k) {
        cout << 1 << '\n';
        return 0;
    }
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1] + (j >= i ? dp[i][j -i ] : 0);
        }
    }
    cout << dp[k][n] << '\n';
    return 0;
}