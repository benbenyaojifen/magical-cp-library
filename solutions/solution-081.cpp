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
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int half = sum / 2;
    vector<bool> dp(half + 1);
    dp[0] = 1;
    for (int x : v) {
        for (int i = half; i >= x; i--) {
            if (dp[i - x]) {
                dp[i] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = dp.size() - 1; i >= 0; i--) {
        if (dp[i]) {
            ans = sum - i * 2LL;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}