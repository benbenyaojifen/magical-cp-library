#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; 2 * i < n; i++) {
        ll one = n - 2 * i;
        if (one > 1) {
            ans = max(ans, one * (one - 1) / 2 * i);
        }
    }
    cout << ans << '\n';
    return 0;
}