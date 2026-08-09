#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    int ans = 2;
    for (int i = 1; i < n; i++) {
        ans *= 2;
    }
    ans -= 2 * n;
    cout << ans << '\n';
    return 0;
}