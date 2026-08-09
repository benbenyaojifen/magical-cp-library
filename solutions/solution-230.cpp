#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[n - 1][i] == '#') dp[n - 1][i] = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            char c = v[i][j];
            if (c == '#') {
                dp[i][j] = 1;
                if (j - 1 >= 0 && j + 1 < n) dp[i][j] = min({dp[i + 1][j], dp[i + 1][j - 1], dp[i + 1][j + 1]}) + 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j]) cnt += dp[i][j];
        }
    }
    cout << cnt << '\n';
    return 0;
}