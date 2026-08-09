#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; string s; cin >> n >> s;
    unordered_set<int> pos;
    auto fib = [&](unordered_set<int> &p) {
        vector<int> dp(n + 1);
        p.insert(1);
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            if (dp[i] > n) break;
            p.insert(dp[i]);
        }
    };
    fib(pos);
    for (int i = 0; i < s.size(); i++) {
        if ((!pos.count(i + 1) && s[i] == 'A') || (pos.count(i + 1) && s[i] != 'A')) {
            cout << "Bruno, GO TO SLEEP" << '\n';
            return 0;
        }
    }
    cout << "That's quite the observation!" << '\n';
    return 0;
}