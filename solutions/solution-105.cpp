#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = n + 10;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = min(ans, i + n / i);
        }
    }
    cout << ans << '\n';
    return 0;
}