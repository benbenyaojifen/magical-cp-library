#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int d, c, r; cin >> d >> c >> r;
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 0; i <= b.size(); i++) {
        dp[0][i] = i * c;
    }
    for (int i = 0; i <= a.size(); i++) {
        dp[i][0] = i * d;
    }
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] != b[j - 1]) dp[i][j] = min({dp[i - 1][j] + d, dp[i][j - 1] + c, dp[i - 1][j - 1] + r});
            else dp[i][j] = min({dp[i - 1][j] + d, dp[i][j - 1] + c, dp[i - 1][j - 1]});
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
    return 0;
}