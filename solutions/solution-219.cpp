#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L, R; int sum, ans; ll dp[20][2][163];
ll fun(string s, int idx, bool lmt, int ds) {
    if (idx == s.size()) return ds == sum;
    if (dp[idx][lmt][ds] != -1) return dp[idx][lmt][ds];
    int up = lmt ? s[idx] - '0' : 9; ll cnt = 0;
    for (int i = 0; i <= up; i++) 
        cnt += fun(s, idx + 1, lmt & (i + '0' == s[idx]), ds + i);
    return dp[idx][lmt][ds] = cnt;
}
ll solve(ll val) {
    string s = to_string(val); memset(dp, -1, sizeof(dp));
    return fun(s, 0, 1, 0);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> L >> R;
    for (sum = 1; sum <= 9 * 18; sum++) {
        if (solve(R) - solve(L-1) > 0) ans++;
    }
    cout << ans << "\n";
}