#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    auto out = [&](const vector<vector<int>> &dp) {
        string ans = "";
        int i = a.size(), j = b.size();
        while (i != 0 && j != 0) {
            if (dp[i][j] == dp[i - 1][j - 1] + 1 && a[i - 1] == b[j - 1]) {
                i--; j--; ans += a[i];
            } else if (dp[i][j] == dp[i - 1][j]) {
                i--;
            } else {
                j--;
            }
        }
        return ans;
    };
    string s = out(dp);
    reverse(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}